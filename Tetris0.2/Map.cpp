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
				end = clock();//��ʱ��ʱ
				if (end - start >= 1000) {//���ʱ��>1s������һ��
					if (StopFallingJudge()) {//�������Ҫֹͣ		
						FallingToData();//�����뵽data�У�
						Remove();//Ȼ��remove�жϣ�
						Show();//��չʾ
						break;
					}
					Falling1Times();//����
					start = clock();//���¼�ʱ	
				}
				else {
					Control();//����
					DataToShow();//data���뵽��ʾ
					Show();//��ʾ
				}
			}
		}
		Bag2ToBag1();
		RandomGenerator_Bag2();
	}
}
Map::Map() {//��ʼ
	initgraph(423, 20 * 30 + 38);//����һ������
	//�����Ǹ�������ĳ�ʼ��
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
	for (int i = 0; i < 20; i++) {//����show������
		for (int j = 0; j < 10; j++) {
			s[i][j].x = j * 30 + j * 2;
			s[i][j].y = i * 30 + i * 2;
		}
	}
	for (int i = 0; i < 4; i++) {//��¼��һ�����������λ��
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
void Map::Init() {//�빹�캯��һ�£���дע��
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
	for (int i = 0; i < 24; i++)falling[i] = 0;//ѭ������falling���䷽�飻
}
void Map::DataToShow() {
	for (int i = 0; i < 24; i++) {
		bitset<10> bit(data[i] | falling[i]);//ת���ɶ������ַ���bit
		strcpy_s(mapchar[i], bit.to_string().c_str());//���ַ��������Լ�bit�ķ�����bit������mapchar��
		for (int j = 0; j < 10; j++)
			show[i][j] = mapchar[i][j] - '0';//int = char - ��0��
	}
	return;
}
void Map::FallingToFlag() {//������ͬ��
	for (int i = 0; i < 24; i++) {
		bitset<10> bit(falling[i]);//ת���ɶ������ַ���
		strcpy_s(mapchar[i], bit.to_string().c_str());
		for (int j = 0; j < 10; j++)
			flag[i][j] = mapchar[i][j] - '0';
	}
}
void Map::Falling1Times() {
	b.coord.y++;//�ο�����y����һ��
	data[24] = 1023;//�ײ�Ϊ1111111111
	for (int i = 23; i > 0; i--)
		falling[i] = falling[i - 1];//�����濪ʼѭ����ʵ�ָ���
	falling[0] = 0;
}
void Map::LeftMove() {
	int move = 1;//���ƣ�  ��ʼ��moveΪ1   ����ƶ�  111
	for (int i = 0; i < 24; i++)//                 100   ���ȡ& = 1 ��move=0�����ƶ�
		if ((falling[i] & 512) || ((falling[i] << 1) & data[i]))move = 0; //��������һλ��datai�ص�Ҳ�����ƶ�
	if (move) {
		b.coord.x--;//x�������
		for (int i = 0; i < 24; i++)
			falling[i] <<= 1;  //����1
	}
	return;
}
void Map::RightMove() {// ����ͬ��
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
	b.coord.y++;//���䷽��ο�����++
	data[24] = 1023;//ͬ�����һ��Ϊ1111111111
	if (!StopFallingJudge()) {//���ûͣ
		for (int i = 23; i > 0; i--)
			falling[i] = falling[i - 1];
		falling[0] = 0;//����������������
	}
}
int Map::StopFallingJudge() {//falling[24]  data[25]
	for (int i = 0; i < 24; i++)//������ص���ͣ
		if (falling[i] & data[i + 1])return 1;
	return 0;
}
void Map::FallingToData() {     //   1001
	for (int i = 0; i < 24; i++)//   0110   => 1111  ȡ|�� ���������ֵ 
		data[i] = data[i] | falling[i];
	InitFalling(); // ���д˺���˵���Լ�ֹͣ�����ˣ�����Ҫ��ʼ��falling
	return;
}
void Map::Remove() {
	int RemoveRow = 0;
	for (int i = 0; i < 24; i++)
		if (data[i] == 1023)RemoveRow++;
	if (RemoveRow == 1)Score += 10;
	if (RemoveRow == 2)Score += 30;//�÷�ϸ��
	if (RemoveRow == 3)Score += 70;
	if (RemoveRow == 4)Score += 150;
	for (int k = 0; k < 4; k++) {//�����4�Σ����Խ���4��
		for (int i = 23; i >= 0; i--) {
			if (data[i] == 1023) {//����е���1111111111�ľʹӵ�ǰ�п�ʼ��ǰ����
				for (int j = i; j >= 0; j--)
					data[j] = data[j - 1];
				data[0] = 0;
				break;
			}
		}
	}
	DataToShow();//����д������
	return;
}
int Map::RandBlock() {
	int n = rand() % 7;
	return n;  //�򵥵����������
}
void Map::NextToShow(int n) {//�����о���һ�����飬û����
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			nextblock[i][j] = 0;//��ʼ��
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
void Map::BlockToFalling(int n) {//�Բο����꽨����ʼ�����飬������ת��ʱ��������
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
		//O�β���Ҫ��ת
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
void Map::Spin() {//i j   ->   len - 1 - j,  i    ������ת�ľ���任  ˳ʱ�������
	FallingToFlag();//fallingת����flag�������
	if (b.block == 'O') return;  //O�Ͳ�����ת
	else if (b.block == 'I') {//�����I��
		int n = 0;
		for (int i = b.coord.y - 1; i <= b.coord.y + 2; i++)//�ο�����b.coord.y��x ����ǰ����Ĳο��㣬3*3�����ĵ�����
			for (int j = b.coord.x - 1; j <= b.coord.x + 2; j++)
				if (show[i][j] == 1)n++;//��4��4�����ڵ����ݽ���ѭ������4���Ͳ�����ת
		if (n > 4 || b.coord.x < 1 || b.coord.x >= 8)return;//�����ڱ߽�Ҳ������ת
		else {
			int temp[4][4] = { 0 };
			int ni[4][4] = { 0 };//ת�þ���
			for (int i = 0, m = b.coord.y - 1; i < 4; i++, m++)
				for (int j = 0, n = b.coord.x - 1; j < 4; j++, n++)
					temp[i][j] = flag[m][n];//temp3*3��ʱ�洢flag�е�����
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					ni[i][j] = temp[3 - j][i];//��temp����˳ʱ��ת��
			for (int i = 0, m = b.coord.y - 1; i < 4; i++, m++)
				for (int j = 0, n = b.coord.x - 1; j < 4; j++, n++)
					flag[m][n] = ni[i][j];//�ٰѸ�ֵ��ȥ
		}
	}
	else {//������״��Ҳ��ͬ��
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
	FlagToFalling();//��flag��ά���������תΪһά����
	return;
}
void Map::FlagToFalling() {
	for (int i = 0; i < 24; i++) {//�����ƶ�ά����ת���֣�ûɶ��˵
		int n = 0;
		for (int j = 0; j < 10; j++)
			n += flag[i][j] * pow(2, 9 - j);
		falling[i] = n;
	}
	DataToShow();
	return;
}
void Map::Control() {//���ƺ���
	int downtime = 67;
	int a = 65; // a����
	int d = 68; // d����
	int w = 87; // w��ת
	int s = 83; // s�½�
	int sp = 32;// �ո�
	int re = 82;// r�ؿ�
	if (GetKeyState(a) < 0) {//a   ���������
		down = clock();//��ʼ��ʱ
		while (GetKeyState(a) < 0) {//����ѭ������̧��ʱ��
			up = clock();//̧���ʱ
			if ((up - down) > downtime && GetKeyState(a) < 0) {//������µ�ʱ�䳬����Ԥ��ʱ�䲢�һ��ڰ���
				up = clock();//��ʱ
				LeftMove();//����
				break;//�˳�ѭ��
			}
		}
	}
	if (GetKeyState(d) < 0) {//d  ͬ��
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