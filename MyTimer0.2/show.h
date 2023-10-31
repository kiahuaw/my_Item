#pragma once
#include "data.h"
void MidTimeSHOW_0();
void MidTimeSHOW_1();
void InitShowDataSHOW();
void FormulaShow();
void LogoSHOW();
void FastAndSlowSHOW();
void Ao5AndAo12SHOW();
void TotalSloveAndTimesSHOW();
void SetTextRed() { settextcolor(RGB(255, 0, 0)); ShowUI(); }
void SetTextGreen() { settextcolor(RGB(0, 225, 0)); ShowUI(); }
void NextFormulaButton();
void SavesNumShow();
void DeleteShow();
void SavesTextShow();
void DataShow();
void UpAndDownButton();


void ShowUI() {//下次写显示函数一定分块写，一个一个找参数哥们要疯了
	BeginBatchDraw();//开始批量绘图  并防止绘图闪烁
	cleardevice();
	if (Press) {
		MidTimeSHOW_0();
		InitShowDataSHOW();
		LogoSHOW();
		DataShow();

		FormulaShow();
		UpAndDownButton();
		NextFormulaButton();
		SavesNumShow();
		DeleteShow();
		SavesTextShow();
	}
	else MidTimeSHOW_1();//计时时候的中间显示
	EndBatchDraw();//结束批量绘图
	return;
}


void MidTimeSHOW_1() {
	//华文琥珀//OCR A Extended
	settextstyle(250, 110, "MS UI Gothic");
	char MidTime[10] = "";
	sprintf(MidTime, "%.f", TimeShow);
	int tempx = 1000 / 2 - textwidth(MidTime) / 2;//用格子的一半减去字符串宽度的一半
	int tempy = 650 / 2 - textheight(MidTime) / 2;
	outtextxy(tempx, tempy, MidTime);
}
void MidTimeSHOW_0() {
	settextstyle(250, 110, "MS UI Gothic");
	char MidTime[10] = "";
	sprintf(MidTime, "%.2f", TimeShow);
	if (TimeShow > 10.00) outtextxy(80, 200, MidTime);
	else outtextxy(143, 200, MidTime);
}
void InitShowDataSHOW() {
	//初始化绘制图形参数
	settextcolor(RGB(153, 170, 170));
	setfillcolor(RGB(0, 51, 68));//设置填充颜色
}
void LogoSHOW() {
	//mytimer  的logo
	solidroundrect(780, 50, 950, 130, 70, 70);
	settextstyle(45, 0, "Microsoft YaHei UI");
	outtextxy(790, 67, "MyTimer");
	settextstyle(30, 0, "Microsoft YaHei UI");
}

