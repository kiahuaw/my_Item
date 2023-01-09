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

int Map[18][18];//�ײ������  +2������ֹ����Խ�� ����ͬ��

int FlagMap[18][18];//��ʾ���ϲ��

int hang = 9; //��

int lie = 9;//��

int MineNum = 10;//�׵�����

int initMineNum = 10;

int choice = 0;//ѡ���ͼ��С

int width = 0;

int height = 0;

int KEY_X;//���ʵʱ������

int KEY_Y;

int p = 251, q = 217, u = 130;

int red = 251, green = 217, blue = 130;

bool boom = false;//ը��ը�Ϳ����

bool win = false;

clock_t start;//������ʱ��

clock_t end;

MOUSEMSG key;//����key��һ�ֽṹ��

POINT pos[18][18];//�������Ͻǵ����꣬+2��ֹ����Խ��

void InitShowUI();//��ʼ������

void ShowUI();//��ʾ����

void InitGame();//��ʼ����Ϸ

void Control();//��������

void Remove(int x, int y);//��ȡ�������ȥ������

void GamePlay();//��Ϸ���е�������

void MouseVision();//�����ӻ�

void FlagAndQmark(int x, int y);//���Ӻ��ʺ�

void Choose();

int MineWatch();//�׵ļ���

int GameWinJudge();//�Ƿ��ʤ

int FlagNumber();//���ӵ�����





