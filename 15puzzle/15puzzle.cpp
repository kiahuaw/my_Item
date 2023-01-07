#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>
#include <easyx.h>
#include <stdio.h>
#include <time.h>
#include "data.h"

int main(void) {
	//初始化窗口
	initgraph(475, 675);
	setbkcolor(RGB(88, 64, 124));
	cleardevice();
	//进入主程序
	GamePlay();
	closegraph();
	return 0;
}

void GamePlay() {
	//计时功能
	InitGame();
	start = time(NULL);
	while (1) {
		end = time(NULL);
		ShowUI();	
		Control();		
		if (GameEndJudge()) {
			ShowUI();
			break;
		} 
	}//跳出循环后进行下一步操作 显示并捕获键盘输入
	while (1) {
		ShowUI();
		Control();
	}
}
void InitUI() {//显示部分界面
	// 标题的绘制   可以不管
	setfillcolor(RGB(73, 52, 111));
	solidroundrect(80, 15, 395, 65, 40, 40);
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "华文琥珀");
	outtextxy(135, 17, "15 Puzzle");
	//newgame
	solidroundrect(15, 80, 115, 125, 40, 40);
	settextstyle(40, 0, "华文琥珀");
	settextcolor(RGB(133, 119, 161));
	outtextxy(29, 85, "New");
	//time&&move
	solidroundrect(130, 80, 460, 125, 20, 20);
	//暂停的位置
	solidroundrect(15, 600, 460, 650, 20, 20);
	settextstyle(40, 0, "华文琥珀");
	outtextxy(190, 605, "Pause");

	settextcolor(RGB(250, 250, 250));
	settextstyle(30, 0, "华文琥珀");
	outtextxy(140, 90, "TIME");

	outtextxy(290, 90, "MOVES");
}
void MouseShow() {
	setlinecolor(RGB(113, 96, 232));
	if (KEY_X >= 15 && KEY_X <= 460 && KEY_Y >= 600 && KEY_Y <= 650) {
		roundrect(15, 600, 460, 650, 20, 20);
		roundrect(16, 601, 459, 649, 20, 20);
	}
	if (KEY_X >= 15 && KEY_X <= 115 && KEY_Y >= 80 && KEY_Y <= 125) {
		roundrect(15, 80, 115, 125, 40, 40);
		roundrect(16, 81, 114, 124, 40, 40);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			
			if (KEY_X >= pos[i][j].x && KEY_X <= pos[i][j].x + 100 && KEY_Y >= pos[i][j].y && KEY_Y <= pos[i][j].y + 100) {
				roundrect(pos[i][j].x + 1, pos[i][j].y + 1, pos[i][j].x + 99, pos[i][j].y + 99, 20, 20);
				roundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 100, pos[i][j].y + 100, 20, 20);
			}
			
		}
	}
}
void ShowUI() {
	BeginBatchDraw();//防止绘图闪烁
	cleardevice();
	InitUI();
	settextstyle(60, 0, "华文琥珀");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (Map[i][j] != 0) {
				setfillcolor(RGB(106, 199, 187));
				solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 100, pos[i][j].y + 100, 20, 20);
			}
			if (Map[i][j] == 0) {
				setfillcolor(RGB(61, 41, 100));
				solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 100, pos[i][j].y + 100, 20, 20);
			}
			char number[5] = "";
			sprintf(number, "%d", Map[i][j]);
			int tempx = 100 / 2 - textwidth(number) / 2;//字体居中显示
			int tempy = 100 / 2 - textheight(number) / 2;
			outtextxy(pos[i][j].x + tempx, pos[i][j].y + tempy + 5, number);
		}
	}
	settextstyle(30, 0, "华文琥珀");
	char UsingTime[5] = "";
	sprintf(UsingTime, "%ds", (int)(end - start));
	outtextxy(220, 90, UsingTime);

	char UsingMove[5] = "";
	sprintf(UsingMove, "%d", move);
	outtextxy(395, 90, UsingMove);
	MouseShow();
	EndBatchDraw();
}
void Control() {
	key = GetMouseMsg();
	while (1) {
		KEY_X = key.x;
		KEY_Y = key.y;
		if (key.x >= 0 && key.x <= 475 && key.y >= 0 && key.y <= 675) {
			if (key.uMsg == WM_LBUTTONDOWN) {
				if (key.x >= pos[0][0].x && key.x <= pos[3][3].x + 115
					&& key.y >= pos[0][0].y && key.y <= pos[3][3].y + 115)
					Move(key.x, key.y);//移动函数
				if (key.x >= 15 && key.x <= 115 && key.y >= 80 && key.y <= 125)
					GamePlay();//重新开始游戏
				if (key.x >= 15 && key.x <= 460 && key.y >= 600 && key.y <= 650)
					system("pause");//暂停功能
			}
		}
		else break;
		
		break;
	}
	return;
}
void Move(int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {//下面的判断条件是判断鼠标点击的是在第几行第几列  i是行   j是列
			if (x >= pos[i][j].x && x <= pos[i][j].x + 100 && y >= pos[i][j].y && y <= pos[i][j].y + 100) {

				if (Map[i][j] != 0) {//如果点击处非零才可以移动
					for (int k = 0; k < 4; k++) {
						if (Map[i][k] == 0) {//如果一行内有一个数字是0 的话就可以移动
							if (k > j) {//0 在点击位置右边
								for (int p = 0, flag = k; p < k - j; p++, flag--) {
									Map[i][flag] = Map[i][flag - 1];//做交换，做k-j次
								}
								Map[i][j] = 0;//将点击位置 置为0
								move++;
							}
							if (k < j) {//0 在点击位置左边
								for (int p = 0, flag = k; p < j - k; p++, flag++) {
									Map[i][flag] = Map[i][flag + 1];//与上面同理
								}
								Map[i][j] = 0;//将点击位置 置为0
								move++;
							}
						}
						if (Map[k][j] == 0) {//如果一列内有一个数字是0 的话就可以移动
							if (k > i) {//0 在点击位置下边
								for (int p = 0, flag = k; p < k - i; p++, flag--) {
									Map[flag][j] = Map[flag - 1][j];
								}
								Map[i][j] = 0;
								move++;
							}
							if (k < i) {//0 在点击位置上边
								for (int p = 0, flag = k; p < i - k; p++, flag++) {
									Map[flag][j] = Map[flag + 1][j];
								}
								Map[i][j] = 0;
								move++;
							}
						}

					}
				}
			}
		}
	}
	return;
}
void InitGame() {
	srand((size_t)time(NULL));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Map[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pos[i][j].x = (j + 1) * 15 + 100 * j;
			pos[i][j].y = (i + 1) * 15 + 100 * i + 120;
		}
	}
	int num = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Map[i][j] = InitArr[num];
			num++;
		}
	}
	for (int i = 0; i < 5000; i++) {//模拟人工打乱操作
		int x = rand() % (pos[3][3].x + 100) + pos[0][0].x;
		int y = rand() % (pos[3][3].y + 100) + pos[0][0].y;
		Move(x, y);
	}
	move = 0;//模拟结束move要置为0;
}
int GameEndJudge() {
	int num = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (Map[i][j] != InitArr[num])return 0;
			num++;
		}
	}
	return 1;
}