#pragma once
#include <graphics.h>
#include <easyx.h>

enum Color {//������ɫ��ö��
	one = RGB(255, 245, 65),
	two = RGB(26, 236, 138),
	three = RGB(103, 243, 242),
	four = RGB(138, 226, 138),
	five = RGB(244, 182, 252),
	six = RGB(255, 228, 160), 
	seven = RGB(0, 1, 247),
	eight = RGB(245, 87, 98)
};

Color ColorArr[8] = { one, two, three, four, five, six, seven, eight };

int Map[9 + 2][9 + 2];//�ײ������  +2������ֹ����Խ�� ����ͬ��

int FlagMap[9][9];//��ʾ���ϲ��

int MineNum = 10;//�׵�����

int KEY_X;//���ʵʱ������

int KEY_Y;

int p = 251, q = 217, u = 130;

bool boom = false;//ը��ը�Ϳ����

bool win = false;

clock_t start;//������ʱ��

clock_t end;

MOUSEMSG key;//����key��һ�ֽṹ��

POINT pos[9 + 2][9 + 2];//�������Ͻǵ����꣬+2��ֹ����Խ��

void InitShowUI();//��ʼ������

void ShowUI();//��ʾ����

void InitGame();//��ʼ����Ϸ

void Control();//��������

void Remove(int x, int y);//��ȡ�������ȥ������

void GamePlay();//��Ϸ���е�������

void MouseVision();//�����ӻ�

void FlagAndQmark(int x, int y);//���Ӻ��ʺ�

int MineWatch();//�׵ļ���

int GameWinJudge();//�Ƿ��ʤ

int FlagNumber();//���ӵ�����





