#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <string>
#include <Windows.h>
#include <graphics.h>

#define Font Microsoft YaHei UI

using namespace std;
void MainProcess();
void TimeSave(float inputnum);
void TimeProcess();
void TimeRecord();
void FormulaCreate();
void InitData();
void InitShowUI();
void ShowUI();
void Control();
void ClickDetect();
void Delete(int num);
void DataCalculate();
void DataInit();

int SaveNumbers();
int SaveFlag;

bool Press = 0;
bool StartTime = false;
bool StopTime = false;


float TimeShow = 0.00;
float sum_ao5 = 0;
float sum_ao12 = 0;
float TheFast = 100;//全部的最快
float TheSlow = 0;//全部的最慢
float ALLavg = 0;



clock_t start;//用来计时的
clock_t end_;
clock_t spacedown;
clock_t spaceup;

POINT SaveBlocks[3][15];
int Pos[15];

ExMessage key;//鼠标的key，一种结构体

struct Perm {
	char R[3][5] = { "R", "R'", "R2" };
	char L[3][5] = { "L", "L'", "L2" };
	char U[3][5] = { "U", "U'", "U2" };
	char D[3][5] = { "D", "D'", "D2" };
	char F[3][5] = { "F", "F'", "F2" };
	char B[3][5] = { "B", "B'", "B2" };
}Perm;

class Formula {
public:
	string f1;
	string f2;
	Formula() {
		f1 = "";
		f2 = "";
	}
};
Formula f;

class Saves {
	//成绩类
	//包含成绩的序号，成绩本身
public:
	Saves() {
		//构造函数   初始化
		this->f.f1 = "";
		this->f.f2 = "";
		this->Number = 0;
		this->Times = 0;
		Initff();
	}
	void Initff() {
		for (int i = 0; i < 50; i++) {
			ff1[i] = 0;
			ff2[i] = 0;
		}
	}
	void StringToChar() {
		strcpy(this->ff1, this->f.f1.c_str());
		strcpy(this->ff2, this->f.f2.c_str());
	}
	void CharToString() {
		this->f.f1 = this->ff1;
		this->f.f2 = this->ff2;
	}
	Formula f;
	int Number;
	float Times;
	char ff1[50];
	char ff2[50];

};

Saves S[256];
