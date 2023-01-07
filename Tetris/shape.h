#pragma once
#include "data.h"
// 下一个方块的数据输入
void NextBlockShow(int next) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			Preview[i][j] = 0;
	if (next == 1) { Preview[3][0] = 1; Preview[2][0] = 1; Preview[1][0] = 1; Preview[0][0] = 1; }
	if (next == 2) { Preview[2][0] = 2; Preview[2][1] = 2; Preview[1][1] = 2; Preview[0][1] = 2; }
	if (next == 3) { Preview[2][0] = 3; Preview[1][0] = 3; Preview[0][0] = 3; Preview[2][1] = 3; }
	if (next == 4) { Preview[0][0] = 4; Preview[0][1] = 4; Preview[1][0] = 4; Preview[1][1] = 4; }
	if (next == 5) { Preview[1][1] = 5; Preview[1][0] = 5; Preview[0][1] = 5; Preview[0][2] = 5; }
	if (next == 6) { Preview[1][0] = 6; Preview[0][1] = 6; Preview[1][1] = 6; Preview[1][2] = 6; }
	if (next == 7) { Preview[0][0] = 7; Preview[0][1] = 7; Preview[1][1] = 7; Preview[1][2] = 7; }
}
int I_ShapeInput() {//I  旋转4次
	if (SpinNum == 1) {
		if (Spin) { Map[y - 1][x - 1] = 0; Map[y - 1][x - 2] = 0; Map[y - 1][x - 3] = 0; } Spin = 0;
		if (Map[y][x - 1] == 0 && Map[y - 1][x - 1] == 0
			&& Map[y - 2][x - 1] == 0 && Map[y - 3][x - 1] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if (Map[y][x + 1] == 0 && Map[y - 1][x + 1] == 0 
			&& Map[y - 2][x + 1] == 0 && Map[y - 4][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; };
			}
		Map[y - 3][x] = 1;Map[y - 2][x] = 1;Map[y - 1][x] = 1;Map[y][x] = 1;
		Map[y - 4][x] = 0;
		if (left) {
			Map[y - 4][x + 1] = 0;Map[y - 3][x + 1] = 0;Map[y - 2][x + 1] = 0;Map[y - 1][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 4][x - 1] = 0;Map[y - 3][x - 1] = 0;Map[y - 2][x - 1] = 0;Map[y - 1][x - 1] = 0;
			right = 0;
		}
		if (Map[y + 1][x] != 0)
			StopNum = 1;
	}
	else if (SpinNum == 2) {
		if (Spin) { Map[y - 2][x] = 0; Map[y - 3][x] = 0; Map[y - 4][x] = 0; } Spin = 0;
		if (Map[y][x - 1] == 0) {
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		}
		if (Map[y][x + 4] == 0) {
			if (right) {
				x++;
				if (x + 4 > 9) { x = 9 - 4 + 1; right = 0; }
			}
		}
		Map[y][x] = 1;Map[y][x + 1] = 1;Map[y][x + 2] = 1;Map[y][x + 3] = 1;
		Map[y - 1][x] = 0;Map[y - 1][x + 1] = 0;Map[y - 1][x + 2] = 0;Map[y - 1][x + 3] = 0;
		if (left) {
			Map[y - 1][x + 4] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;
			right = 0;
		}
		if (Map[y + 1][x] != 0 || Map[y + 1][x + 1] != 0
			|| Map[y + 1][x + 2] != 0 || Map[y + 1][x + 3] != 0)
			StopNum = 1;
	}
	else if (SpinNum == 3) {
		if (Spin) { Map[y - 1][x + 1] = 0; Map[y - 1][x + 2] = 0; Map[y - 1][x + 3] = 0; } Spin = 0;
		if (Map[y][x - 1] == 0 && Map[y + 1][x - 1] == 0 && Map[y + 2][x - 1] == 0 && Map[y + 3][x - 1] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if (Map[y][x + 1] == 0 && Map[y + 1][x + 1] == 0 && Map[y + 2][x + 1] == 0 && Map[y + 3][x + 1] == 0)
			if(right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y][x] = 1;Map[y + 1][x] = 1;Map[y + 2][x] = 1;Map[y + 3][x] = 1;
		Map[y - 1][x] = 0;
		if (left) {
			Map[y - 1][x + 1] = 0;Map[y][x + 1] = 0;Map[y + 1][x + 1] = 0;Map[y + 2][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;Map[y][x - 1] = 0;Map[y + 1][x - 1] = 0;Map[y + 2][x - 1] = 0;
			right = 0;
		}
		if (Map[y + 4][x] != 0 || y + 4 >= 20)
			StopNum = 1;
	}
	else if (SpinNum == 4) {
		if (Spin) { Map[y + 1][x] = 0; Map[y + 1][x] = 0; Map[y + 2][x] = 0; } Spin = 0;
		if (Map[y][x - 4] == 0)
			if (left) {
				x--;
				if (x - 3 < 0) { x = 3; left = 0; }
			}
		if (Map[y][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y][x] = 1;Map[y][x - 1] = 1;Map[y][x - 2] = 1;Map[y][x - 3] = 1;
		Map[y - 1][x] = 0;Map[y - 1][x - 1] = 0;Map[y - 1][x - 2] = 0;Map[y - 1][x - 3] = 0;
		if (left) {
			Map[y - 1][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 4] = 0;
			right = 0;
		}
		if (Map[y + 1][x] != 0 || Map[y + 1][x - 1] != 0
			|| Map[y + 1][x - 2] != 0 || Map[y + 1][x - 3] != 0)
			StopNum = 1;
	}

	return 0;
}
//______________________________________________________________________________________
int J_ShapeInput() {//J  旋转4次
	if (SpinNum == 1) {
		if(Spin)Map[y - 1][x - 2] = 0;
		if (Map[y][x - 2] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if (Map[y][x + 1] == 0 && Map[y - 1][x + 1] == 0 && Map[y - 2][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y - 2][x] = 2;Map[y - 1][x] = 2;Map[y][x] = 2;Map[y][x - 1] = 2;
		Map[y - 3][x] = 0; Map[y - 1][x - 1] = 0;
		if (left) {
			Map[y - 2][x + 1] = 0;Map[y - 1][x + 1] = 0;Map[y - 3][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 3][x - 1] = 0;Map[y - 2][x - 1] = 0;Map[y - 1][x - 1 - 1] = 0;
			right = 0;
		}
		if (Map[y + 1][x] != 0 || Map[y + 1][x - 1] != 0) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 2) {
		if (Spin) { Map[y - 1][x - 1] = 0; Map[y - 3][x] = 0; } Spin = 0;
		if(Map[y][x - 1] == 0 && Map[y - 1][x - 1] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if(Map[y][x + 3] == 0 && Map[y + 1][x + 1] == 0)
			if (right) {
				x++;
				if (x + 2 > 9) { x = 9 - 2; right = 0; }
			}
		Map[y][x] = 2;Map[y - 1][x] = 2;Map[y][x + 1] = 2;Map[y][x + 2] = 2;
		Map[y - 2][x] = 0;Map[y - 1][x + 1] = 0;Map[y - 1][x + 2] = 0;

		if (left) {
			Map[y - 2][x + 1] = 0;Map[y - 1][x + 3] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;Map[y - 2][x - 1] = 0;
			right = 0;
		}
		if (Map[y + 1][x] != 0 || Map[y + 1][x + 1] != 0 || Map[y + 1][x + 2] != 0) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 3) {
		if (Spin) { Map[y - 1][x + 2] = 0; Map[y - 2][x] = 0; }Spin = 0;
		if(Map[y][x - 1] == 0 && Map[y + 1][x - 1] == 0 && Map[y + 2][x - 1] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if(Map[y][x + 2] == 0 && Map[y + 1][x + 1] == 0 && Map[y + 2][x + 1] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 2;Map[y + 1][x] = 2;Map[y + 2][x] = 2;Map[y][x + 1] = 2;
		Map[y - 1][x] = 0; Map[y - 1][x + 1] = 0;

		if (left) {
			Map[y - 1][x + 2] = 0;Map[y + 1][x + 1] = 0;Map[y + 2][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;Map[y][x - 1] = 0;Map[y + 1][x - 1] = 0;
			right = 0;
		}
		if (Map[y + 3][x] != 0 || Map[y + 1][x + 1] != 0 || y + 3 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 4) {
		if (Spin)Map[y - 1][x + 1] = 0; Spin = 0;
		if(Map[y][x - 3] == 0 && Map[y + 1][x - 1] == 0)
			if (left) {
				x--;
				if (x - 2 < 0) { x = 2; left = 0; }
			}
		if(Map[y][x + 1] == 0 && Map[y + 1][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y][x] = 2;Map[y + 1][x] = 2;Map[y][x - 1] = 2;Map[y][x - 2] = 2;
		Map[y - 1][x] = 0;Map[y - 1][x - 1] = 0;Map[y - 1][x - 2] = 0;

		if (left) {
			Map[y - 1][x + 1] = 0;Map[y][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 3] = 0;
			right = 0;
		}

		if (Map[y + 2][x] != 0 || Map[y + 1][x - 1] != 0
			|| Map[y + 1][x - 2] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	return 0;
}
//______________________________________________________________________________________
int L_ShapeInput() {//L
	if (SpinNum == 1) {
		if (Spin) { Map[y - 1][x - 1] = 0; Map[y - 1][x - 2] = 0; } Spin = 0;
		if(Map[y][x - 1] == 0  && Map[y - 2][x - 1] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if(Map[y][x + 2] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y - 2][x] = 3; Map[y - 1][x] = 3; Map[y][x] = 3; Map[y][x + 1] = 3;
		Map[y - 3][x] = 0;Map[y - 1][x + 1] = 0;

		if (left) {
			Map[y - 3][x + 1] = 0; Map[y - 2][x + 1] = 0; Map[y - 1][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;Map[y - 2][x - 1] = 0;Map[y - 3][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 1][x] != 0 || Map[y + 1][x + 1] != 0) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 2) {
		if (Spin) { Map[y - 3][x] = 0; Map[y - 2][x] = 0; } Spin = 0;
		if(Map[y][x - 1] == 0 && Map[y + 1][x - 1] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if (Map[y][x + 3] == 0 && Map[y + 1][x + 1] == 0)
			if (right) {
				x++;
				if (x + 2 > 9) { x = 9 - 2; right = 0; }
			}
		Map[y][x] = 3;Map[y + 1][x] = 3;Map[y][x + 1] = 3;Map[y][x + 2] = 3;
		Map[y - 1][x] = 0;Map[y - 1][x + 1] = 0;Map[y - 1][x + 2] = 0;

		if (left) {
			Map[y - 1][x + 3] = 0;
			left = 0;
		}
		if (right) {
			Map[y][x - 1] = 0;Map[y - 1][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 2][x] != 0 || Map[y + 1][x + 1] != 0
			|| Map[y + 1][x + 2] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 3) {
		if (Spin) { Map[y - 1][x + 1] = 0; Map[y - 1][x + 2] = 0; Map[y - 0][x + 3] = 0; } Spin = 0;
		if (Map[y][x - 2] == 0 && Map[y + 1][x - 1] == 0 && Map[y + 2][x - 1] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if (Map[y][x + 1] == 0 && Map[y + 1][x + 1] == 0 && Map[y + 2][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y][x] = 3;Map[y][x - 1] = 3;Map[y + 1][x] = 3;Map[y + 2][x] = 3;
		Map[y - 1][x] = 0;Map[y - 1][x - 1] = 0;

		if (left) {
			Map[y + 1][x + 1] = 0;Map[y][x + 1] = 0;Map[y - 1][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 2] = 0;Map[y + 1][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 3][x] != 0 || Map[y + 1][x - 1] != 0 || y + 3 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 4) {
		if (Spin)Map[y + 1][x] = 0; Spin = 0;
		if(Map[y][x - 3] == 0 )
			if (left) {
				x--;
				if (x - 2 < 0) { x = 2; left = 0; }
			}
		if(Map[y][x + 1] == 0 && Map[y + 1][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y][x] = 3;Map[y - 1][x] = 3;Map[y][x - 1] = 3;Map[y][x - 2] = 3;
		Map[y - 2][x] = 0;Map[y - 1][x - 1] = 0;Map[y - 1][x - 2] = 0;

		if (left) {
			Map[y - 1][x + 1] = 0;Map[y - 2][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 3] = 0;Map[y - 2][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 1][x] != 0 || Map[y + 1][x - 1] != 0 || Map[y + 1][x - 2] != 0) {
			StopNum = 1;
		}
	}
	return 0;
}
//______________________________________________________________________________________
int O_ShapeInput() {//O  不用旋转
	if (SpinNum > 0) {
		if (Map[y][x - 1] == 0 && Map[y - 1][x - 1] == 0) 
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if (Map[y][x + 2] == 0 && Map[y - 1][x + 2] == 0) 
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y - 1][x] = 4;Map[y - 1][x + 1] = 4;Map[y][x] = 4;Map[y][x + 1] = 4;
		Map[y - 2][x] = 0;Map[y - 2][x + 1] = 0;
		
		if (left) {
			Map[y - 1][x + 2] = 0;Map[y - 2][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;Map[y - 2][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 1][x] != 0 || Map[y + 1][x + 1] != 0) {
			StopNum = 1;
		}
	}
	return 0;
}
//______________________________________________________________________________________
int S_ShapeInput() {//S  旋转2次
	if (SpinNum == 1) {
		if (Spin)Map[y - 2][x - 1] = 0; Spin = 0;
		if(Map[y][x - 2] == 0 )
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if(Map[y][x + 1] == 0 && Map[y - 1][x + 2] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 5;Map[y - 1][x] = 5;Map[y - 1][x + 1] = 5;Map[y][x - 1] = 5;
		Map[y - 1][x - 1] = 0;Map[y - 2][x] = 0;Map[y - 2][x + 1] = 0;

		if (left) {
			Map[y - 2][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 2] = 0;Map[y - 2][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 1][x] != 0 || Map[y + 1][x - 1] != 0 || Map[y][x + 1] != 0) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 2) {
		if (Spin) { Map[y - 1][x - 1] = 0; Map[y - 2][x] = 0; Map[y - 2][x + 1] = 0; } Spin = 0;
		if(Map[y][x - 1] == 0 && Map[y - 1][x - 1] == 0 && Map[y + 1][x] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if(Map[y][x + 2] == 0  && Map[y + 1][x + 2] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 5;Map[y][x + 1] = 5;Map[y + 1][x + 1] = 5;Map[y - 1][x] = 5;
		Map[y - 2][x] = 0;Map[y - 1][x + 1] = 0;
		
		if (left) {
			Map[y - 2][x + 1] = 0;Map[y - 1][x + 2] = 0;Map[y][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;Map[y - 2][x - 1] = 0;
			right = 0;
		}
		
		if (Map[y + 1][x] != 0 || Map[y + 2][x + 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 3) {
		if (Spin)Map[y - 2][x] = 0; Spin = 0;
		if(Map[y + 1][x - 2] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if(Map[y][x + 2] == 0 && Map[y + 1][x + 1] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 5;Map[y + 1][x] = 5;Map[y + 1][x - 1] = 5;Map[y][x + 1] = 5;
		Map[y - 1][x] = 0;Map[y][x - 1] = 0;Map[y - 1][x + 1] = 0;

		if (left) {
			Map[y - 1][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;Map[y][x - 2] = 0;
			right = 0;
		}

		if (Map[y + 2][x] != 0 || Map[y + 2][x - 1] != 0
			|| Map[y + 1][x + 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 4) {
		if (Spin)Map[y - 1][x + 1] = 0; Spin = 0;
		if(Map[y][x - 2] == 0 && Map[y - 1][x - 2] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if(Map[y][x + 1] == 0 && Map[y + 1][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y][x] = 5;Map[y + 1][x] = 5;Map[y][x - 1] = 5;Map[y - 1][x - 1] = 5;
		Map[y - 1][x] = 0;Map[y - 2][x - 1] = 0;

		if (left) {
			Map[y - 1][x + 1] = 0;Map[y - 2][x] = 0;Map[y][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 2][x - 2] = 0;Map[y - 1][x - 2] = 0;
			right = 0;
		}

		if (Map[y + 2][x] != 0 || Map[y + 1][x - 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	return 0;
}
//______________________________________________________________________________________
int T_ShapeInput() {//T
	if (SpinNum == 1) {
		if(Map[y][x - 2] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if(Map[y][x + 2] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 6;Map[y][x - 1] = 6;Map[y - 1][x] = 6;Map[y][x + 1] = 6;
		Map[y - 1][x - 1] = 0;Map[y - 2][x] = 0;Map[y - 1][x + 1] = 0;

		if (left) {
			Map[y - 2][x + 1] = 0;
			Map[y - 1][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 2][x - 1] = 0;
			Map[y - 1][x - 2] = 0;
			right = 0;
		}

		if (Map[y + 1][x] != 0 || Map[y + 1][x + 1] != 0
			|| Map[y + 1][x - 1] != 0 || y + 1 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 2) {
		if (Spin) { Map[y - 1][x + 1] = 0; Map[y - 2][x] = 0; Map[y - 1][x - 1] = 0; }Spin = 0;
		if(Map[y][x - 1] == 0 && Map[y - 1][x - 1] == 0 && Map[y + 1][x - 1] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if(Map[y][x + 2] == 0 && Map[y + 1][x + 1] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 6;Map[y + 1][x] = 6;Map[y - 1][x] = 6;Map[y][x + 1] = 6;
		Map[y - 2][x] = 0;Map[y - 1][x + 1] = 0;

		if (left) {
			Map[y - 1][x + 2] = 0;Map[y - 2][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y][x - 1] = 0;Map[y - 1][x - 1] = 0;Map[y - 2][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 2][x] != 0 || Map[y + 1][x + 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 3) {
		if (Spin)Map[y - 2][x] = 0; Spin = 0;
		if(Map[y][x - 2] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if (Map[y][x + 2] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 6;Map[y][x + 1] = 6;Map[y][x - 1] = 6;Map[y + 1][x] = 6;
		Map[y - 1][x] = 0;Map[y - 1][x - 1] = 0;Map[y - 1][x + 1] = 0;

		if (left) {
			Map[y - 1][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 2] = 0;
			right = 0;
		}

		if (Map[y + 2][x] != 0 || Map[y + 1][x - 1] != 0
			|| Map[y + 1][x + 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 4) {
		if (Spin) { Map[y - 1][x + 1] = 0; Map[y - 1][x - 1] = 0; }Spin = 0;
		if(Map[y][x - 2] == 0 && Map[y + 1][x - 1] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if(Map[y][x + 1] == 0 && Map[y - 1][x + 1] == 0 && Map[y + 1][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y][x] = 6;Map[y + 1][x] = 6;Map[y - 1][x] = 6;Map[y][x - 1] = 6;
		Map[y - 2][x] = 0;Map[y - 1][x - 1] = 0;

		if (left) {
			Map[y][x + 1] = 0;Map[y - 1][x + 1] = 0;Map[y - 2][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 2] = 0;Map[y - 2][x - 1] = 0;
			right = 0;
		}
		if (Map[y + 2][x] != 0 || Map[y + 1][x - 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	return 0;
}
//______________________________________________________________________________________
int Z_ShapeInput() {//Z
	if (SpinNum == 1) {
		if (Spin) { Map[y][x - 1] = 0; } Spin = 0;
		if(Map[y - 1][x - 2] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if(Map[y][x + 2] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 7;Map[y - 1][x - 1] = 7;Map[y - 1][x] = 7;Map[y][x + 1] = 7;
		Map[y - 2][x - 1] = 0;Map[y - 2][x] = 0;Map[y - 1][x + 1] = 0;

		if (left) {
			Map[y - 1][x + 2] = 0;Map[y - 2][x + 1] = 0;Map[y - 2][x] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 2][x - 1] = 0;Map[y - 2][x - 2] = 0;
			right = 0;
		}

		if (Map[y + 1][x] != 0 || Map[y + 1][x + 1] != 0 || Map[y][x - 1] != 0) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 2) {
		if (Spin) { Map[y - 2][x] = 0; Map[y - 2][x - 1] = 0; } Spin = 0;
		if(Map[y][x - 1] == 0 && Map[y + 1][x - 1] == 0)
			if (left) {
				x--;
				if (x < 0) { x = 0; left = 0; }
			}
		if(Map[y][x + 2] == 0 && Map[y - 1][x + 2] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 7;Map[y + 1][x] = 7;Map[y][x + 1] = 7;Map[y - 1][x + 1] = 7;
		Map[y - 1][x] = 0;Map[y - 2][x + 1] = 0;

		if (left) {
			Map[y - 2][x + 2] = 0;Map[y - 1][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y][x - 1] = 0;Map[y - 2][x] = 0;Map[y - 1][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 2][x] != 0 || Map[y + 1][x + 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 3) {
		if (Spin) { Map[y - 1][x + 1] = 0; Map[y - 2][x + 1] = 0; }Spin = 0;
		if(Map[y][x - 2] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if(Map[y + 1][x + 2] == 0)
			if (right) {
				x++;
				if (x + 1 > 9) { x = 9 - 1; right = 0; }
			}
		Map[y][x] = 7;Map[y + 1][x] = 7;Map[y + 1][x + 1] = 7;Map[y][x - 1] = 7;
		Map[y - 1][x] = 0;Map[y][x + 1] = 0;Map[y - 1][x - 1] = 0;

		if (left) {
			Map[y - 1][x + 1] = 0;Map[y][x + 2] = 0;
			left = 0;
		}
		if (right) {
			Map[y - 1][x - 1] = 0;Map[y - 1][x - 2] = 0;
			right = 0;
		}

		if (Map[y + 2][x] != 0 || Map[y + 2][x + 1] != 0
			|| Map[y + 1][x - 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	else if (SpinNum == 4) {
		if (Spin) { Map[y - 2][x - 1] = 0; Map[y][x + 1] = 0; } Spin = 0;
		if(Map[y][x - 2] == 0 && Map[y + 1][x - 2] == 0)
			if (left) {
				x--;
				if (x - 1 < 0) { x = 1; left = 0; }
			}
		if(Map[y][x + 1] == 0 && Map[y - 1][x + 1] == 0)
			if (right) {
				x++;
				if (x > 9) { x = 9; right = 0; }
			}
		Map[y][x] = 7;Map[y - 1][x] = 7;Map[y][x - 1] = 7;Map[y + 1][x - 1] = 7;
		Map[y - 2][x] = 0;Map[y - 1][x - 1] = 0;

		if (left) {
			Map[y - 1][x + 1] = 0;Map[y - 2][x + 1] = 0;
			left = 0;
		}
		if (right) {
			Map[y][x - 2] = 0;Map[y - 1][x - 2] = 0;Map[y - 2][x - 1] = 0;
			right = 0;
		}

		if (Map[y + 1][x] != 0 || Map[y + 2][x - 1] != 0 || y + 2 >= 20) {
			StopNum = 1;
		}
	}
	return 0;
}
//______________________________________________________________________________________
