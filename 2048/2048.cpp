#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>//包含图形库头文件
#include "2048.h"
#include "2048control.h"
int twoORfour() {//定义函数随机返回2/4
	if (rand() % 10 == 1) return 4;
	else return 2;//1/10的概率产生一个4
}
void CreateNumber() {
	while (1) {
		int x = rand() % MAX_GRID;//在数组的随机位置产生  把数放到数组里面
		int y = rand() % MAX_GRID;
		if (map[x][y] == 0) {
			map[x][y] = twoORfour();
			break;
		}
	}
}
void GameInit() {
	srand((size_t)time(NULL));
	for (int i = 0; i < MAX_GRID; i++) {
		for (int j = 0; j < MAX_GRID; j++) {
			pos[i][j].x = j * GRID_WIDTH + (j + 1) * INTERVAL;
			pos[i][j].y = i * GRID_WIDTH + (i + 1) * INTERVAL;//每个格子左上角的坐标
		}
	}
	CreateNumber();//初始化 游戏开始时先随机生成两个数字
	CreateNumber();
}
void GameDraw() {
	setbkcolor(back);
	cleardevice();//背景颜色
	for (int i = 0; i < MAX_GRID; i++) {
		for (int j = 0; j < MAX_GRID; j++) {
			//判断map的值是多少    跟对应数组进行比较，如果匹配则将对应数字输出
			for (int k = 0; k < 12; k++) {
				if (map[i][j] == number[k]) {
					setfillcolor(arr[k]);//设置对应的颜色
					solidrectangle(pos[i][j].x, pos[i][j].y, pos[i][j].x + GRID_WIDTH, pos[i][j].y + GRID_WIDTH);
					if (map[i][j] != 0) {
						char num[5] = "";
						char scoreChar[5] = "";
						settextcolor(RGB(119, 110, 101));
						settextstyle(55, 0, "Consolas");
						setbkmode(TRANSPARENT);//设置背景模式透明
						sprintf(num, "%d", map[i][j]);//将数字输入到字符串里
						//数字居中显示
						int tempx = GRID_WIDTH / 2 - textwidth(num) / 2;//用格子的一半减去字符串宽度的一半
						int tempy = GRID_WIDTH / 2 - textheight(num) / 2;
						outtextxy(pos[i][j].x + tempx, pos[i][j].y + tempy, num);
						//在下面显示分数
						settextcolor(BLACK);
						settextstyle(15, 0, "Consolas");
						setbkmode(TRANSPARENT);
						sprintf(scoreChar, "|Your score is: %d.|   |You can press R to restart the game|", score);
						outtextxy(30, 460, scoreChar);
					}
				}
			}
		}
	}
}

void GameJudge() {
	if (flag) {
		CreateNumber();
		flag = false;
	}
}
//键盘控制数字移动
void GameContorl() {
	//先获取键盘输入,_getch();
	char key = _getch();
	switch (key) {
		case 'w': case 'W': case  72: moveup();break;
		case 's': case 'S': case  80: movedown();break;
		case 'a': case 'A': case  75: moveleft();break;
		case 'd': case 'D': case  77: moveright();break;
		case 'r': case 'R': GameLoseUI();//重新开始
	}
}
void reset() {
	for (int i = 0; i < MAX_GRID; i++)
		for (int j = 0; j < MAX_GRID; j++)
			map[i][j] = 0;//重新开始的初始化状态
	score = 0;
}
int GameRestartJudge() {
	int restartNum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//如果该元素的上或下或左或右有一个数字与它相等
			if (map[i + 1][j] == map[i][j] || map[i][j + 1] == map[i][j]
				|| map[i - 1][j] == map[i][j] || map[i][j - 1] == map[i][j]) {
				restartNum++;
			}
		}
	}
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] != 0) flag++;
		}     
	}
	if (restartNum > 0 || flag != 16) return 0;
	else if(restartNum == 0 && flag == 16) return 1;
}
int GameWinJudge() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 2048) return 1;
		}
	}
	return 0;
}
void GameWinUI(){
	char WinString[100] = "You win!";
	char WinScoreString[100] = "";
	setbkcolor(back);//背景颜色
	cleardevice();//背景颜色
	settextcolor(RGB(119, 110, 101));//设置颜色
	settextstyle(30, 0, "微软雅黑");//字体
	sprintf(WinScoreString, "Your final score is : %d !", score);
	outtextxy(30, 180, WinString);
	outtextxy(30, 210, WinScoreString);
	Sleep(2500);
	system("pause");
	main();
}
void GameLoseUI() {
	char PrintFinalScore[100] = "";
	char WaitingStrings[100] = "        Please wait for 3 second...";
	char EndGameStrings[100] = "  Press any key to restart the game...";
	char DontCloseStrings[100] = "    Please dont't close the window...";
	Sleep(500);
	setbkcolor(back);
	cleardevice();//背景颜色
	settextcolor(RGB(119, 110, 101));
	settextstyle(30, 0, "微软雅黑");
	sprintf(PrintFinalScore, "         Your final score is : %d !", score);
	outtextxy(30, 150, PrintFinalScore);
	outtextxy(30, 180, WaitingStrings);
	outtextxy(30, 210, EndGameStrings);
	outtextxy(30, 240, DontCloseStrings);
	printf("press any key to restart the game...\n");
	Sleep(2500);
	system("pause");
	main();
}
int main(void) {
	reset();
	//创建窗口
	initgraph(MAX_GRID * GRID_WIDTH + 5 * INTERVAL, MAX_GRID * GRID_WIDTH + 5 * INTERVAL);
	GameInit();
	while (1){
		GameDraw();
		GameContorl();
		if (GameRestartJudge()) GameLoseUI();
		if (GameWinJudge()) GameWinUI();
		GameJudge();
	}
	return 0;
}