#include "data.h"
#include "show.h"

using namespace std;

int main(void) {
	srand((size_t)time(NULL));
	InitShowUI();
	MainProcess();
	return 0;
}
void MainProcess() {
	InitData();
	FormulaCreate();
	DataInit();
	while (!StartTime) {
		ShowUI();
		Control();
		ClickDetect();
		DataCalculate();
	}
	TimeProcess();
	return;
}
void TimeProcess() {
	start = clock();
	while (!StopTime) {
		end_ = clock();
		TimeRecord();
		ShowUI();
		Control();
	}
	TimeSave(TimeShow);
	DataCalculate();
	MainProcess();
	return;
}
void TimeRecord() {//时间显示实时生成保留的函数:对全局变量的操作 
	TimeShow = (float)(end_ - start) / CLOCKS_PER_SEC;
	return;
}
void InitData() {
	SaveFlag = 0;
	StartTime = false;
	StopTime = false;
	Press = true;
	for (int i = 0; i < 15; i++) {
		SaveBlocks[0][i].x = 750;
		SaveBlocks[0][i].y = 200 + (i + 1) * 30;

		SaveBlocks[1][i].x = 750 + 70 + 5;
		SaveBlocks[1][i].y = 200 + (i + 1) * 30;

		SaveBlocks[2][i].x = 825 + 100 + 5;
		SaveBlocks[2][i].y = 200 + (i + 1) * 30;

		Pos[i] = 0;
	}
	return;
}
void InitShowUI() {
	initgraph(1000, 700);
	BeginBatchDraw();
	setbkcolor(RGB(0, 34, 51));
	setbkmode(TRANSPARENT);
	cleardevice();
	EndBatchDraw();//结束批量绘图
	return;
}
void FormulaCreate() {
	f.f1 = "";
	f.f2 = "";
	for (int i = 0; i < 12; i++) {
		int temp = rand() % 3;
		if (i % 3 == 0) {//L R 
			if (temp == 0 || temp == 2)f.f1 = f.f1 + Perm.R[rand() % 3] + " ";
			if (temp == 1)f.f1 = f.f1 + Perm.L[rand() % 3] + " ";
		}
		else if (i % 2 == 0) {//U D
			if (temp == 0 || temp == 2)f.f1 = f.f1 + Perm.U[rand() % 3] + " ";
			if (temp == 1)f.f1 = f.f1 + Perm.D[rand() % 3] + " ";
		}
		else if (i % 1 == 0) {//F B
			if (temp == 0 || temp == 2)f.f1 = f.f1 + Perm.F[rand() % 3] + " ";
			if (temp == 1)f.f1 = f.f1 + Perm.B[rand() % 3] + " ";
		}
	}
	for (int i = 0; i < 12; i++) {
		int temp = rand() % 3;
		if (i % 3 == 0) {//L R 
			if (temp == 0 || temp == 2)f.f2 = f.f2 + Perm.R[rand() % 3] + " ";
			if (temp == 1)f.f2 = f.f2 + Perm.L[rand() % 3] + " ";
		}
		else if (i % 2 == 0) {//U D
			if (temp == 0 || temp == 2)f.f2 = f.f2 + Perm.U[rand() % 3] + " ";
			if (temp == 1)f.f2 = f.f2 + Perm.D[rand() % 3] + " ";
		}
		else if (i % 1 == 0) {//F B
			if (temp == 0 || temp == 2)f.f2 = f.f2 + Perm.F[rand() % 3] + " ";
			if (temp == 1)f.f2 = f.f2 + Perm.B[rand() % 3] + " ";
		}
	}
	int n = SaveNumbers();
	S[n].f.f1 = f.f1;
	S[n].f.f2 = f.f2;
	return;
}
void ClickDetect() {
	int n = SaveNumbers();
	while (1) {
		//点击检测	
		key = getmessage();
		if (key.lbutton == 1) {//鼠标的左键按下650, 50, 770, 130  //GetKeyState(1) <0 为按下
			if (key.x >= 650 && key.x <= 770 && key.y >= 50 && key.y <= 130) {
				//如果点到了下一条的打乱公式
				FormulaCreate();
			}
			for (int i = 0; i < 15; i++) {
				if (key.x >= SaveBlocks[2][i].x && key.x <= SaveBlocks[2][i].x + 30
					&& key.y >= SaveBlocks[2][i].y && key.y <= SaveBlocks[2][i].y + 26) {
					Delete(i);
					TimeSave(0);
					DataCalculate();
					break;

				}
			}
			if (n > 15) {
				if (key.x >= 690 && key.x <= 720 && key.y >= 300 && key.y <= 440) {
					// 上
					if (SaveFlag < n - 15) SaveFlag++;

				}
				if (key.x >= 690 && key.x <= 720 && key.y >= 460 && key.y <= 600) {
					// 下
					if (SaveFlag > 0) SaveFlag--;
				}
			}
		}
		break;
	}
	return;
}
void Control() {//按键检测算法
	//<0为按下  >0为未按下
	int ClickTime = 100;
	if (GetKeyState(32) < 0 && StartTime == 0) {//按下了之后
		spacedown = clock();
		if (GetKeyState(32) < 0) {//如果还在按着就继续，否则退出循环
			while ((spaceup - spacedown) < ClickTime && GetKeyState(32) < 0) {
				spaceup = clock();//计算时间的
				if ((spaceup - spacedown) > 0 && (spaceup - spacedown) < ClickTime)SetTextRed();//设置字体为红色				
			}
			if (GetKeyState(32) < 0) {
				Press = 0;
				TimeShow = 0;
				SetTextGreen();//红色之后是绿色
				while (1) {
					if (GetKeyState(32) > 0) {//按着之后弹起来了才开始计时
						StartTime = 1;
						break;
					}
				}
				settextcolor(RGB(153, 170, 170));
			}
		}
	}
	if (GetKeyState(32) < 0 && StartTime == 1)
		StopTime = 1;
}
int SaveNumbers() {
	int SaveNum = 0;
	for (int i = 0; i < 256; i++) {
		if (S[i].Times == 0) {
			SaveNum = i;//记录成绩个数
			break;
		}
	}
	return SaveNum;
}
void DataInit() {//先
	ifstream infile_saves("Saves.txt");
	ifstream infile_formula("Formula.txt");
	string line;
	for (int i = 0; i < 256; i++) {
		infile_saves >> S[i].Times;
		S[i].Number = i;
	}

	int i = 0;
	while (getline(infile_formula, line)) {
		S[i].f.f1 = line;
		while (getline(infile_formula, line)) {
			S[i].f.f2 = line;
			break;
		}
		i++;
	}
	infile_formula.close();
	infile_saves.close();
	return;
}
void TimeSave(float inputnum) {//后	
	ofstream infile_saves("Saves.txt");
	ofstream infile_formula("Formula.txt");
	S[SaveNumbers()].Times = inputnum;
	for (int i = 0; i < SaveNumbers(); i++) {

		infile_saves << S[i].Times << endl;
		infile_formula << S[i].f.f1 << endl;
		infile_formula << S[i].f.f2 << endl;

	}
	infile_formula.close();
	infile_saves.close();
	return;
}
void DataCalculate() {
	TheFast = 100;
	TheSlow = 0;
	sum_ao5 = 0;
	sum_ao12 = 0;
	bool ao5count = false;
	bool ao12count = false;
	int n = SaveNumbers();
	int ao5_start = n - 5;
	int ao12_start = n - 12;
	for (int i = 0, flag = 0; i < 12; i++) {
		if (S[i].Times > 0.01 && S[i].Times < 100)flag++;
		if (flag >= 5)ao5count = true;//加到5就对头  下面12的同理
		else ao5count = false;
		if (flag >= 12)ao12count = true;
		else ao12count = false;
	}
	if (ao5count) {//如果有5个成绩
		float tempmax = 0;
		float tempmin = 100;//方便比较
		for (int i = ao5_start; i < ao5_start + 5; i++) {
			if (S[i].Times != 0 && S[i].Times > tempmax)tempmax = S[i].Times;//判断5次内最慢成绩
			if (S[i].Times != 0 && S[i].Times < tempmin)tempmin = S[i].Times;//判断5次内最快成绩
			sum_ao5 += S[i].Times;//5次总成绩
		}
		sum_ao5 = (sum_ao5 - tempmax - tempmin) / 3;//去头尾
	}
	if (ao12count) {//同理
		float tempmax = 0;
		float tempmin = 100;
		for (int i = ao12_start; i < ao12_start + 12; i++) {
			if (S[i].Times != 0 && S[i].Times > tempmax)tempmax = S[i].Times;//判断最慢成绩
			if (S[i].Times != 0 && S[i].Times < tempmin)tempmin = S[i].Times;//判断最快成绩
			sum_ao12 += S[i].Times;
		}
		sum_ao12 = (sum_ao12 - tempmax - tempmin) / 10;
	}
	float sum = 0;
	int savenumber = SaveNumbers();
	for (int i = 0; i < savenumber; i++) {
		sum += S[i].Times;
		if (S[i].Times > TheSlow)TheSlow = S[i].Times;
		if (S[i].Times != 0 && S[i].Times < TheFast)TheFast = S[i].Times;
	}
	if (savenumber == 0) ALLavg = 0;
	else ALLavg = sum / savenumber;
}
void Delete(int num) {//num是点击格子的坐标，0-14
	int n = Pos[S[num].Number] - 1;//n是第几个成绩，从0开始,是点击格子的位置
	if (S[num].Number > n)return;//如果点击在空白处就不能删除成绩//仅针对1-15个成绩
	for (int i = n; i < SaveNumbers(); i++) {
		S[i].Number = i;
		S[i].Times = S[i + 1].Times;

		S[i].f.f1 = S[i + 1].f.f1;
		S[i].f.f2 = S[i + 1].f.f2;
		if (i != 0) {
			S[i + 1].f.f1 = "";
			S[i + 1].f.f2 = "";
		}
	}
	for (int i = 0; i < 15; i++)Pos[i] = 0;
}