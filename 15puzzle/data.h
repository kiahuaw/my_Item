#pragma once
#include <graphics.h>
#include <easyx.h>

int Map[4][4] = { 0 };

int InitArr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

int move = 0;

int KEY_X;

int KEY_Y;

time_t start, end;

POINT pos[4][4];//为了方便，先保存每个格子左上角的坐标

MOUSEMSG key;

void Control();

void InitGame();

void InitUI();

void ShowUI();

void GamePlay();

void Move(int x, int y);

int GameEndJudge();

void Time();

void MouseShow();