void SavesNumShow() {
	setfillcolor(RGB(0, 60, 80));//设置填充颜色
	solidroundrect(730, 200, 980, 1000, 60, 60);
	setfillcolor(RGB(0, 51, 68));//设置填充颜色
	settextstyle(30, 0, "Microsoft YaHei UI");
	char NumShow[5] = "";
	char FormulaNumShow[5] = "";
	int n = SaveNumbers() - SaveFlag;
	int m = SaveNumbers();
	//成绩方格的显示
	//solidroundrect(30, 50, 570, 130, 70, 70);
	int tempx;
	for (int i = n, j = 0, k = m; i < n + 15; i++, j++, k++) {//i是成绩个数  j是格子的坐标 
		if (key.x >= SaveBlocks[0][j].x && key.x <= SaveBlocks[0][j].x + 70 && key.y >= SaveBlocks[0][j].y && key.y <= SaveBlocks[0][j].y + 26) {
			solidroundrect(SaveBlocks[0][j].x + 2, SaveBlocks[0][j].y + 2, SaveBlocks[0][j].x + 70 - 2, SaveBlocks[0][j].y + 26 - 2, 10, 10);
			if ((n <= 15 && S[j].Times != 0) || (n > 15 && S[S[i].Number - 15].Times != 0)) {
				setfillcolor(RGB(0, 60, 80));
				int Keyx = key.x - 580, Keyy = key.y - 120;
				solidroundrect(Keyx, Keyy, key.x, key.y, 60, 60);
				settextstyle(40, 0, "Microsoft YaHei UI");
				if (n <= 15) {
					S[j].StringToChar();
					tempx = 290 - textwidth(S[j].ff1) / 2;
					outtextxy(Keyx + tempx, Keyy + 20, S[j].ff1);
					tempx = 290 - textwidth(S[j].ff2) / 2;
					outtextxy(Keyx + tempx, Keyy + 60, S[j].ff2);
				}
				else {
					S[S[i].Number - 15].StringToChar();
					tempx = 290 - textwidth(S[S[i].Number - 15].ff1) / 2;
					outtextxy(Keyx + tempx, Keyy + 20, S[S[i].Number - 15].ff1);
					tempx = 290 - textwidth(S[S[i].Number - 15].ff2) / 2;
					outtextxy(Keyx + tempx, Keyy + 60, S[S[i].Number - 15].ff2);
				}
				settextstyle(30, 0, "Microsoft YaHei UI");
				setfillcolor(RGB(0, 51, 68));
			}
		}
		else {
			solidroundrect(SaveBlocks[0][j].x, SaveBlocks[0][j].y, SaveBlocks[0][j].x + 70, SaveBlocks[0][j].y + 26, 10, 10);

			if (n <= 15) {
				if (j < n) {
					sprintf(NumShow, "%d", S[j].Number + 1);//如果当前成绩个数恰好大于循环j的个数则打印成绩，否则不打印 
					Pos[j] = S[j].Number + 1;
				}
				else sprintf(NumShow, " ");
				tempx = 35 - textwidth(NumShow) / 2;
				outtextxy(SaveBlocks[0][j].x + tempx, SaveBlocks[0][j].y - 1, NumShow);
			}
			else {
				sprintf(NumShow, "%d", S[i].Number + 1 - 15);
				Pos[j] = S[i].Number + 1 - 15;
				tempx = 35 - textwidth(NumShow) / 2;
				outtextxy(SaveBlocks[0][j].x + tempx, SaveBlocks[0][j].y - 1, NumShow);
			}
		}
	}
	return;
}
void SavesTextShow() {
	char NumShow[5] = "";
	int tempx;
	int n = SaveNumbers() - SaveFlag; //20 + 
	for (int i = n, j = 0; j < 15; i++, j++) {
		if (key.x >= SaveBlocks[1][j].x && key.x <= SaveBlocks[1][j].x + 100 && key.y >= SaveBlocks[1][j].y && key.y <= SaveBlocks[1][j].y + 26) {
			solidroundrect(SaveBlocks[1][j].x + 2, SaveBlocks[1][j].y + 2, SaveBlocks[1][j].x + 100 - 2, SaveBlocks[1][j].y + 26 - 2, 10, 10);
			//成绩的显示
			settextcolor(RGB(93, 185, 245));
			settextstyle(27, 0, "Microsoft YaHei UI");
			for (int i = 0; i < 5; i++)NumShow[i] = 0;

			if (S[j].Times > 0.01 && S[j].Times < 1000) {
				if (n <= 15) {
					if (j < n) sprintf(NumShow, "%.2f", S[j].Times);
					else sprintf(NumShow, " ");
				}
				else sprintf(NumShow, "%.2f", S[S[i].Number - 15].Times);

				tempx = 50 - textwidth(NumShow) / 2;
				outtextxy(SaveBlocks[1][j].x + tempx, SaveBlocks[1][j].y, NumShow);
			}
			else {
				sprintf(NumShow, " ");
				tempx = 50 - textwidth(NumShow) / 2;
				outtextxy(SaveBlocks[1][j].x + tempx, SaveBlocks[1][j].y, NumShow);
			}

			tempx = 50 - textwidth(NumShow) / 2;
			outtextxy(SaveBlocks[1][j].x + tempx, SaveBlocks[1][j].y + 1, NumShow);
			settextcolor(RGB(153, 170, 170));
			settextstyle(30, 0, "Microsoft YaHei UI");
		}
		else {
			solidroundrect(SaveBlocks[1][j].x, SaveBlocks[1][j].y, SaveBlocks[1][j].x + 100, SaveBlocks[1][j].y + 26, 10, 10);
			for (int i = 0; i < 5; i++)NumShow[i] = 0;

			if (S[j].Times > 0.01 && S[j].Times < 1000) {
				if (n <= 15) {
					if (j < n) sprintf(NumShow, "%.2f", S[j].Times);
					else sprintf(NumShow, " ");
				}
				else {
					sprintf(NumShow, "%.2f", S[S[i].Number - 15].Times);
				}
				tempx = 50 - textwidth(NumShow) / 2;
				outtextxy(SaveBlocks[1][j].x + tempx, SaveBlocks[1][j].y - 1, NumShow);
			}
			else {
				sprintf(NumShow, " ");
				tempx = 50 - textwidth(NumShow) / 2;
				outtextxy(SaveBlocks[1][j].x + tempx, SaveBlocks[1][j].y - 1, NumShow);
			}
		}
	}

}
void DeleteShow() {//×的显示
	char NumShow[5] = "×";
	int tempx;
	tempx = 15 - textwidth(NumShow) / 2;
	for (int j = 0; j < 15; j++) {
		if (key.x >= SaveBlocks[2][j].x && key.x <= SaveBlocks[2][j].x + 30 && key.y >= SaveBlocks[2][j].y && key.y <= SaveBlocks[2][j].y + 26) {
			solidroundrect(SaveBlocks[2][j].x + 2, SaveBlocks[2][j].y + 2, SaveBlocks[2][j].x + 30 - 2, SaveBlocks[2][j].y + 26 - 2, 10, 10);
			if (Pos[j] != 0) {
				settextcolor(RGB(249, 43, 85));
				settextstyle(27, 0, "Microsoft YaHei UI");
				outtextxy(SaveBlocks[2][j].x + tempx + 1, SaveBlocks[2][j].y, NumShow);
				settextcolor(RGB(153, 170, 170));
				settextstyle(30, 0, "Microsoft YaHei UI");
			}
		}
		else {
			solidroundrect(SaveBlocks[2][j].x, SaveBlocks[2][j].y, SaveBlocks[2][j].x + 30, SaveBlocks[2][j].y + 26, 10, 10);
			if (Pos[j] != 0)outtextxy(SaveBlocks[2][j].x + tempx, SaveBlocks[2][j].y - 3, NumShow);
		}
	}
}
void UpAndDownButton() {
	if (key.x >= 690 && key.x <= 720 && key.y >= 300 && key.y <= 440) {
		solidroundrect(692, 303, 718, 437, 27, 27);//上
		settextstyle(60, 0, "Microsoft YaHei UI");
		settextcolor(RGB(137, 226, 137));
		outtextxy(694, 340, "↑");
		settextcolor(RGB(153, 170, 170));
	}
	else {
		solidroundrect(690, 300, 720, 440, 27, 27);//上
		settextstyle(65, 0, "Microsoft YaHei UI");
		outtextxy(694, 340, "↑");

	}

	if (key.x >= 690 && key.x <= 720 && key.y >= 460 && key.y <= 600) {
		solidroundrect(692, 463, 718, 597, 27, 27);//下
		settextstyle(60, 0, "Microsoft YaHei UI");
		settextcolor(RGB(137, 226, 137));
		outtextxy(694, 500, "↓");
		settextcolor(RGB(153, 170, 170));
	}
	else {
		solidroundrect(690, 460, 720, 600, 27, 27);//下
		settextstyle(65, 0, "Microsoft YaHei UI");
		outtextxy(694, 500, "↓");
	}

}

