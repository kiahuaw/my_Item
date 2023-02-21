#include "data.h"
int main(void) {
	srand((size_t)time(NULL));
	InitShowUI();//初始化图形界面
	MainProcess();//程序的主函数
	return 0;
}
void MainProcess() {
	InitData();//初始化数据
	FormulaCreate();//创建打乱公式
	while (1) {
		ShowUI();//显示ui
		Control();//键盘监控函数
		DataCalculate();//结果计算
		if (StartTime)TimeProcess();//如果开始则开始计时
	}
	return;
}
void TimeProcess() {//计时的主题函数
	start = clock();//记录开始时刻
	while (1) {
		end = clock();//结束时刻
		if (StopTime)break;//如果结束则退出循环
		TimeRecord();//时间记录
		ShowUI();//显示
		Control();//控制
	}
	TimeSave(TimeShow);//如果循环退出则将timeshow保存
	DataCalculate();//计算ao5和ao12
	MainProcess();//返回主程序
	return;
}
void TimeRecord() {//时间显示实时生成保留的函数:对全局变量的操作 
	TimeShow = (float)(end - start) / CLOCKS_PER_SEC;
	return;
}
void InitData() {//初始化数据
	StartTime = false;
	StopTime = false;
	Press = true;
	return;
}
void FormulaCreate() {
	int last1 = 0, last2 = 0;
	for (int i = 0; i < 24; i++) {//奇数RUF偶数LDB
		if (i % 2 == 0) { // == 0   则用RUF组写入    
			int temp = rand() % 3;
			while (1) {
				if (temp == last1 || temp == last2)temp = rand() % 3;
				else break;
			}
			last1 = temp;//为了防止重复出现的情况，把前两次的数据记录防止接下来的生成重复
			last2 = last1;
			if (temp == 0) for (int j = 0; j < 5; j++)Formula[i][j] = Perm.R[rand() % 3][j];
			if (temp == 1) for (int j = 0; j < 5; j++)Formula[i][j] = Perm.U[rand() % 3][j];
			if (temp == 2) for (int j = 0; j < 5; j++)Formula[i][j] = Perm.F[rand() % 3][j];
		}
		else if (i % 2 != 0) { //  == 1   用LDB组写入
			int temp = rand() % 3;
			while (1) {
				if (temp == last1 || temp == last2)temp = rand() % 3;
				else break;
			}
			last1 = temp;
			last2 = last1;
			if (temp == 0) for (int j = 0; j < 5; j++)Formula[i][j] = Perm.L[rand() % 3][j];
			if (temp == 1) for (int j = 0; j < 5; j++)Formula[i][j] = Perm.D[rand() % 3][j];
			if (temp == 2) for (int j = 0; j < 5; j++)Formula[i][j] = Perm.B[rand() % 3][j];
		}
	}
	return;
}
void InitShowUI() {//初始化图形界面
	initgraph(1000, 700);
	setbkcolor(RGB(0, 34, 51));
	cleardevice();
	return;
}
void Control() {
	char key = NULL;
	while (_kbhit()) {
		key = _getch();
	}
	//<0为按下  >0为未按下
	if (GetKeyState(32) < 0 && StartTime == 0) {//按下了之后
		spacedown = clock();
		if (GetKeyState(32) < 0) {//如果还在按着就继续，否则退出循环
			while ((spaceup - spacedown) < 550 && GetKeyState(32) < 0) {
				spaceup = clock();//计算时间的
				if ((spaceup - spacedown) > 0 && (spaceup - spacedown) < 550)SetTextRed();//设置字体为红色
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
	if (GetKeyState(32) < 0 && StartTime == 1) {
		StopTime = 1;
	}
	if (key == 13) {//回车
		FormulaCreate();
	}
	else if (key == '\b') {
		Delete();//删除成绩
		DataCalculate();
	}
}
void TimeSave(float inputnum) {
	for (int i = 11; i > 0; i--) 
		Sheet[i] = Sheet[i - 1];//把每个成绩往下移一个
	Sheet[0] = inputnum;//输入成绩
	/*文件读写功能，等以后有时间再写
	FILE* fp1 = fopen("D:/Cpp/Timer_Saves/Saves.txt", "r");
	FILE* fp2 = fopen("D:/Cpp/Timer_Saves/Saves.txt", "w");
	if (!fp1 || !fp2) {
		printf("寄");
		return;
	}*/
	return;
}
void Delete() {
	for (int i = 0; i < 11; i++) //删除成绩
		Sheet[i] = Sheet[i + 1];//把每个成绩往上移一格
	Sheet[11] = 0.00;//最后一格的成绩==0
}
void DataCalculate() {
	Slowest = 0;//初始化最快最慢绩否则删除成绩时没有数据比原来的更慢
	Fastest = 100;
	sum_ao5 = 0;
	sum_ao12 = 0;
	for (int i = 0; i < 12; i++) {// 还是得有一部分拿来判断最快和最慢，虽然有点冗余
		if (Sheet[i] != 0 && Sheet[i] > Slowest)Slowest = Sheet[i];//判断最慢成绩
		if (Sheet[i] != 0 && Sheet[i] < Fastest)Fastest = Sheet[i];//判断最快成绩
	}
	float tempmax = 0;
	float tempmin = 100;
	for (int i = 0, flag = 0; i < 5; i++) {//判断是否有5个成绩了
		if (Sheet[i] != 0)flag++;//不等于0就++
		if (flag == 5) ao5count = true;//加到5就对头  下面12的同理
		else ao5count = false;
	}
	for (int i = 0, flag = 0; i < 12; i++) {
		if (Sheet[i] != 0)flag++;
		if (flag == 12)ao12count = true;
		else ao12count = false;
	}
	if (ao5count) {//如果有5个成绩
		for (int i = 0; i < 5; i++) {
			if (Sheet[i] != 0 && Sheet[i] > tempmax)tempmax = Sheet[i];//判断5次内最慢成绩
			if (Sheet[i] != 0 && Sheet[i] < tempmin)tempmin = Sheet[i];//判断5次内最快成绩
			sum_ao5 += Sheet[i];
		}
		sum_ao5 = (sum_ao5 - tempmax - tempmin) / 3;
	}
	if (ao12count) {
		for (int i = 0; i < 12; i++) {
			if (Sheet[i] != 0 && Sheet[i] > Slowest)Slowest = Sheet[i];//判断最慢成绩
			if (Sheet[i] != 0 && Sheet[i] < Fastest)Fastest = Sheet[i];//判断最快成绩
			sum_ao12 += Sheet[i];
		}
		sum_ao12 = (sum_ao12 - Slowest - Fastest) / 10;
	}
}
void ShowUI() {
	BeginBatchDraw();//开始批量绘图  并防止绘图闪烁
	cleardevice();
	
	//中间时间的显示s
	if (Press) {
		settextstyle(200, 0, "OCR A Extended");
		char MidTime[10] = "";
		sprintf(MidTime, "%.2f", TimeShow);
		outtextxy(130, 200, MidTime);
	}
	else if (!Press) {
		settextstyle(200, 0, "OCR A Extended");
		char MidTime[10] = "";
		sprintf(MidTime, "%.2f", TimeShow);
		int tempx = 1000 / 2 - textwidth(MidTime) / 2;//用格子的一半减去字符串宽度的一半
		int tempy = 650 / 2 - textheight(MidTime) / 2;
		outtextxy(tempx, tempy, MidTime);
	}
	if (Press) {
		settextcolor(RGB(153, 170, 170));
		setfillcolor(RGB(0, 51, 68));//设置填充颜色
		solidroundrect(750, 180, 980, 672, 70, 70);//成绩显示的位置
		setlinecolor(RGB(0, 34, 51));//设置线条颜色s
		line(750, 210, 980, 210);//画条分割线
		//画线  
		for (int i = 1; i < 13; i++)
			line(750, 210 + 36 * i, 980, 210 + 36 * i);//-------
		line(810, 210, 810, 641);
		//各个区块的位置
		solidroundrect(30, 50, 730, 130, 70, 70);//打乱显示的位置
		solidroundrect(780, 50, 950, 130, 70, 70);//mytimer  的logo
		solidroundrect(30, 570, 230, 670, 30, 30);//显示当前最慢和最快
		solidroundrect(260, 570, 460, 670, 30, 30);//ao5和ao12
		solidroundrect(490, 570, 690, 618, 50, 50);//删除本次成绩
		solidroundrect(490, 622, 690, 670, 50, 50);//下一条打乱的位置
		//logo
		settextstyle(40, 0, "华文琥珀");
		outtextxy(790, 72, "MyTimer");
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, "华文琥珀");
		//打印数字和标号
		char Saves[12][5] = { 0 };
		char Number[12][4] = { 0 };
		for (int i = 0; i < 12; i++) {
			sprintf(Saves[i], "%.2f", Sheet[i]);
			sprintf(Number[i], "%d", i + 1);
			outtextxy(860, 210 + 36 * i + 4, Saves[i]);
			outtextxy(760, 210 + 36 * i + 4, Number[i]);
		}
		//最快和最慢的显示//要素过多懒得写注释30, 570, 230, 670
		line(30, 620, 230, 620);
		line(30, 621, 230, 621);
		line(100, 570, 100, 670);
		char StringFast[10] = "";
		char StringSlow[10] = "";
		if (Sheet[0] == 0)sprintf(StringFast, "%.2f", 0.00);
		else sprintf(StringFast, "%.2f", Fastest);
		sprintf(StringSlow, "%.2f", Slowest);
		outtextxy(130, 583, StringFast);
		outtextxy(130, 633, StringSlow);
		outtextxy(35, 583, "Fast");
		outtextxy(35, 633, "Slow");
		//ao5和ao12的显示//要素过多也懒得写注释260, 570, 460, 670
		line(260, 620, 460, 620);
		line(260, 621, 460, 621);
		line(330, 570, 330, 670);
		char String_ao5[10] = "";
		char String_ao12[10] = "";
		sprintf(String_ao5, "%.2f", sum_ao5);
		sprintf(String_ao12, "%.2f", sum_ao12);
		outtextxy(360, 583, String_ao5);
		outtextxy(360, 633, String_ao12);
		outtextxy(270, 583, "ao5");
		outtextxy(262, 633, "ao12");
		//写一些提示
		outtextxy(510, 583, "Del_BackSp");
		outtextxy(519, 633, "Next_Enter");
		//打乱公式的显示
		char Total1[80] = "";
		char Total2[50] = "";
		//settextstyle(40, 0, "微软雅黑");
		settextstyle(40, 0, "Microsoft YaHei UI");
		for (int i = 0; i < 15; i++) {
			strcat(Total1, Formula[i]);
			strcat(Total1, " ");
		}
		for (int i = 15; i < 24; i++) {
			strcat(Total2, Formula[i]);
			strcat(Total2, " ");
		}
		outtextxy(100, 50, Total1);
		outtextxy(170, 85, Total2);
	}
	EndBatchDraw();//结束批量绘图
	return;
}
