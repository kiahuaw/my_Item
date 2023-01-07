#pragma once

#include <graphics.h>//包含图形库头文件
#define MAX_GRID 4  //每行格子数
#define GRID_WIDTH 100 //格子宽度
#define INTERVAL 15	//格子之间的间隔

int score = 0;
int result = 0;
int main();
void GameJudge();
void GameLoseUI();
enum Color {//枚举格子颜色
	zero = RGB(205, 193, 180),//0
	twoTo1 = RGB(238, 228, 218),//2
	twoTo2 = RGB(237, 224, 200),//4
	twoTo3 = RGB(242, 177, 121),//8
	twoTo4 = RGB(245, 149, 99),//16
	twoTo5 = RGB(246, 124, 95),//32
	twoTo6 = RGB(246, 94, 59),//64
	twoTo7 = RGB(242, 177, 121),//128
	twoTo8 = RGB(237, 204, 97),//256
	twoTo9 = RGB(255, 0, 128),//512
	twoTo10 = RGB(145, 0, 72),//1024
	twoTo11 = RGB(242, 17, 158),//2048
	back = RGB(187, 173, 160),//背景颜色   
};
Color arr[13] = { zero, twoTo1, twoTo2, twoTo3, twoTo4,twoTo5,
				  twoTo6, twoTo7, twoTo8, twoTo9, twoTo10, twoTo11, back };

int number[12] = { 0,2,4,8,16,32,64,128,256,512,1024,2048 };

int map[MAX_GRID][MAX_GRID];//初始化格子--全部变量自动初始化为0

POINT pos[MAX_GRID][MAX_GRID];//为了方便，先保存每个格子左上角的坐标

bool flag = false;