void FormulaShow() {
	//打乱公式的显示 
	solidroundrect(30 + 70, 50, 570 + 70, 130, 70, 70);
	settextstyle(40, 0, "Microsoft YaHei UI");

	char ff1[50] = "";
	strcpy(ff1, f.f1.c_str());
	int tempx = 600 / 2 - textwidth(ff1) / 2;
	outtextxy(tempx + 70, 50, ff1);

	char ff2[50] = "";
	strcpy(ff2, f.f2.c_str());
	tempx = 600 / 2 - textwidth(ff2) / 2;
	outtextxy(tempx + 70, 85, ff2);
}
void NextFormulaButton() {

	if (key.x >= 650 && key.x <= 770 && key.y >= 50 && key.y <= 130) {
		solidroundrect(652, 52, 768, 128, 70, 70);
		settextstyle(78, 0, "Microsoft YaHei UI");
		settextcolor(RGB(0, 200, 0));
		outtextxy(677, 54, "→");
		settextcolor(RGB(153, 170, 170));
	}
	else {
		solidroundrect(650, 50, 770, 130, 70, 70);
		settextstyle(83, 0, "Microsoft YaHei UI");
		outtextxy(675, 52, "→");
	}
}

void DataShow() {
	setfillcolor(RGB(0, 60, 80));
	solidroundrect(50, 600, 245, 800, 50, 50);
	solidroundrect(270, 600, 465, 800, 50, 50);
	solidroundrect(490, 600, 685, 800, 50, 50);

	setfillcolor(RGB(0, 51, 68));
	FastAndSlowSHOW();
	Ao5AndAo12SHOW();
	TotalSloveAndTimesSHOW();

	setfillcolor(RGB(0, 60, 80));
}
void FastAndSlowSHOW() {
	//显示当前最慢和最快
	char StringFast[10] = "";
	char StringSlow[10] = "";
	if (S[0].Times == 0 || TheFast == 100)
		sprintf(StringFast, "%.2f", 0.00);
	else sprintf(StringFast, "%.2f", TheFast);
	sprintf(StringSlow, "%.2f", TheSlow);

	solidroundrect(70, 618, 135, 648, 10, 10);
	outtextxy(81, 618, "Fast");
	solidroundrect(140, 618, 225, 648, 10, 10);
	int tempx = 40 - textwidth(StringFast) / 2;
	outtextxy(142 + tempx, 618, StringFast);

	solidroundrect(70, 660, 135, 690, 10, 10);
	outtextxy(77, 661, "Slow");
	solidroundrect(140, 660, 225, 690, 10, 10);
	tempx = 40 - textwidth(StringSlow) / 2;
	outtextxy(142 + tempx, 661, StringSlow);
}
void Ao5AndAo12SHOW() {
	//显示的是ao5和ao12
	char String_ao5[10] = "";
	char String_ao12[10] = "";
	sprintf(String_ao5, "%.2f", sum_ao5);
	sprintf(String_ao12, "%.2f", sum_ao12);
	
	solidroundrect(290, 618, 355, 648, 10, 10);
	outtextxy(303, 618, "ao5");
	solidroundrect(360, 618, 440, 648, 10, 10);
	int tempx = 40 - textwidth(String_ao5) / 2;
	outtextxy(358 + tempx, 618, String_ao5);

	solidroundrect(290, 660, 355, 690, 10, 10);
	outtextxy(297, 661, "ao12");
	solidroundrect(360, 660, 440, 690, 10, 10);
	tempx = 40 - textwidth(String_ao12) / 2;
	outtextxy(358 + tempx, 661, String_ao12);
}
void TotalSloveAndTimesSHOW() {
	//总平均和完成次数的显示
	//solidroundrect(490, 600, 685, 800, 50, 50);
	char TotalAVG[10] = "";
	char SolveTimes[10] = "";
	sprintf(TotalAVG, "%.2f", ALLavg);
	sprintf(SolveTimes, "%d", SaveNumbers());

	solidroundrect(510, 618, 575, 648, 10, 10);
	outtextxy(520, 618, "Avg");
	solidroundrect(580, 618, 660, 648, 10, 10);
	int tempx = 40 - textwidth(TotalAVG) / 2;
	outtextxy(580 + tempx, 618, TotalAVG);

	solidroundrect(510, 660, 575, 690, 10, 10);
	outtextxy(516, 661, "Solve");
	solidroundrect(580, 660, 660, 690, 10, 10);
	tempx = 40 - textwidth(SolveTimes) / 2;
	outtextxy(580 + tempx, 661, SolveTimes);


}