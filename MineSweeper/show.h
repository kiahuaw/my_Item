#pragma once
#include <graphics.h>
#include "data.h"

void InitShowUI() {
	if (choice == 0) { width = 318, height = 440; }
	if (choice == 1) { width = 556, height = 680; }
	initgraph(width, height);//��������
	setbkcolor(RGB(161, 97, 26));
	cleardevice();
	return;
}
void ShowUI() {
	BeginBatchDraw();//��ֹ��ͼ��˸
	cleardevice();
	if (choice == 0) {
		setbkmode(TRANSPARENT);
		//�Ѷ�
		setfillcolor(RGB(204, 145, 65));
		solidrectangle(0, 400, 318, 440);
		//easy
		setfillcolor(RGB(251, 217, 130));
		solidroundrect(15, 405, 150, 435, 6, 6);
		settextcolor(RGB(196, 133, 54));
		settextstyle(35, 0, "��������");
		outtextxy(25, 405, "MIDDLE");
		// exit
		solidroundrect(167, 405, 303, 435, 6, 6);
		outtextxy(205, 405, "EXIT");
		//��书����
		setfillcolor(RGB(204, 145, 65));
		solidrectangle(0, 0, 318, 82);
		//���¿�ʼͼ�����
		setfillcolor(RGB(251, 217, 130));
		solidroundrect(132, 20, 182, 70, 6, 6);
		//newgame
		settextcolor(RGB(196, 133, 54));
		settextstyle(20, 0, "��������");
		outtextxy(138, 25, "New");
		settextstyle(20, 0, "��������");
		outtextxy(134, 45, "game");
		//���Ͻǵ�����
		settextcolor(RGB(245, 87, 98));
		char minearr[5] = " ";
		if (win)sprintf(minearr, "%d", 0);
		else sprintf(minearr, "%d", MineNum);
		settextstyle(50, 0, "��������");
		setfillcolor(RGB(161, 97, 26));
		solidroundrect(212, 20, 303, 70, 6, 6);
		int temp = textwidth(minearr);
		outtextxy(212 + (303 - 212) / 2 - temp / 2, 23, minearr);
		//��ʾʱ��s
		char time[5] = " ";
		sprintf(time, "%d", end - start);
		int timetemp = textwidth(time);
		solidroundrect(15, 20, 102, 70, 6, 6);
		outtextxy(15 + (102 - 15) / 2 - timetemp / 2, 23, time);
	}
	if (choice == 1) {
		setbkmode(TRANSPARENT);
		//ѡ���Ѷ�
		setfillcolor(RGB(204, 145, 65));
		solidrectangle(0, 637, 556, 680);
		//easy
		setfillcolor(RGB(251, 217, 130));
		solidroundrect(15, 643, 270, 672, 6, 6);
		settextcolor(RGB(196, 133, 54));
		settextstyle(35, 0, "��������");
		outtextxy(108, 643, "EASY");
		//exit
		solidroundrect(286, 643, 541, 672, 6, 6);
		outtextxy(383, 643, "EXIT");
		//��书����
		setfillcolor(RGB(204, 145, 65));
		solidrectangle(0, 0, 556, 82);
		//���¿�ʼͼ�����
		setfillcolor(RGB(251, 217, 130));
		solidroundrect(130, 20, 425, 70, 10, 10);
		//newgame
		settextcolor(RGB(196, 133, 54));	
		settextstyle(60, 0, "��������");
		outtextxy(140, 20, "New Game");
		//���Ͻǵ�����
		settextcolor(RGB(245, 87, 98));
		char minearr[5] = " ";
		if (win)sprintf(minearr, "%d", 0);
		else sprintf(minearr, "%d", MineNum);
		settextstyle(50, 0, "��������");
		setfillcolor(RGB(161, 97, 26));
		solidroundrect(212 + 240, 20, 303 + 240, 70, 6, 6);
		int temp = textwidth(minearr);
		outtextxy(212 + 240 + (303 - 212) / 2 - temp / 2, 23, minearr);
		//��ʾʱ��s
		char time[5] = " ";
		sprintf(time, "%d", end - start);
		int timetemp = textwidth(time);
		solidroundrect(15, 20, 102, 70, 6, 6);
		outtextxy(15 + (102 - 15) / 2 - timetemp / 2, 23, time);
	}
	//��ʼ����ͼ��
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {//Ϊ10��X   11�� ?'
			if (FlagMap[i][j] == 0 || FlagMap[i][j] == 10 || FlagMap[i][j] == 11) {//����0�Ǳ��ڵ�״̬				
				setfillcolor(RGB(251, 217, 130));
				solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30, 6, 6);
			}
			if (FlagMap[i][j] > 0 && FlagMap[i][j] <= 9) {//������0������������
				setfillcolor(RGB(196, 133, 54));
				solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30, 6, 6);
			}			
			if (FlagMap[i][j] > 0 && FlagMap[i][j] < 9) {
				for (int k = 0; k < 8; k++) {
					if (FlagMap[i][j] == k + 1)//������ɫ
						settextcolor(ColorArr[k + 1]);
				}
				char Mines[5] = " ";
				sprintf(Mines, "%d", FlagMap[i][j]);
				settextstyle(30, 0, "��������");//����׵ĸ���
				outtextxy(pos[i][j].x + 6, pos[i][j].y + 2, Mines);
			}
			if (FlagMap[i][j] == 10) {
				settextstyle(35, 0, "��������");
				settextcolor(RGB(228, 75, 86));//���ӻ�������
				outtextxy(pos[i][j].x - 2, pos[i][j].y - 1, "��");
			}
			if (FlagMap[i][j] == 11) {
				settextstyle(35, 0, "��������");
				settextcolor(RGB(228, 75, 86));//�ʺ�
				outtextxy(pos[i][j].x + 6, pos[i][j].y, "?");
			}
			if (boom == true && Map[i][j] == 1) {
				setfillcolor(RGB(245, 87, 98));//��Ϸ������ʾ��
				solidroundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30, 6, 6);
			}
			if (win) {//ʤ�����ױ���				
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
	MouseVision();
	EndBatchDraw();
	return;
}
void MouseVision() {//��ʾ���λ�ã���ʵ���Ǹ�������ڵĸ��ӼӸ����
	BeginBatchDraw();//��ֹ��ͼ��˸
	setlinecolor(RGB(161, 97, 26));
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			if (KEY_X >= pos[i][j].x && KEY_X <= pos[i][j].x + 30 && KEY_Y >= pos[i][j].y && KEY_Y <= pos[i][j].y + 30) {
				roundrect(pos[i][j].x, pos[i][j].y, pos[i][j].x + 30, pos[i][j].y + 30, 6, 6);
				roundrect(pos[i][j].x + 1, pos[i][j].y + 1, pos[i][j].x + 29, pos[i][j].y + 29, 6, 6);
			}
		}
	}
	if (choice == 0) {//�ؿ�����
		if (KEY_X >= 132 && KEY_X <= 182 && KEY_Y >= 20 && KEY_Y <= 70) {
			roundrect(132, 20, 182, 70, 6, 6);
			roundrect(133, 21, 181, 69, 6, 6);
		}
	}
	else if (choice == 1) {//130, 20, 425, 70, 6, 6
		if (KEY_X >= 130 && KEY_X <= 425 && KEY_Y >= 20 && KEY_Y <= 70) {
			roundrect(130, 20, 425, 70, 6, 6);
			roundrect(131, 21, 424, 69, 6, 6);
		}
	}
	if (choice == 1) {//11111
		if (KEY_X >= 15 && KEY_X <= 270 && KEY_Y >= 643 && KEY_Y <= 672) {
			roundrect(15, 643, 270, 672, 6, 6);
			roundrect(16, 644, 269, 671, 6, 6);
		}
		if (KEY_X >= 286 && KEY_X <= 541 && KEY_Y >= 643 && KEY_Y <= 672) {
			roundrect(286, 643, 541, 672, 6, 6);
			roundrect(287, 644, 540, 671, 6, 6);
		}
	}
	 else if (choice == 0) {//00000
		if (KEY_X >= 15 && KEY_X <= 150 && KEY_Y >= 405 && KEY_Y <= 435) {
			roundrect(15, 405, 150, 435, 6, 6);
			roundrect(16, 406, 149, 434, 6, 6);
		}
		if (KEY_X >= 167 && KEY_X <= 303 && KEY_Y >= 405 && KEY_Y <= 435) {
			roundrect(167, 405, 303, 435, 6, 6);
			roundrect(168, 406, 302, 434, 6, 6);
		}
	}
	EndBatchDraw();
}