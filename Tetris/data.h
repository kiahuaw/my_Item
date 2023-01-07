#pragma once
#include <easyx.h>
#include <graphics.h>

enum Color {//枚举格子颜色
	background = RGB(30, 30, 30),//背景颜色
	  Ishape = RGB(47, 158, 255),//I形状
	  Jshape = RGB(44, 98, 177),//J形状
	  Lshape = RGB(254, 95, 12),//L形状
	  Oshape = RGB(254, 180, 11),//O形状
	  Sshape = RGB(25, 238, 43),//S形状
	  Tshape = RGB(219, 142, 226),//T形状
	  Zshape = RGB(234, 42, 37),//Z形状
};

struct MessageBoxJudge {
	int FallingShow = 0;
	int SpinShow = 0;
	int LeftMoveShow = 0;
	int RightMoveShow = 0;
	int PauseShow = 0;
	int ScoreShow = 0;
	int GameOverShow = 0;
	int GameRestart = 0;
}MBJ;

struct MessageBoxString {
	char Falling[10] = "  Falling";
	char Spin[10] = "   Spin";
	char LeftMove[11] = " Leftmove";
	char RightMove[11] = " Rightmove";
	char Pause[10] = "  Paused";
	char Score[11] = "  Score!";
	char GameOver[10] = " GameOver";
	char BreakBest[10] = "BreakBest";
	char GameRestart[10] = "  ReStart";
}MBS;

Color arr[8] = { background,Ishape,Jshape,Lshape,Oshape,Sshape,Tshape,Zshape };

POINT pos[500][600];//为了方便，先保存每个格子左上角的坐标

POINT view[128][128];//保存下一个方块的格子左上角的坐标

int arrNum[8] = { 0,1,2,3,4,5,6,7 };//颜色对应的数字

int arrContrast[8] = { 0,1,2,3,4,5,6,7 };//用来输出颜色的

int Map[20][10];//地图！

int Preview[4][4];//下一个方块

int NextBlock = 0;//下一个方块

int x = 5, y = 1;//初始化出现方块的位置

int StopNum = 0;//让格子停下的数字

int SpinNum = 1;//让格子旋转的数字

int left = 0;//左移

int right = 0;//右移

int FallingTips = 200;//下落的初始化速度

int Spin = 0;//旋转的判断

int RowNum[20] = { 0 };//行满的判断

int CanSpin = 1;

int score = 0;//当前分数

int Bestscore = 0;//最高分数

int Epause = 0;//E暂停

char Score[10] = "";//当前分数的字符串

char BestScore[10] = "";//最高分数的字符串

void InitGame();

int Rand();

void ShowUI();

void BlockSpinJudge(int next);

void Control();

int StopJudge();

void MapInput(int next);

void Falling();

void RowDeleteAndMove();

void DataRes();

void res();

void InitShowUI();

int GameEndJudge();

void PauseJudge();

void GamePlay();

void NextBlockShow(int next);

void GameEndShow();

int I_ShapeInput();
int J_ShapeInput();
int L_ShapeInput();
int O_ShapeInput();
int S_ShapeInput();
int T_ShapeInput();
int Z_ShapeInput();

