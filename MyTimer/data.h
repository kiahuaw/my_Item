#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <easyx.h>

void MainProcess();

void TimeProcess();

void TimeRecord();

void InitData();

void FormulaCreate();

void InitShowUI();

void ShowUI();

void Control();

void TimeSave(float inputnum);

void Delete();

void DataCalculate();

bool StartTime = false;

bool StopTime = false;

bool ao5count = false;

bool ao12count = false;

float TimeShow = 0.00;

float sum_ao5 = 0;

float sum_ao12 = 0;

float Fastest = 100;//初始化为100以便判断

float Slowest = 0;

float Sheet[12] = { 0 };//写的是去尾平均   求掉最高和最低  保留的是两位小数

char Formula[24][5] = { 0 };

struct Perm {
	char R[3][5] = { "R", "R'", "R2" };
	char L[3][5] = { "L", "L'", "L2" };
	char U[3][5] = { "U", "U'", "U2" };
	char D[3][5] = { "D", "D'", "D2" };
	char F[3][5] = { "F", "F'", "F2" };
	char B[3][5] = { "B", "B'", "B2" };
}Perm;



clock_t start;//用来计时的

clock_t end;