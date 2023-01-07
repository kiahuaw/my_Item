#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <easyx.h>
#include "photograph.h"
#include "data.h"
#include "shape.h"

int main(void) {
	srand((size_t)time(NULL));
	initgraph(300 + 185, 600 + 38);//地图格子大小为10*20// 200用来显示其他东西 
	GamePlay();
	_getch();
	closegraph();
	return 0;
}

void GamePlay() {
	res();
	InitGame();
	InitShowUI();
	score = 0;
	int NowBlock = Rand();
	while (1) {//进入死循环一直循环方块出现
		int NextBlock = Rand();
		NextBlockShow(NextBlock);
		DataRes();
		RowDeleteAndMove();
		while (1) {
			Control();
			if (Epause)PauseJudge();
			MapInput(NowBlock);
			ShowUI();
			Falling();
			Sleep(FallingTips);
			if (StopJudge()) {
				RowDeleteAndMove();
				y = -1;
				break;
			}
			if (y >= 20) {
				y = -1;
				break;
			}
		}
		RowDeleteAndMove();
		NowBlock = NextBlock;
		if (GameEndJudge()) {
			GameEndShow();
			ShowUI();
			break;
		}
	}
	system("pause");
	GamePlay();
}

void GameEndShow() {
	MBJ.FallingShow = 0;
	MBJ.GameOverShow = 1;
	MBJ.LeftMoveShow = 0;
	MBJ.RightMoveShow = 0;
	MBJ.PauseShow = 0;
	MBJ.SpinShow = 0;
	MBJ.ScoreShow = 0;
}
void DataRes() {
	x = 4, y = -1;//初始化方块出现的位置
	SpinNum = 1;
	FallingTips = 200;
}

void InitShowUI() {
	setbkcolor(RGB(30, 30, 30));
	cleardevice();//背景颜色
	setlinecolor(RGB(51, 51, 51));
	for (int i = 0; i < 10; i++)
		line(319 + i, 0, 319 + i, 638);//画分割线
	for (int i = 0; i < 10; i++) {
		line(475 + i, 0, 475 + i, 638);
	}
	Title();
	NextBlockTitle();
	NextBlockShow();
	MessageBox();
	ControlBox();
}

void ShowUI() {
	ScoreShowBox();
	MessageBox();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 8; k++) {
				if (Preview[i][j] == arrContrast[k]) {
					setfillcolor(arr[k]);
					solidrectangle(view[i][j].x, view[i][j].y, view[i][j].x + 30, view[i][j].y + 30);
				}
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 8; k++) {
				if (Map[i][j] == arrContrast[k]) {
					setfillcolor(arr[k]);
					solidrectangle(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30);
				}
			}
		}
	}
	//打印当前得分
	settextstyle(25, 0, "Consolas");
	settextcolor(RGB(85, 170, 255));
	sprintf(Score, "%d", score);
	outtextxy(342, 371, Score);
	//打印最高得分
	if (score > Bestscore)Bestscore = score;
	settextstyle(25, 0, "Consolas");
	settextcolor(RGB(214, 157, 133));
	sprintf(BestScore, "%d", Bestscore);
	outtextxy(409, 371, BestScore);
}

void InitGame() {//游戏开局初始化
	res();
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			pos[i][j].x = j * 30 + j * 2;
			pos[i][j].y = i * 30 + i * 2;//每个格子左上角的坐标
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			view[i][j].x = 337 + j * 32;
			view[i][j].y = 119 + i * 32;//保存一下preview左上角的坐标
		}
	}
}

void res() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			Map[i][j] = 0;
		}
	}
}

void Control() {
	char key = 0;
	while (_kbhit()) {//捕获键盘输入
		key = _getch();
	}
	switch (key) {
	case 'w': case 'W': case  72:  SpinNum++; Spin = 1; if (SpinNum > 4) SpinNum = 1;MBJ.SpinShow = 1; MBJ.FallingShow = 0; break;
	case 's': case 'S': case  80:  FallingTips -= 199;  if (FallingTips < 1)FallingTips = 0; break;
	case 'a': case 'A': case  75:  left = 1; MBJ.LeftMoveShow = 1; MBJ.FallingShow = 0; break;
	case 'd': case 'D': case  77:  right = 1; MBJ.RightMoveShow = 1; MBJ.FallingShow = 0; break;
	case 'r': case 'R': MBJ.GameRestart = 1; MBJ.FallingShow = 0; ShowUI(); Sleep(300);  GamePlay();
	case 'e': case 'E': MBJ.PauseShow = 1; MBJ.FallingShow = 0; ShowUI(); Epause = 1;
	}
	key = 0;
}
int StopJudge() {
	if (StopNum) {//如果全局变量有一个为1则返回0
		StopNum = 0;
		return 1;
	}
	return 0;
}

int Rand() {
	srand((size_t)time(NULL));
	return rand() % 7 + 1;
}
void MapInput(int next) {
	if (next == 1) I_ShapeInput();
	if (next == 2) J_ShapeInput();
	if (next == 3) L_ShapeInput();
	if (next == 4) O_ShapeInput();
	if (next == 5) S_ShapeInput();
	if (next == 6) T_ShapeInput();
	if (next == 7) Z_ShapeInput();
}
void Falling() {
	y++;
	MBJ.FallingShow = 1;
}
void RowDeleteAndMove() {
	int times = 0, row = 0, zeroNum = 0;
	for (int i = 19; i >= 0; i--) {
		times = 0;
		for (int j = 9; j >= 0; j--) {
			if (Map[i][j] != 0) times++;
		}
		if (times == 10) {
			RowNum[i] = 1;
			zeroNum++;
			score++;
			MBJ.FallingShow = 0;
			MBJ.ScoreShow = 1;
			times = 0;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (RowNum[i] == 1) {
			row = i;
			for (int j = 0; j < 10; j++)
				Map[i][j] = 0;
			RowNum[i] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {//列
		int temp = 0;
		int temprow = row;
		for (int j = temprow - zeroNum; j >= 0; j--) {//行
			temp = Map[j][i];
			Map[j][i] = Map[temprow][i];
			Map[temprow][i] = temp;
			temprow--;
		}
	}
}

int GameEndJudge() {
	if (Map[y + 1][x] != 0 && y == -1) {
		MBJ.GameOverShow = 1;
		return 1;
	}
	return 0;
}

void PauseJudge() {
	system("pause");
	Epause = 0;
}



