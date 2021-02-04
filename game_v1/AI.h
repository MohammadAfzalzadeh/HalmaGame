#pragma once

int rand_between(int min, int max) {
	int random = (rand() % (max - min)) + min;
	return random;
}
void AI_move(int& x1, int& y1, int& x2, int& y2,int star_c,int number_c,int n,int state[][25],int camp[][25],int turn,int recentlymove[][5],int leave_camp,char name[]) {
	int i,ps, primer_s = 1;
	int validmove[2][50];
	while (primer_s)
	{
		showStatus(n, turn, 1, star_c, number_c,name);
		//entekhabeh moreh shoro
		int ps = 1;
		do
		{
			x1 = rand_between(0, n - 1);
			y1 = rand_between(0, n - 1);
			if (state[x1][y1] == turn)
				ps = 0;
		} while (ps);
		ArryToPosInScrean(x1, y1, x1, y1);
		//motemayez kardan mohre shoro agar vogod dashdeh bashad
		lite(x1, y1, number_c, number, state);
		NormalMove(x1, y1, n, i, state, validmove);
		NormalJump(x1, y1, n, i, state, validmove);
		super_jump(x1, y1, n, i, state, validmove);
		lite_valid_move(i, validmove);
		//entekhabeh magsad
		if (i != 0) {
			primer_s = 0;
		}
	}
	int magsad = rand_between(0, i);
	x2 = validmove[0][magsad];
	y2 = validmove[1][magsad];
	unlite_valid_move(i, validmove);
	ArryToPosInScrean(x2, y2, x2, y2);
}
