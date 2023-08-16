#pragma once
#include "data.h"
void MidTimeSHOW_0();
void MidTimeSHOW_1();
void InitShowDataSHOW();
void FormulaSHOW();
void LogoSHOW();
void FastAndSlowSHOW();
void Ao5AndAo12SHOW();
void TotalSloveAndTimesSHOW();
void NumbersAndScoresSHOW();
void LinesUnknowSHOW();
void SetTextRed() { settextcolor(RGB(255, 0, 0)); ShowUI(); }
void SetTextGreen() { settextcolor(RGB(0, 225, 0)); ShowUI(); }

void ShowUI() {//�´�д��ʾ����һ���ֿ�д��һ��һ���Ҳ�������Ҫ����
	BeginBatchDraw();//��ʼ������ͼ  ����ֹ��ͼ��˸
	cleardevice();
	if (Press) {
		MidTimeSHOW_0();
		InitShowDataSHOW();
		LogoSHOW();

		FastAndSlowSHOW();
		Ao5AndAo12SHOW();
		TotalSloveAndTimesSHOW();

		NumbersAndScoresSHOW();

		FormulaSHOW();
		LinesUnknowSHOW();	
	}
	else MidTimeSHOW_1();//��ʱʱ����м���ʾ
	EndBatchDraw();//����������ͼ
	return;
}


void MidTimeSHOW_1() {
	//��������//OCR A Extended
	settextstyle(200, 0, "OCR A Extended");
	char MidTime[10] = "";
	sprintf(MidTime, "%.f", TimeShow);
	int tempx = 1000 / 2 - textwidth(MidTime) / 2;//�ø��ӵ�һ���ȥ�ַ�����ȵ�һ��
	int tempy = 650 / 2 - textheight(MidTime) / 2;
	outtextxy(tempx, tempy, MidTime);
}
void MidTimeSHOW_0() {
	settextstyle(200, 0, "OCR A Extended");
	char MidTime[10] = "";
	sprintf(MidTime, "%.2f", TimeShow);
	outtextxy(130, 200, MidTime);
}
void InitShowDataSHOW() {
	//��ʼ������ͼ�β���
	settextcolor(RGB(153, 170, 170));
	setfillcolor(RGB(0, 51, 68));//���������ɫ
	setlinecolor(RGB(0, 34, 51));//����������ɫs
	solidroundrect(750, 180, 980, 672, 70, 70);//�ɼ���ʾ��λ��
	line(750, 210, 980, 210);//�����ָ���
}
void FormulaSHOW() {
	//���ҹ�ʽ����ʾ 
	solidroundrect(30, 50, 730, 130, 70, 70);
	settextstyle(40, 0, "Microsoft YaHei UI");
	
	char ff1[50] = "";
	char ff2[50] = "";
	
	strcpy(ff1, f.f1.c_str());
	strcpy(ff2, f.f2.c_str());

	outtextxy(170, 50, ff1);
	outtextxy(170, 85, ff2);
}
void LogoSHOW() {
	//mytimer  ��logo
	solidroundrect(780, 50, 950, 130, 70, 70);
	settextstyle(40, 0, "��������");
	outtextxy(790, 72, "MyTimer");
	settextstyle(30, 0, "��������");
}
void FastAndSlowSHOW() {
	//��ʾ��ǰ���������
	char StringFast[10] = "";
	char StringSlow[10] = "";
	if (Sheet[1] == 0 || TheFast == 100)
		sprintf(StringFast, "%.2f", 0.00);
	else sprintf(StringFast, "%.2f", TheFast);
	sprintf(StringSlow, "%.2f", TheSlow);

	solidroundrect(30, 570, 230, 670, 30, 30);
	outtextxy(130, 583, StringFast);
	outtextxy(130, 633, StringSlow);
	outtextxy(35, 583, "Fast");
	outtextxy(35, 633, "Slow");
}
void Ao5AndAo12SHOW() {
	//��ʾ����ao5��ao12
	char String_ao5[10] = "";
	char String_ao12[10] = "";
	sprintf(String_ao5, "%.2f", sum_ao5);
	sprintf(String_ao12, "%.2f", sum_ao12);

	solidroundrect(260, 570, 460, 670, 30, 30);
	outtextxy(360, 583, String_ao5);
	outtextxy(360, 633, String_ao12);
	outtextxy(270, 583, "ao5");
	outtextxy(262, 633, "ao12");
}
void TotalSloveAndTimesSHOW() {
	//��ƽ������ɴ�������ʾ
	char TotalAVG[10] = "";
	char SolveTimes[10] = "";
	//if (ALLavg)
	sprintf(TotalAVG, "%.2f", ALLavg);
	sprintf(SolveTimes, "%d", SaveNumbers());

	solidroundrect(490, 570, 690, 670, 30, 30);
	outtextxy(500, 583, "AVG");
	outtextxy(493, 633, "Solve");
	outtextxy(580, 583, TotalAVG);
	outtextxy(595, 633, SolveTimes);
}
void NumbersAndScoresSHOW() {
	//��ӡ���ֺͱ��
	char Saves[12][5] = { 0 };
	char Number[12][4] = { 0 };
	int n = SaveNumbers();
	for (int i = 0; i < 12; i++) {
		
		if (Sheet[i + 1] <= 0.1 || Sheet[i + 1] >= 1000) 
			sprintf(Saves[i], "%s", "0.00");
		else sprintf(Saves[i], "%.2f", Sheet[i + 1]);

		if (n - i <= 0) sprintf(Number[i], "%s", " ");
		else sprintf(Number[i], "%d", n - i);	
		outtextxy(860, 210 + 36 * i + 4, Saves[i]);
		outtextxy(755, 210 + 36 * i + 4, Number[i]);
	}
}
void LinesUnknowSHOW() {
	for (int i = 1; i < 13; i++)
		line(750, 210 + 36 * i, 980, 210 + 36 * i);
	line(810, 210, 810, 641);
	line(490, 620, 690, 620);
	line(490, 621, 690, 621);
	line(560, 570, 560, 670);
	line(30, 620, 230, 620);
	line(30, 621, 230, 621);
	line(100, 570, 100, 670);
	line(260, 620, 460, 620);
	line(260, 621, 460, 621);
	line(330, 570, 330, 670);
}
