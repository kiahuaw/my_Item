#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>//����ͼ�ο�ͷ�ļ�
#include "2048.h"
#include "2048control.h"
int twoORfour() {//���庯���������2/4
	if (rand() % 10 == 1) return 4;
	else return 2;//1/10�ĸ��ʲ���һ��4
}
void CreateNumber() {
	while (1) {
		int x = rand() % MAX_GRID;//����������λ�ò���  �����ŵ���������
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
			pos[i][j].y = i * GRID_WIDTH + (i + 1) * INTERVAL;//ÿ���������Ͻǵ�����
		}
	}
	CreateNumber();//��ʼ�� ��Ϸ��ʼʱ�����������������
	CreateNumber();
}
void GameDraw() {
	setbkcolor(back);
	cleardevice();//������ɫ
	for (int i = 0; i < MAX_GRID; i++) {
		for (int j = 0; j < MAX_GRID; j++) {
			//�ж�map��ֵ�Ƕ���    ����Ӧ������бȽϣ����ƥ���򽫶�Ӧ�������
			for (int k = 0; k < 12; k++) {
				if (map[i][j] == number[k]) {
					setfillcolor(arr[k]);//���ö�Ӧ����ɫ
					solidrectangle(pos[i][j].x, pos[i][j].y, pos[i][j].x + GRID_WIDTH, pos[i][j].y + GRID_WIDTH);
					if (map[i][j] != 0) {
						char num[5] = "";
						char scoreChar[5] = "";
						settextcolor(RGB(119, 110, 101));
						settextstyle(55, 0, "Consolas");
						setbkmode(TRANSPARENT);//���ñ���ģʽ͸��
						sprintf(num, "%d", map[i][j]);//���������뵽�ַ�����
						//���־�����ʾ
						int tempx = GRID_WIDTH / 2 - textwidth(num) / 2;//�ø��ӵ�һ���ȥ�ַ�����ȵ�һ��
						int tempy = GRID_WIDTH / 2 - textheight(num) / 2;
						outtextxy(pos[i][j].x + tempx, pos[i][j].y + tempy, num);
						//��������ʾ����
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
//���̿��������ƶ�
void GameContorl() {
	//�Ȼ�ȡ��������,_getch();
	char key = _getch();
	switch (key) {
		case 'w': case 'W': case  72: moveup();break;
		case 's': case 'S': case  80: movedown();break;
		case 'a': case 'A': case  75: moveleft();break;
		case 'd': case 'D': case  77: moveright();break;
		case 'r': case 'R': GameLoseUI();//���¿�ʼ
	}
}
void reset() {
	for (int i = 0; i < MAX_GRID; i++)
		for (int j = 0; j < MAX_GRID; j++)
			map[i][j] = 0;//���¿�ʼ�ĳ�ʼ��״̬
	score = 0;
}
int GameRestartJudge() {
	int restartNum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//�����Ԫ�ص��ϻ��»��������һ�������������
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
	setbkcolor(back);//������ɫ
	cleardevice();//������ɫ
	settextcolor(RGB(119, 110, 101));//������ɫ
	settextstyle(30, 0, "΢���ź�");//����
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
	cleardevice();//������ɫ
	settextcolor(RGB(119, 110, 101));
	settextstyle(30, 0, "΢���ź�");
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
	//��������
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