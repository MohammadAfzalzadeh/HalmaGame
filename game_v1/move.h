#pragma once
//harkat cursor aghar kelid jahaty bashad
void arrow_key(char ch, int& pos_x, int& pos_y) {
	if (ch == 0 || ch == 224)
		ch = _getch();
	if (ch == 77) {
		/*==>*/
		pos_x += 2;
	}

	else if (ch == 75) {
		/*<==*/
		pos_x -= 2;
	}
	else if (ch == 80) {
		/*payyn*/
		pos_y += 2;
	}

	else if (ch == 72) {
		/*bala*/
		pos_y -= 2;
	}
}
//harkat cursor aghar kelidhay (w,s,a,d) bashad
void WSAD_key(char ch, int& pos_x, int& pos_y) {
	switch (ch)
	{
	case 97:
		pos_x -= 2;
		break;
	case 115:
		pos_y += 2;
		break;
	case 100:
		pos_x += 2;
		break;
	case 119:
		pos_y -= 2;
		break;
	default:
		break;
	}
}
//barasi in ke cursor az gadval khareg nasheh
void check_cursor_in_table(int n, int& pos_x, int& pos_y) {
	if (pos_x < 0) {
		pos_x = 1;
	}
	if (pos_y < 0)
	{
		pos_y = 1;
	}
	if (pos_x > 2 * n)
	{
		pos_x = 2 * n - 1;
	}
	if (pos_y > 2 * n)
	{
		pos_y = 2 * n - 1;
	}
}
// tabe asli ke baes harkat cursor mishe ta fard ENTER bezanad on noghteh ra bar migar danad ba estefadeh az ( int& pos1_x, int& pos1_y)
void move_with_keyboard(int n, int& pos1_x, int& pos1_y, int& pos_x, int& pos_y) {
	char ch;
	do
	{
		ch = _getch();
		arrow_key(ch, pos_x, pos_y);
		WSAD_key(ch, pos_x, pos_y);
		check_cursor_in_table(n, pos_x, pos_y);
		gotoxy2(pos_x, pos_y);
		pos1_x = pos_x;
		pos1_y = pos_y;
	} while (ch != 13);
}
 //aghar harkat dorost bashad arry ra update mikonad
void update_arry(int player, int pos1_x, int pos1_y, int pos_x, int pos_y, int state[][25]) {
	state[((pos1_x + 1) / 2) - 1][((pos1_y + 1) / 2) - 1] = 0;
	state[((pos_x + 1) / 2) - 1][((pos_y) / 2)] = player;
}


