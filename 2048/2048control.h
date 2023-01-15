#pragma once
#include "2048.h"
//����
void moveup() {
	int sb = 0;
	//��������һ��һ�е��ж��Ƿ���Լ�����
	for (int i = 0; i < MAX_GRID; i++) {//�������У��ڲ������
		int temp = 0;
		for (int j = 1; j < MAX_GRID; j++) {
			if (map[j][i] != 0) {//������0 �ſ����ƶ�
				if (map[temp][i] == 0) {//�����i�е�tempΪ0��begin i ���ƹ�ȥ
					map[temp][i] = map[j][i];
					map[j][i] = 0;
					sb++;
				}
				else if (map[temp][i] == map[j][i]) {//��i�е�temp==mapbegini��ֵ�ͼ�����
					map[temp][i] += map[j][i];//Ҳ����*=2
					map[j][i] = 0;
					sb++;
					score += 10;
				}
				else {//����ȵĻ�
					map[temp + 1][i] = map[j][i];//temp��һ�о͵��ڸ�ֵ
					if ((temp + 1) != j) {//����ȵĻ��͵���0
						map[j][i] = 0;
						sb++;
					}
				}
				temp++;
				if (sb >= 1) flag = true;
				else flag = false;
			}
		}
	}
	sb = 0;
}
//����
void movedown() {
	int sb = 0;
	for (int i = 0; i < MAX_GRID; i++) {
		int temp = MAX_GRID - 1;
		for (int begin = MAX_GRID - 2; begin >= 0; begin--) {
			if (map[begin][i] != 0) {//������0 �ſ����ƶ�
				if (map[temp][i] == 0) {//�����i�е�tempΪ0��begin i ���ƹ�ȥ
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
					sb++;
				}
				else if (map[temp][i] == map[begin][i]) {//��i�е�temp==mapbegini��ֵ�ͼ�����
					map[temp][i] += map[begin][i];//Ҳ����*=2
					map[begin][i] = 0;
					sb++;
					score += 10;
				}
				else {//����ȵĻ�
					map[temp - 1][i] = map[begin][i];//temp��һ�о͵��ڸ�ֵ
					if ((temp - 1) != begin) {//����ȵĻ��͵���0
						map[begin][i] = 0;
						sb++;
					}
				}
				temp--;
				if (sb >= 1) flag = true;
				else flag = false;
			}
		}
	}
	sb = 0;
}
//����
void moveleft() {
	int sb = 0;
	for (int i = 0; i < MAX_GRID; i++) {
		int temp = 0;
		for (int begin = 1; begin < MAX_GRID; begin++) {
			if (map[i][begin] != 0) {//������0 �ſ����ƶ�
				if (map[i][temp] == 0) {//�����i�е�tempΪ0��i i ���ƹ�ȥ
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
					sb++;
				}
				else if (map[i][temp] == map[i][begin]) {//��i�е�temp==mapii��ֵ�ͼ�����
					map[i][temp] += map[i][begin];//Ҳ����*=2
					map[i][begin] = 0;
					sb++;
					score += 10;
				}
				else {//����ȵĻ�
					map[i][temp + 1] = map[i][begin];//temp��һ�о͵��ڸ�ֵ
					if ((temp + 1) != begin) {//����ȵĻ��͵���0
						map[i][begin] = 0;
						sb++;
					}
				}
				temp++;
				if (sb >= 1) flag = true;
				else flag = false;
			}
		}
	}
	sb = 0;
}
//����
void moveright() {
	int sb = 0;
	for (int i = 0; i < MAX_GRID; i++) {
		int temp = MAX_GRID - 1;
		for (int begin = MAX_GRID - 2; begin >= 0; begin--) {
			if (map[i][begin] != 0) {//������0 �ſ����ƶ�
				if (map[i][temp] == 0) {//�����i�е�tempΪ0��i i ���ƹ�ȥ
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
					sb++;
				}
				else if (map[i][temp] == map[i][begin]) {//��i�е�temp==mapii��ֵ�ͼ�����
					map[i][temp] += map[i][begin];//Ҳ����*=2
					map[i][begin] = 0;
					sb++;
					score += 10;
				}
				else {//����ȵĻ�
					map[i][temp - 1] = map[i][begin];//temp��һ�о͵��ڸ�ֵ
					if ((temp - 1) != begin) {//����ȵĻ��͵���0
						map[i][begin] = 0;
						sb++;
					}
				}
				temp--;
				if (sb >= 1) flag = true;
				else flag = false;
			}
		}
	}
	sb = 0;
}