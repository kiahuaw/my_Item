#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <Windows.h>
#include <graphics.h>


using namespace std;
void MainProcess();
void TimeSave(float inputnum);
void TimeProcess();
void TimeRecord();

void InitData();
void InitShowUI();
void ShowUI();
void Control();
void Delete();
void DataCalculate();
void DataInit();

int SaveNumbers();

bool Press = 0;
bool deleteif = 0;
bool StartTime = false;
bool StopTime = false;


float TimeShow = 0.00;
float sum_ao5 = 0;
float sum_ao12 = 0;
float TheFast = 100;//全部的最快
float TheSlow = 0;//全部的最慢
float Sheet[13] = { 0 };
float ALLavg = 0;
float* TotalSave = (float*)malloc(sizeof(float) * 256);


clock_t start;//用来计时的
clock_t end_;
clock_t spacedown;
clock_t spaceup;



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