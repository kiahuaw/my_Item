#pragma once
#include "data.h"
#include "shape.h"


void Title() {
	setfillcolor(RGB(56, 56, 56));
	solidrectangle(337, 30, 465, 65);
	settextcolor(RGB(190, 183, 255));
	setbkmode(TRANSPARENT);
	settextstyle(35, 0, "Consolas");
	outtextxy(337, 30, " TETRIS");
}
void NextBlockTitle() {
	setfillcolor(RGB(56, 56, 56));
	solidrectangle(337, 90, 465, 117);
	settextstyle(25, 0, "Consolas");// 181 206 168
	settextcolor(RGB(181, 206, 168));
	outtextxy(337, 90, " NEXTBLOCK");

}
void NextBlockShow() {
	setfillcolor(RGB(56, 56, 56));
	solidrectangle(337, 119, 465, 247);

}
void MessageBox() {
	setfillcolor(RGB(56, 56, 56));
	solidrectangle(337, 277, 465, 307);
	settextcolor(RGB(223, 199, 140));
	if (MBJ.FallingShow) {
		outtextxy(337, 279, MBS.Falling);
		MBJ.FallingShow = 0;
	}
	if (MBJ.LeftMoveShow) {
		outtextxy(340, 279, MBS.LeftMove);
		MBJ.LeftMoveShow = 0;
	}
	if (MBJ.RightMoveShow) {
		outtextxy(337, 279, MBS.RightMove);
		MBJ.RightMoveShow = 0;
	}
	if (MBJ.SpinShow) {
		outtextxy(337, 279, MBS.Spin);
		MBJ.SpinShow = 0;
	}
	if (MBJ.ScoreShow) {
		outtextxy(337, 279, MBS.Score);
		MBJ.ScoreShow = 0;
	}
	if (MBJ.GameOverShow) {
		outtextxy(339, 279, MBS.GameOver);
		MBJ.GameOverShow = 0;
	}
	if (MBJ.PauseShow) {
		outtextxy(339, 279, MBS.Pause);
		MBJ.PauseShow = 0;
	}
	if (MBJ.GameRestart) {
		outtextxy(339, 279, MBS.GameRestart);
		MBJ.GameRestart = 0;
	}
}
void ScoreShowBox() {
	setfillcolor(RGB(56, 56, 56));

	solidrectangle(337, 337, 399, 367);
	settextstyle(25, 0, "Consolas");
	settextcolor(RGB(85, 170, 255));
	outtextxy(338, 339, "SCORE");

	solidrectangle(401, 337, 465, 367);
	settextstyle(25, 0, "Consolas");
	settextcolor(RGB(214, 157, 133));
	outtextxy(409, 339, "BEST");

	solidrectangle(337, 369, 399, 401);

	solidrectangle(401, 369, 465, 401);

}
void ControlBox() {
	setfillcolor(RGB(56, 56, 56));
	solidrectangle(337, 427, 465, 567);
	settextcolor(RGB(220, 220, 170));
	settextstyle(20, 0, "Consolas");
	outtextxy(337, 427, " W: SpinBlock");
	outtextxy(337, 447, " S: SpeedUp");
	outtextxy(337, 467, " A: LeftMove");
	outtextxy(337, 487, " D: RightMove");
	outtextxy(337, 507, " R: ReStart");
	outtextxy(337, 527, " E: Pause");
}