#pragma once
#include <easyx.h>
#include <graphics.h>

enum Color {//ö�ٸ�����ɫ
	background = RGB(30, 30, 30),//������ɫ
	  Ishape = RGB(47, 158, 255),//I��״
	  Jshape = RGB(44, 98, 177),//J��״
	  Lshape = RGB(254, 95, 12),//L��״
	  Oshape = RGB(254, 180, 11),//O��״
	  Sshape = RGB(25, 238, 43),//S��״
	  Tshape = RGB(219, 142, 226),//T��״
	  Zshape = RGB(234, 42, 37),//Z��״
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

POINT pos[500][600];//Ϊ�˷��㣬�ȱ���ÿ���������Ͻǵ�����

POINT view[128][128];//������һ������ĸ������Ͻǵ�����

int arrNum[8] = { 0,1,2,3,4,5,6,7 };//��ɫ��Ӧ������

int arrContrast[8] = { 0,1,2,3,4,5,6,7 };//���������ɫ��

int Map[20][10];//��ͼ��

int Preview[4][4];//��һ������

int NextBlock = 0;//��һ������

int x = 5, y = 1;//��ʼ�����ַ����λ��

int StopNum = 0;//�ø���ͣ�µ�����

int SpinNum = 1;//�ø�����ת������

int left = 0;//����

int right = 0;//����

int FallingTips = 200;//����ĳ�ʼ���ٶ�

int Spin = 0;//��ת���ж�

int RowNum[20] = { 0 };//�������ж�

int CanSpin = 1;

int score = 0;//��ǰ����

int Bestscore = 0;//��߷���

int Epause = 0;//E��ͣ

char Score[10] = "";//��ǰ�������ַ���

char BestScore[10] = "";//��߷������ַ���

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

