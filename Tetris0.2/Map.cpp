#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "data.h"
#include "Block.h"
#include "Map.h"
void Map::Loop() {
	RandomGenerator_Bag1();
	RandomGenerator_Bag2();
	while (1) {
		for (int i = 0; i < 7; i++) {	
			BlockToFalling(bag7_1[i]);
			if (i < 6) NextToShow(bag7_1[i + 1]);
			else NextToShow(bag7_2[0]);
			start = clock();
			while (1) {
				end = clock();//随时计时
				if (end - start >= 1000) {//如果时间>1s就下落一次
					if (StopFallingJudge()) {//如果方块要停止		
						FallingToData();//就输入到data中，
						Remove();//然后remove判断，
						Show();//再展示
						break;
					}
					Falling1Times();//下落
					start = clock();//重新计时	
				}
				else {
					Control();//控制
					DataToShow();//data输入到显示
					Show();//显示
				}
			}
		}
		Bag2ToBag1();
		RandomGenerator_Bag2();
	}
}
Map::Map() {//初始
	initgraph(423, 20 * 30 + 38);//创建一个窗口
	//下面是各种数组的初始化
	for (int i = 0; i < 7; i++) {
		bag7_1[i] = 0;
		bag7_2[i] = 0;
	}
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 10; j++)
			show[i][j] = 0;
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 12; j++)
			mapchar[i][j] = 0;
	for (int i = 0; i < 25; i++)
		data[i] = 0;
	for (int i = 0; i < 24; i++)
		falling[i] = 0;
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 10; j++)
			flag[i][j] = 0;
	for (int i = 0; i < 20; i++) {//整体show的坐标
		for (int j = 0; j < 10; j++) {
			s[i][j].x = j * 30 + j * 2;
			s[i][j].y = i * 30 + i * 2;
		}
	}
	for (int i = 0; i < 4; i++) {//记录下一个方块坐标的位置
		for (int j = 0; j < 3; j++) {
			next[i][j].x = 325 + j * 30 + 2 * (j + 1);
			next[i][j].y = i * 30 + i * 2 + 150;
			nextblock[i][j] = 0;
		}
	}
	srand((size_t)time(NULL));
	start = 0, end = 0, up = 0, down = 0, nextblocknum = 0, nowblocknum = 0;
	Score = 0, Best = 0;
	FILE* filetry = fopen("Save.txt", "r");
	if (filetry != NULL) {
		FILE* fp = fopen("Save.txt", "r");
		fscanf_s(fp, "%d", &Best);
		fclose(fp);
	}
	else {
		FILE* fp = fopen("Save.txt", "w");
		fclose(fp);
	}
}
void Map::Init() {//与构造函数一致，不写注释
	for (int i = 0; i < 7; i++) {
		bag7_1[i] = 0;
		bag7_2[i] = 0;
	}
		
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 10; j++)
			show[i][j] = 0;
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 12; j++)
			mapchar[i][j] = 0;
	for (int i = 0; i < 25; i++)
		data[i] = 0;
	for (int i = 0; i < 24; i++)
		falling[i] = 0;
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 10; j++)
			flag[i][j] = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			s[i][j].x = j * 30 + j * 2;
			s[i][j].y = i * 30 + i * 2;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			next[i][j].x = 325 + j * 30 + 2 * (j + 1);
			next[i][j].y = i * 30 + i * 2 + 150;
			nextblock[i][j] = 0;
		}
	}
	srand((size_t)time(NULL));
	start = 0, end = 0, up = 0, down = 0, nextblocknum = 0, nowblocknum = 0;
	Score = 0;
	FILE* fp = fopen("Save.txt", "r");
	fscanf_s(fp, "%d", &Best);
	fclose(fp);
}
void Map::InitFalling() {
	for (int i = 0; i < 24; i++)falling[i] = 0;//循环重置falling下落方块；
}
void Map::DataToShow() {
	for (int i = 0; i < 24; i++) {
		bitset<10> bit(data[i] | falling[i]);//转换成二进制字符串bit
		strcpy_s(mapchar[i], bit.to_string().c_str());//用字符串拷贝以及bit的方法把bit拷贝到mapchar中
		for (int j = 0; j < 10; j++)
			show[i][j] = mapchar[i][j] - '0';//int = char - ‘0’
	}
	return;
}
void Map::FallingToFlag() {//与上面同理
	for (int i = 0; i < 24; i++) {
		bitset<10> bit(falling[i]);//转换成二进制字符串
		strcpy_s(mapchar[i], bit.to_string().c_str());
		for (int j = 0; j < 10; j++)
			flag[i][j] = mapchar[i][j] - '0';
	}
}
void Map::Falling1Times() {
	b.coord.y++;//参考坐标y下落一格
	data[24] = 1023;//底层为1111111111
	for (int i = 23; i > 0; i--)
		falling[i] = falling[i - 1];//从下面开始循环，实现覆盖
	falling[0] = 0;
}
void Map::LeftMove() {
	int move = 1;//左移，  初始化move为1   如果移动  111
	for (int i = 0; i < 24; i++)//                 100   如果取& = 1 就move=0不能移动
		if ((falling[i] & 512) || ((falling[i] << 1) & data[i]))move = 0; //或者左移一位与datai重叠也不能移动
	if (move) {
		b.coord.x--;//x坐标减少
		for (int i = 0; i < 24; i++)
			falling[i] <<= 1;  //左移1
	}
	return;
}
void Map::RightMove() {// 右移同理
	int move = 1;
	for (int i = 0; i < 24; i++)
		if ((falling[i] & 1) || ((falling[i] >> 1) & data[i]))move = 0;
	if (move) {
		b.coord.x++;
		for (int i = 0; i < 24; i++)
			falling[i] >>= 1;
	}
	return;
}
void Map::DownMove() {
	b.coord.y++;//下落方块参考坐标++
	data[24] = 1023;//同理最后一层为1111111111
	if (!StopFallingJudge()) {//如果没停
		for (int i = 23; i > 0; i--)
			falling[i] = falling[i - 1];
		falling[0] = 0;//下落矩阵就整体下移
	}
}
int Map::StopFallingJudge() {//falling[24]  data[25]
	for (int i = 0; i < 24; i++)//如果有重叠就停
		if (falling[i] & data[i + 1])return 1;
	return 0;
}
void Map::FallingToData() {     //   1001
	for (int i = 0; i < 24; i++)//   0110   => 1111  取|得 两个数组的值 
		data[i] = data[i] | falling[i];
	InitFalling(); // 进行此函数说明以及停止下落了，所以要初始化falling
	return;
}
void Map::Remove() {
	int RemoveRow = 0;
	for (int i = 0; i < 24; i++)
		if (data[i] == 1023)RemoveRow++;
	if (RemoveRow == 1)Score += 10;
	if (RemoveRow == 2)Score += 30;//得分细则
	if (RemoveRow == 3)Score += 70;
	if (RemoveRow == 4)Score += 150;
	for (int k = 0; k < 4; k++) {//最多消4次，所以进行4次
		for (int i = 23; i >= 0; i--) {
			if (data[i] == 1023) {//如果有等于1111111111的就从当前行开始往前覆盖
				for (int j = i; j >= 0; j--)
					data[j] = data[j - 1];
				data[0] = 0;
				break;
			}
		}
	}
	DataToShow();//重新写入数据
	return;
}
int Map::RandBlock() {
	int n = rand() % 7;
	return n;  //简单的随机数返回
}
void Map::NextToShow(int n) {//暴力列举下一个方块，没东西
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			nextblock[i][j] = 0;//初始化
	if (n == 0) {//j
		nextblock[0][1] = 1;
		nextblock[1][1] = 1;
		nextblock[2][1] = 1;
		nextblock[2][0] = 1;
	}
	else if (n == 1) {//l
		nextblock[0][1] = 1;
		nextblock[1][1] = 1;
		nextblock[2][1] = 1;
		nextblock[2][2] = 1;
	}
	else if (n == 2) {//i
		nextblock[0][1] = 1;
		nextblock[1][1] = 1;
		nextblock[2][1] = 1;
		nextblock[3][1] = 1;
	}
	else if (n == 3) {//t
		nextblock[1][1] = 1;
		nextblock[2][0] = 1;
		nextblock[2][1] = 1;
		nextblock[2][2] = 1;
	}
	else if (n == 4) {//o
		nextblock[1][0] = 1;
		nextblock[1][1] = 1;
		nextblock[2][0] = 1;
		nextblock[2][1] = 1;
	}
	else if (n == 5) {//s
		nextblock[1][1] = 1;
		nextblock[1][2] = 1;
		nextblock[2][0] = 1;
		nextblock[2][1] = 1;
	}
	else if (n == 6) {//z
		nextblock[1][0] = 1;
		nextblock[1][1] = 1;
		nextblock[2][1] = 1;
		nextblock[2][2] = 1;
	}
	return;
}
void Map::BlockToFalling(int n) {//以参考坐标建立初始化方块，方便旋转的时候找坐标
	if (n == 0) { //J
		b.coord.y = 2;
		b.block = 'J';
		falling[1] = b.J[0];
		falling[2] = b.J[1];
		falling[3] = b.J[2];
	}
	if (n == 1) { //L
		b.coord.y = 2;
		b.block = 'L';
		falling[1] = b.L[0];
		falling[2] = b.L[1];
		falling[3] = b.L[2];
	}
	if (n == 2) { //I
		b.coord.y = 1;
		b.block = 'I';
		falling[0] = b.I[0];
		falling[1] = b.I[1];
		falling[2] = b.I[2];
		falling[3] = b.I[3];
	}
	if (n == 3) { //T
		b.coord.y = 3;
		b.block = 'T';
		falling[2] = b.T[0];
		falling[3] = b.T[1];
	}
	if (n == 4) { //O
		//O形不需要旋转
		b.block = 'O';
		falling[2] = b.O[0];
		falling[3] = b.O[1];
	}
	if (n == 5) { //S
		b.coord.y = 3;
		b.block = 'S';
		falling[2] = b.S[0];
		falling[3] = b.S[1];
	}
	if (n == 6) { //Z
		b.coord.y = 3;
		b.block = 'Z';
		falling[2] = b.Z[0];
		falling[3] = b.Z[1];
	}
	b.coord.x = 4;
	return;
}
void Map::Spin() {//i j   ->   len - 1 - j,  i    这是旋转的矩阵变换  顺时针好像是
	FallingToFlag();//falling转换到flag方便操作
	if (b.block == 'O') return;  //O型不用旋转
	else if (b.block == 'I') {//如果是I型
		int n = 0;
		for (int i = b.coord.y - 1; i <= b.coord.y + 2; i++)//参考坐标b.coord.y和x 即当前方块的参考点，3*3的中心点坐标
			for (int j = b.coord.x - 1; j <= b.coord.x + 2; j++)
				if (show[i][j] == 1)n++;//对4×4矩阵内的数据进行循环多于4个就不能旋转
		if (n > 4 || b.coord.x < 1 || b.coord.x >= 8)return;//或者在边界也不能旋转
		else {
			int temp[4][4] = { 0 };
			int ni[4][4] = { 0 };//转置矩阵
			for (int i = 0, m = b.coord.y - 1; i < 4; i++, m++)
				for (int j = 0, n = b.coord.x - 1; j < 4; j++, n++)
					temp[i][j] = flag[m][n];//temp3*3暂时存储flag中的数字
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					ni[i][j] = temp[3 - j][i];//对temp进行顺时针转置
			for (int i = 0, m = b.coord.y - 1; i < 4; i++, m++)
				for (int j = 0, n = b.coord.x - 1; j < 4; j++, n++)
					flag[m][n] = ni[i][j];//再把赋值回去
		}
	}
	else {//其他形状的也是同理
		int n = 0;
		for (int i = b.coord.y - 1; i <= b.coord.y + 1; i++)
			for (int j = b.coord.x - 1; j <= b.coord.x + 1; j++)
				if (show[i][j] == 1)n++;
		if (n > 4 || b.coord.x == 0 || b.coord.x > 8)return;
		else {
			int temp[3][3] = { 0 };
			int ni[3][3] = { 0 };
			for (int i = 0, m = b.coord.y - 1; i < 3; i++, m++)
				for (int j = 0, n = b.coord.x - 1; j < 3; j++, n++)
					temp[i][j] = flag[m][n];
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					ni[i][j] = temp[2 - j][i];
			for (int i = 0, m = b.coord.y - 1; i < 3; i++, m++)
				for (int j = 0, n = b.coord.x - 1; j < 3; j++, n++)
					flag[m][n] = ni[i][j];
		}
	}
	FlagToFalling();//把flag二维数组的数据转为一维数组
	return;
}
void Map::FlagToFalling() {
	for (int i = 0; i < 24; i++) {//二进制二维数组转数字，没啥好说
		int n = 0;
		for (int j = 0; j < 10; j++)
			n += flag[i][j] * pow(2, 9 - j);
		falling[i] = n;
	}
	DataToShow();
	return;
}
void Map::Control() {//控制函数
	int downtime = 67;
	int a = 65; // a右移
	int d = 68; // d左移
	int w = 87; // w旋转
	int s = 83; // s下降
	int sp = 32;// 空格
	int re = 82;// r重开
	if (GetKeyState(a) < 0) {//a   如果按下了
		down = clock();//开始计时
		while (GetKeyState(a) < 0) {//进入循环计算抬起时间
			up = clock();//抬起计时
			if ((up - down) > downtime && GetKeyState(a) < 0) {//如果按下的时间超过了预定时间并且还在按着
				up = clock();//计时
				LeftMove();//左移
				break;//退出循环
			}
		}
	}
	if (GetKeyState(d) < 0) {//d  同理
		down = clock();
		while (GetKeyState(d) < 0) {
			up = clock();
			if ((up - down) > downtime && GetKeyState(d) < 0) {
				up = clock();
				RightMove();
				break;
			}
		}
	}
	if (GetKeyState(s) < 0) {//s
		down = clock();
		while (GetKeyState(s) < 0) {
			up = clock();
			if ((up - down) > 70 && GetKeyState(s) < 0) {
				up = clock();
				DownMove();
				DataToShow();
				Show();
				break;
			}
		}
	}
	if (GetKeyState(w) < 0) {//w
		down = clock();
		while (GetKeyState(w) < 0) {
			up = clock();
			if ((up - down) > downtime && GetKeyState(w) < 0) {
				up = clock();
				Spin();
				break;
			}
		}
	}
	if (GetKeyState(re) < 0) {//restart
		down = clock();
		while (GetKeyState(re) < 0) {
			up = clock();
			if ((up - down) > downtime && GetKeyState(re) < 0) {
				up = clock();
				ScoreSave();
				Init();
				Loop();
				break;
			}
		}
	}
	if (GetKeyState(sp) < 0) {//kongge
		down = clock();
		while (GetKeyState(sp) < 0) {
			up = clock();
			if ((up - down) > downtime && GetKeyState(sp) < 0) {
				up = clock();
				while (!StopFallingJudge()) { Falling1Times(); DataToShow(); };
				if (GetKeyState(sp) > 0) break;
			}
		}
	}
}
void Map::ScoreSave(void) {
	FILE* fp = fopen("Save.txt", "r");
	fscanf_s(fp, "%d", &Best);
	if (Score > Best) {
		fclose(fp);
		FILE* op = fopen("Save.txt", "w");
		fprintf(op, "%d", Score);
		fclose(op);
	}
	else fclose(fp);
	return;
}
void Map::RandomGenerator_Bag1() {
	for (int i = 0; i < 7; i++) 
		bag7_1[i] = i;
	Shuffle(bag7_1);
	return;
}
void Map::RandomGenerator_Bag2() {
	for (int i = 0; i < 7; i++)
		bag7_2[i] = i;
	Shuffle(bag7_2);
	return;
}
void Map::Bag2ToBag1() {
	for (int i = 0; i < 7; i++) {
		bag7_1[i] = bag7_2[i];
	}
	return;
}
void Map::Shuffle(int obs[]) {
	for (int i = 0; i < 64; i++) {
		int st1 = rand() % 7;
		int st2 = rand() % 7;
		int temp = obs[st1];
		obs[st1] = obs[st2];
		obs[st2] = temp;
	}
}