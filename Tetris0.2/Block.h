#pragma once
class CenterBlock {
public:
	CenterBlock() {
		x = 0;
		y = 0;
	}
	int x;
	int y;
};
class Block {
public:
	Block() {
		block = '0';
	}
	char block;
	CenterBlock coord;
	int J[3] = { 32,32,96 };
	int L[3] = { 32,32,48 };
	int I[4] = { 32,32,32,32 };
	int T[2] = { 32,112 };
	int O[2] = { 48, 48 };
	int S[2] = { 48, 96 };
	int Z[2] = { 96, 48 };
};

