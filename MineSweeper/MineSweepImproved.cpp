#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <easyx.h>
#include <stdlib.h>
#include "data.h"
#include "show.h"

int main(void) {
	InitShowUI();
	GamePlay();
	closegraph();
	return 0;
}
void GamePlay() {
	InitGame();
	cleardevice();
	start = time(NULL);
	while (1) {
		end = time(NULL);
		ShowUI();
		Control();
		GameWinJudge();
		if (boom) {
			ShowUI();
			break;//如果炸了就退出循环
		}
		if (win)break;//如果赢了也退出循环
	}
	while (1) {
		ShowUI();
		Control();
	}
	return;
}
void InitGame() {
	Choose();
	boom = false;
	win = false;
	//记录每个格子左上角的坐标
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			pos[i][j].x = (j) * 30 + j * 4 + 7;
			pos[i][j].y = (i + 1) * 30 + i * 4 + 60;
		}
	}
	//随机数播种
	srand((size_t)time(NULL));
	//初始化地图元素
	for (int i = 0; i < hang; i++) 
		for (int j = 0; j < lie; j++) 
			Map[i][j] = 0;	
	for (int i = 0; i < hang; i++) 
		for (int j = 0; j < lie; j++) 
			FlagMap[i][j] = 0;			
	if (choice == 0)initMineNum = 10;
	if (choice == 1)initMineNum = 40;
	for (int i = 0; i < initMineNum; i++) {
		//随机产生10个雷
		int x = rand() % lie;
		int y = rand() % hang;
		while (1) {//如果随机出来的雷与原来的雷位置相同就一直随机，否则退出循环
			//去重环节
			if (Map[y][x] == 1) {
				x = rand() % hang;
				y = rand() % lie;
			}
			else break;
		}
		Map[y][x] = 1;
	}
	//重置雷的数量
	MineNum = initMineNum;
	return;
}
void Choose() {
	if (choice == 0) { hang = 9; lie = 9; }
	if (choice == 1) { hang = 16; lie = 16; }
	return;
}
void Control() {
	key = GetMouseMsg();
	while (1) {
		KEY_X = key.x;
		KEY_Y = key.y;
		if (key.x >= 0 && key.x <= 556 && key.y >= 0 && key.y <= 680) {
			if (key.uMsg == WM_LBUTTONDOWN) {//左键
				if (key.x >= pos[0][0].x && key.x <= pos[hang - 1][lie - 1].x + 30 
				 && key.y >= pos[0][0].y && key.y <= pos[hang - 1][lie - 1].y + 30
				 && boom == false)
					Remove(key.x, key.y);//消除函数,深度递归,遇到雷返回
				if (choice == 0) {
					if (key.x >= 132 && key.x <= 182 && key.y >= 20 && key.y <= 70)
						GamePlay();	//重新开始游戏
				}
				else if (choice == 1) {//130, 20, 425, 70, 6, 6
					if (key.x >= 130 && key.x <= 425 && key.y >= 20 && key.y <= 70)
						GamePlay();	//重新开始游戏
				}
				if (choice == 1) {
					if (key.x >= 15 && key.x <= 200 && key.y >= 643 && key.y <= 672) {
						choice = 0;
						main();//重新进入主函数加载窗口大小
					}
					if (key.x >= 286 && key.x <= 541 && key.y >= 643 && key.y <= 672) {
						exit(0);//直接退出程序，下面同理
					}
				}
				if (choice == 0) {
					if (key.x >= 15 && key.x <= 150 && key.y >= 405 && key.y <= 435) {
						choice = 1;
						main();
					}
					if (key.x >= 167 && key.x <= 303 && key.y >= 405 && key.y <= 435) {
						exit(0);
					}
				}				
			}
			if (key.uMsg == WM_RBUTTONDOWN) {//右键
				if (key.x >= pos[0][0].x && key.x <= pos[hang - 1][lie - 1].x + 30 
				 && key.y >= pos[0][0].y && key.y <= pos[hang - 1][lie - 1].y + 30
				 && boom == false) {
					FlagAndQmark(key.x, key.y);
				}
			}
		}
		else break;
		break;//多break有好处
	}
	return;
}
void FlagAndQmark(int x, int y) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {//判断点击的在第几行第几列   i行   j列 
			if (x >= pos[i][j].x && x <= pos[i][j].x + 30 && y >= pos[i][j].y && y <= pos[i][j].y + 30) {
				if (FlagMap[i][j] == 0 && FlagNumber()) {
					FlagMap[i][j] += 10;
					MineNum--;
				}
				else if (FlagMap[i][j] == 10 || FlagMap[i][j] == 11) {
					FlagMap[i][j]++;
					if (FlagMap[i][j] == 11)MineNum++;
				}
				if (FlagMap[i][j] == 12) FlagMap[i][j] = 0;
			}
		}
	}
	return;
}
int MineNumber(int y, int x) {//简单的防止数组越界的操作返回雷的个数
	if (y == 0 && x == 0)return Map[y][x + 1] + Map[y + 1][x] + Map[y + 1][x + 1];
	if (y == 0) return Map[y][x + 1] + Map[y][x - 1] + Map[y + 1][x - 1] + Map[y + 1][x] + Map[y + 1][x + 1];
	else if (x == 0)return Map[y + 1][x] + Map[y - 1][x] + Map[y - 1][x + 1] + Map[y + 1][x + 1] + Map[y][x + 1];
	else return Map[y][x + 1] + Map[y][x - 1] + Map[y + 1][x] + Map[y - 1][x]
		+ Map[y + 1][x + 1] + Map[y + 1][x - 1] + Map[y - 1][x + 1] + Map[y - 1][x - 1];
}
void Expand(int y, int x) {
	FlagMap[y][x] = 9;//9是打开的状态	
	int minecount = MineNumber(y, x);
	if (minecount == 0) {
		for (int i = y - 1; i <= y + 1; i++) {
			for (int j = x - 1; j <= x + 1; j++) {//在游戏区域内且附近的块可以打开
				if (i >= 0 && i < hang && j >= 0 && j < lie && FlagMap[i][j] == 0) {
					FlagMap[i][j] = 9;//打开
					Expand(i, j);//对可以打开的块的位置继续往下展开
				}
			}
		}
	}
	else //展开到有雷的地方就输入周围8个格子内有几个雷
		FlagMap[y][x] = minecount;
}
void Remove(int x, int y) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {//判断点击的在第几行第几列   i行   j列 
			if (x >= pos[i][j].x && x <= pos[i][j].x + 30 && y >= pos[i][j].y && y <= pos[i][j].y + 30) {
				if (Map[i][j] == 1) {
					boom = true;
					return;//点到雷直接结束游戏
				}
				if (FlagMap[i][j] != 0) return;//点击空白处不能打开方块
				Expand(i, j);//进入自动展开函数
			}
		}
	}
	return;
}
int MineWatch() {
	int count = 0;//返回周围8格子内qizi的个数
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			if (FlagMap[i][j] == 10) count++;
		}
	}
	return count;
}
int GameWinJudge() {//胜利判断
	int all = 0;
	int Boom = 0;
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			if (Map[i][j] == 1 && FlagMap[i][j] == 10) Boom++;
			for (int k = 1; k <= 9; k++) {
				if (FlagMap[i][j] == k)all++;
			}
		}
	}
	if (Boom == 10 || all == (width * height - initMineNum)) win = true;//有十个旗子或者除雷之外的格子都被点开就获胜
	return 0;
}
int FlagNumber() {//监视全局旗子的个数防止竖旗超过10个
	int count = 0;
	for (int i = 0; i < hang; i++)
		for (int j = 0; j < lie; j++)
			if (FlagMap[i][j] == 10) count++;
	if (count == initMineNum)return 0;
	else return 1;
}