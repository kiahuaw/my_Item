#pragma once
#include <graphics.h>
#include <easyx.h>

enum Color {//数字颜色的枚举
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

int Map[18][18];//底层的数据  +2用来防止数组越界 下面同理

int FlagMap[18][18];//显示在上层的

int hang = 9; //行

int lie = 9;//列

int MineNum = 10;//雷的数量

int initMineNum = 10;

int choice = 0;//选择地图大小

int width = 0;

int height = 0;

int KEY_X;//鼠标实时的坐标

int KEY_Y;

int p = 251, q = 217, u = 130;

int red = 251, green = 217, blue = 130;

bool boom = false;//炸不炸就看这个

bool win = false;

clock_t start;//用来计时的

clock_t end;

MOUSEMSG key;//鼠标的key，一种结构体

POINT pos[18][18];//格子左上角的坐标，+2防止数组越界

void InitShowUI();//初始化界面

void ShowUI();//显示函数

void InitGame();//初始化游戏

void Control();//操作函数

void Remove(int x, int y);//获取点击坐标去除格子

void GamePlay();//游戏运行的主函数

void MouseVision();//鼠标可视化

void FlagAndQmark(int x, int y);//旗子和问号

void Choose();

int MineWatch();//雷的监视

int GameWinJudge();//是否获胜

int FlagNumber();//旗子的数量





