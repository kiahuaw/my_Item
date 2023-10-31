#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "data.h"
#include "Map.h"
#include "Block.h"
void Map::Show() {
	BeginBatchDraw();//∑¿÷πªÊÕº…¡À∏
	cleardevice();
	setbkcolor(RGB(10, 10, 10));
	setfillcolor(RGB(230, 230, 230));
	setlinecolor(RGB(30, 31, 28));
	for (int i = 2; i < 8; i++)
		line(318 + i, 0, 318 + i, 638);//325  + 3 * 30 + 2 * 4;  423
	for (int i = 0; i < 20; i++) 
		for (int j = 0; j < 10; j++) 
			if (show[i + 4][j] == 1)
				solidrectangle(s[i][j].x, s[i][j].y, s[i][j].x + 30, s[i][j].y + 30);
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 3; j++) 
			if (nextblock[i][j] == 1)
				solidrectangle(next[i][j].x, next[i][j].y, next[i][j].x + 30, next[i][j].y + 30);
	settextstyle(20, 0, "");
	char score[11];
	char best[11];
	sprintf(score, "%d", Score);
	sprintf(best, "%d", Best);
	outtextxy(328, 120, "nextblock");
	outtextxy(340, 470, "score");
	outtextxy(340, 500, score);
	outtextxy(340, 530, "best");
	outtextxy(340, 560, best);
	EndBatchDraw();
	return;
}



