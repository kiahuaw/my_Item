#pragma once
#include "2048.h"
//上移
void moveup() {
	int sb = 0;
	//按下上是一列一列地判断是否可以加起来
	for (int i = 0; i < MAX_GRID; i++) {//外层控制行，内层控制列
		int temp = 0;
		for (int j = 1; j < MAX_GRID; j++) {
			if (map[j][i] != 0) {//不等于0 才可以移动
				if (map[temp][i] == 0) {//如果第i行的temp为0则将begin i 复制过去
					map[temp][i] = map[j][i];
					map[j][i] = 0;
					sb++;
				}
				else if (map[temp][i] == map[j][i]) {//第i行的temp==mapbegini的值就加起来
					map[temp][i] += map[j][i];//也可以*=2
					map[j][i] = 0;
					sb++;
					score += 10;
				}
				else {//不相等的话
					map[temp + 1][i] = map[j][i];//temp下一行就等于该值
					if ((temp + 1) != j) {//不相等的话就等于0
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
//下移
void movedown() {
	int sb = 0;
	for (int i = 0; i < MAX_GRID; i++) {
		int temp = MAX_GRID - 1;
		for (int begin = MAX_GRID - 2; begin >= 0; begin--) {
			if (map[begin][i] != 0) {//不等于0 才可以移动
				if (map[temp][i] == 0) {//如果第i行的temp为0则将begin i 复制过去
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
					sb++;
				}
				else if (map[temp][i] == map[begin][i]) {//第i行的temp==mapbegini的值就加起来
					map[temp][i] += map[begin][i];//也可以*=2
					map[begin][i] = 0;
					sb++;
					score += 10;
				}
				else {//不相等的话
					map[temp - 1][i] = map[begin][i];//temp下一行就等于该值
					if ((temp - 1) != begin) {//不相等的话就等于0
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
//左移
void moveleft() {
	int sb = 0;
	for (int i = 0; i < MAX_GRID; i++) {
		int temp = 0;
		for (int begin = 1; begin < MAX_GRID; begin++) {
			if (map[i][begin] != 0) {//不等于0 才可以移动
				if (map[i][temp] == 0) {//如果第i行的temp为0则将i i 复制过去
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
					sb++;
				}
				else if (map[i][temp] == map[i][begin]) {//第i行的temp==mapii的值就加起来
					map[i][temp] += map[i][begin];//也可以*=2
					map[i][begin] = 0;
					sb++;
					score += 10;
				}
				else {//不相等的话
					map[i][temp + 1] = map[i][begin];//temp下一行就等于该值
					if ((temp + 1) != begin) {//不相等的话就等于0
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
//右移
void moveright() {
	int sb = 0;
	for (int i = 0; i < MAX_GRID; i++) {
		int temp = MAX_GRID - 1;
		for (int begin = MAX_GRID - 2; begin >= 0; begin--) {
			if (map[i][begin] != 0) {//不等于0 才可以移动
				if (map[i][temp] == 0) {//如果第i行的temp为0则将i i 复制过去
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
					sb++;
				}
				else if (map[i][temp] == map[i][begin]) {//第i行的temp==mapii的值就加起来
					map[i][temp] += map[i][begin];//也可以*=2
					map[i][begin] = 0;
					sb++;
					score += 10;
				}
				else {//不相等的话
					map[i][temp - 1] = map[i][begin];//temp下一行就等于该值
					if ((temp - 1) != begin) {//不相等的话就等于0
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