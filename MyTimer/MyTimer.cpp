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
	DataInit();
	InitData();
	FormulaCreate();
	while (!StartTime) {
		Sleep(1);
		ShowUI();
		Control();
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
//______________________________________________________________________________________________________
void InitData() {
	StartTime = false;
	StopTime = false;
	Press = true;
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
//______________________________________________________________________________________________________
void FormulaCreate() {
	for (int i = 0; i < 24; i++) {
		int temp = rand() % 3;
		if (i % 3 == 0) {//L R 
			if (temp == 0 || temp == 2)formula = formula + Perm.R[rand() % 3] + " ";
			if (temp == 1)formula = formula + Perm.L[rand() % 3] + " ";
		}
		else if (i % 2 == 0) {//U D
			if (temp == 0 || temp == 2)formula = formula + Perm.U[rand() % 3] + " ";
			if (temp == 1)formula = formula + Perm.D[rand() % 3] + " ";
		}
		else if (i % 1 == 0) {//F B
			if (temp == 0 || temp == 2)formula = formula + Perm.F[rand() % 3] + " ";
			if (temp == 1)formula = formula + Perm.B[rand() % 3] + " ";
		}
	}
	return;
}
//______________________________________________________________________________________________________
void Control() {
	//<0为按下  >0为未按下
	if (GetKeyState(32) < 0 && StartTime == 0) {//按下了之后
		spacedown = clock();
		if (GetKeyState(32) < 0 ) {//如果还在按着就继续，否则退出循环
			while ((spaceup - spacedown) < 550 && GetKeyState(32) < 0 ) {
				spaceup = clock();//计算时间的
				if ((spaceup - spacedown) > 0 && (spaceup - spacedown) < 550)SetTextRed();//设置字体为红色
				Sleep(1);
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
					Sleep(1);
				}
				settextcolor(RGB(153, 170, 170));
			}
		}
	}
	if (GetKeyState(32) < 0 && StartTime == 1) 
		StopTime = 1;
	if (GetKeyState(13) < 0) {//回车
		spacedown = clock();
		while (1) {
			spaceup = clock();
			Sleep(1);
			if ((spaceup - spacedown) > 200) {
				FormulaCreate();
				break;
			}
		}
	}
	else if (GetKeyState(8) < 0) {//下一条打乱
		spacedown = clock();
		while (1) {
			spaceup = clock();
			Sleep(1);
			if ((spaceup - spacedown) > 300) {
				deleteif = 1;
				TimeSave(0);
				DataCalculate();
				break;
			}
		}
	}
	else if (GetKeyState(27) < 0) { Sleep(300); exit(0); }//计时器
}
//______________________________________________________________________________________________________
int SaveNumbers() {
	int SaveNum = 0;
	for (int i = 0; i < 256; i++) {
		if (TotalSave[i] == 0) {
			SaveNum = i;//记录成绩个数
			break;
		}
	}
	return SaveNum;
}
//______________________________________________________________________________________________________
void DataInit() {
	FILE* fp1 = fopen("D:/Cpp/Timer_Saves/Saves.txt", "r");
	if (!fp1) { printf("读取失败"); return; }
	memset(TotalSave, 0, sizeof(float) * 256);//清空内存空间
	for (int i = 0; i < 256; i++) fscanf(fp1, "%f\n", &TotalSave[i]);//从文件中读取数据到内存中
	int s = SaveNumbers();
	for (int i = 0; i < 12; i++) Sheet[i] = TotalSave[s - i - 1];//列表的等于所有的最后12个成绩
	fclose(fp1);
	return;
}
void TimeSave(float inputnum) {
	FILE* fp1 = fopen("D:/Cpp/Timer_Saves/Saves.txt", "w");
	if (!fp1) { printf("写入失败"); return; }
	if (deleteif) { Delete(); deleteif = 0; }//如果删除成绩就不输入成绩
	else TotalSave[SaveNumbers()] = inputnum;//(否则就输入成绩)取下一个位置为最后一个成绩并输入
	for (int i = 0; i < 256; i++) {
		if (TotalSave[i] == 0) break;//等于0就不输出到文件夹里面s
		fprintf(fp1, "%.2f\n", TotalSave[i]);
	}
	fclose(fp1);
	return;
}
//______________________________________________________________________________________________________
void DataCalculate() {
	sum_ao5 = 0;
	sum_ao12 = 0;
	bool ao5count = false;
	bool ao12count = false;
	for (int i = 0, flag = 0; i < 12; i++) {
		if (Sheet[i] != 0)flag++;
		if (flag >= 5)ao5count = true;//加到5就对头  下面12的同理
		else ao5count  = false;
		if (flag == 12)ao12count = true;
		else ao12count = false;
	}
	if (ao5count) {//如果有5个成绩
		float tempmax = 0;
		float tempmin = 100;
		for (int i = 0; i < 5; i++) {
			if (Sheet[i] != 0 && Sheet[i] > tempmax)tempmax = Sheet[i];//判断5次内最慢成绩
			if (Sheet[i] != 0 && Sheet[i] < tempmin)tempmin = Sheet[i];//判断5次内最快成绩
			sum_ao5 += Sheet[i];
		}
		sum_ao5 = (sum_ao5 - tempmax - tempmin) / 3;
	}
	if (ao12count) {
		float tempmax = 0;
		float tempmin = 100;
		for (int i = 0; i < 12; i++) {
			if (Sheet[i] > tempmax)tempmax = Sheet[i];//判断最慢成绩
			if (Sheet[i] != 0 && Sheet[i] < tempmin)tempmin = Sheet[i];//判断最快成绩
			sum_ao12 += Sheet[i];
		}
		sum_ao12 = (sum_ao12 - tempmax - tempmin) / 10;
	}
	float sum = 0;
	int savenumber = SaveNumbers();
	for (int i = 0; i < savenumber; i++) {
		sum += TotalSave[i];
		if (TotalSave[i] > TheSlow)TheSlow = TotalSave[i];
		if (TotalSave[i] != 0 && TotalSave[i] < TheFast)TheFast = TotalSave[i];
	}
	ALLavg = sum / savenumber;
}
void Delete() {
	TotalSave[SaveNumbers() - 1] = 0;
	for (int i = 0; i < 12; i++) Sheet[i] = TotalSave[SaveNumbers() - i - 1];
}