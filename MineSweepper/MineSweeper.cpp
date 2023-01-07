#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <easyx.h>
#include "data.h"
//9*9十个雷版本的扫雷
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
	boom = false;
	win = false;
	//记录每个格子左上角的坐标
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			pos[i][j].x = (j) * 30 + j * 4 + 7;
			pos[i][j].y = (i + 1) * 30 + i * 4 + 60;
		}
	}
	//重置雷的数量
	MineNum = 10;
	//随机数播种
	srand((size_t)time(NULL));
	//初始化地图元素
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 9; j++) {
			Map[i][j] = 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			FlagMap[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		//随机产生10个雷
		int x = rand() % 9;
		int y = rand() % 9;
		while (1) {//如果随机出来的雷与原来的雷位置相同就一直随机，否则退出循环
		//去重环节
			if (Map[y][x] == 1) {
				x = rand() % 9;
				y = rand() % 9;
			}
			else break;		
		}
		Map[y][x] = 1;
	}	
	return;
}
void InitShowUI() {
	initgraph(300 + 18, 400);//创建窗口
	setbkcolor(RGB(161, 97, 26));
	cleardevice();
	return;
}
void Control() {
	key = GetMouseMsg();
	while(1) {
		KEY_X = key.x;
		KEY_Y = key.y;
		if (key.x >= 0 && key.x <= 318 && key.y >= 0 && key.y <= 400) {
			if (key.uMsg == WM_LBUTTONDOWN) {//左键
				if (key.x >= pos[0][0].x && key.x <= pos[8][8].x + 30 && key.y >= pos[0][0].y && key.y <= pos[8][8].y + 30 
					&& boom == false)
					Remove(key.x, key.y);//消除函数,深度递归,遇到雷返回//也可以不递归	
				if (key.x >= 132 && key.x <= 182 && key.y >= 20 && key.y <= 70) 
					GamePlay();	//重新开始游戏
			}
			if (key.uMsg == WM_RBUTTONDOWN) {//右键
				if (key.x >= pos[0][0].x && key.x <= pos[8][8].x + 30 && key.y >= pos[0][0].y && key.y <= pos[8][8].y + 30 
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
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {//判断点击的在第几行第几列   i行   j列 
			if (x >= pos[i][j].x && x <= pos[i][j].x + 30 && y >= pos[i][j].y && y <= pos[i][j].y + 30) {
				if (FlagMap[i][j] == 0 && FlagNumber()) {
					FlagMap[i][j] += 10;
					MineNum--;
				}
				else if (FlagMap[i][j] == 10 || FlagMap[i][j] == 11) {
					FlagMap[i][j]++;
					if(FlagMap[i][j] == 11)MineNum++;
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
				if (i >= 0 && i < 9 && j >= 0 && j < 9 && FlagMap[i][j] == 0) {
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
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {//判断点击的在第几行第几列   i行   j列 
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
void ShowUI() {
	BeginBatchDraw();//防止绘图闪烁
	cleardevice();
	//填充功能区
	setfillcolor(RGB(204, 145, 65));
	solidrectangle(0, 0, 318, 82);
	//重新开始图标绘制
	setfillcolor(RGB(251, 217, 130));
	solidroundrect(132, 20, 182, 70, 6, 6);
	//newgame
	settextcolor(RGB(196, 133, 54));
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, "华文琥珀");
	outtextxy(138, 25, "New");
	settextstyle(20, 0, "华文琥珀");
	outtextxy(134, 45, "game");
	//右上角的雷数
	settextcolor(RGB(245, 87, 98));
	char minearr[5] = " ";
	sprintf(minearr, "%d", MineNum);
	settextstyle(50, 0, "华文琥珀");
	setfillcolor(RGB(161, 97, 26));
	solidroundrect(212, 20, 303, 70, 6, 6);
	int temp = textwidth(minearr);
	outtextxy(212 + (303-212) / 2 - temp / 2, 23, minearr);
	//显示时间s
	char time[5] = " ";
	sprintf(time, "%d", end - start);
	int timetemp = textwidth(time);
	solidroundrect(15, 20, 102, 70, 6, 6);	
	outtextxy(15 + (102 - 15) / 2 - timetemp / 2, 23, time);
	//开始绘制图像
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {//为10是X   11是 ?
			if (FlagMap[i][j] == 0 || FlagMap[i][j] == 10 || FlagMap[i][j] == 11) {//等于0是被遮挡状态				
				setfillcolor(RGB(251, 217, 130));
				solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30, 6, 6);
			}			
			if (FlagMap[i][j] > 0 && FlagMap[i][j] <= 9) {//不等于0就用其他覆盖
				setfillcolor(RGB(196, 133, 54));
				solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30, 6, 6);
			}
			MouseVision();
			if (FlagMap[i][j] > 0 && FlagMap[i][j] < 9) {
				for (int k = 0; k < 8; k++) {
					if(FlagMap[i][j] == k + 1)//设置颜色
						settextcolor(ColorArr[k + 1]);
				}
				char Mines[5] = " ";
				sprintf(Mines, "%d", FlagMap[i][j]);
				settextstyle(30, 0, "华文琥珀");//输出雷的个数
				outtextxy(pos[i][j].x + 6, pos[i][j].y + 2, Mines);
			}
			if (FlagMap[i][j] == 10) {
				settextstyle(35, 0, "华文琥珀");
				settextcolor(RGB(228, 75, 86));//旗子画不出来
				outtextxy(pos[i][j].x - 2, pos[i][j].y - 1 , "×");
			}
			if (FlagMap[i][j] == 11) {
				settextstyle(35, 0, "华文琥珀");
				settextcolor(RGB(228, 75, 86));//问号
				outtextxy(pos[i][j].x + 6, pos[i][j].y, "?");
			}
			if (boom == true && Map[i][j] == 1) {
				setfillcolor(RGB(245, 87, 98));//游戏结束显示雷
				solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30, 6, 6);
			}
			if (win) {//胜利后雷变绿				
				if (Map[i][j] == 1) {
					if (p > 138)p -= 1;
					if (q > 226)q += 1;
					if (u > 138)u += 1;
					setfillcolor(RGB(p, q, u));
					solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30, 6, 6);
					if (p > 138 && q > 226 && u > 138)Sleep(1);					
				}
			}
		}
	}
	EndBatchDraw();
	return;
}
void MouseVision() {//显示鼠标位置：其实就是给鼠标所在的格子加个框框
	if (KEY_X >= 132 && KEY_X <= 182 && KEY_Y >= 20 && KEY_Y <= 70) {
		setlinecolor(RGB(250, 251, 253));
		roundrect(132, 20, 182, 70, 6, 6); roundrect(133, 21, 181, 69, 6, 6);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (KEY_X >= pos[i][j].x && KEY_X <= pos[i][j].x + 30 && KEY_Y >= pos[i][j].y && KEY_Y <= pos[i][j].y + 30) {
				roundrect(pos[i][j].x + 1, pos[i][j].y + 1, pos[i][j].x + 29, pos[i][j].y + 29, 6, 6);
			}
		}
	}
}
int MineWatch() {
	int count = 0;//返回周围8格子内旗子的个数
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (FlagMap[i][j] == 10) count++;
		}
	}
	return count;
}
int GameWinJudge() {//胜利判断
	int all = 0;
	int Boom = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (Map[i][j] == 1 && FlagMap[i][j] == 10) Boom++;			
			for (int k = 1; k <= 9; k++) {
				if (FlagMap[i][j] == k)all++;
			}
		}
	}
	if (Boom == 10 || all == 71) win = true;//有十个旗子或者除雷之外的格子都被点开就获胜
	return 0;
}
int FlagNumber() {//监视全局旗子的个数防止竖旗超过10个
	int count = 0;
	for (int i = 0; i < 9; i++) 
		for (int j = 0; j < 9; j++) 
			if (FlagMap[i][j] == 10) count++;
	if (count == 10)return 0;
	else return 1;
}