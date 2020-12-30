#pragma once

int barrasi_magsad(int x, int y, const int state[][25]) {
	x--;
	y--;
	x /= 2;
	y /= 2;
	if (state[x][y] == 0)
		return 1;
	return 0;
}

int select_turn(int turn, int n) {
	gotoxy2(0, 2 * n + 2);
	printf("              ");
	if (turn == 1)
		return 2;
	return 1;
}

int barasi_mada(int player, int pos1_x, int pos1_y, const int state[][25]) {
	pos1_x = (pos1_x - 1) / 2;
	pos1_y = (pos1_y - 1) / 2;
	if (state[pos1_x][pos1_y] == player)
		return 1;
	return 0;
}

int check_role(int player, int pos1_x, int pos1_y, int x, int y, const int state[][25]) {
	if (barrasi_magsad(x, y, state) == 1 && barasi_mada(player, pos1_x, pos1_y, state) == 1)
		return 1;
	return 0;
}

