#pragma once
extern int bazi_count;
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
//check for tasavi khas
int Q_key(int ch) {
	if (ch == 'q' || ch == 'Q')
		return 1;
	return 0;
}
////////////
int check_draw(int recentlymove[][5]) {
	if (bazi_count < 4) {
		return 0;
	}
	//بدست آوردن اينكه  هركسي در كجاها هست
	int p1[3] = { -1,-1 }, p2[3] = { -1,-1 }, count1 = 0, count2 = 0;
	for (int i = 0; i < 4; i++)
	{
		if (recentlymove[i][0] == 1)
		{
			p1[count1] = i;
			count1++;
		}
		else
		{
			p2[count2] = i;
			count2++;
		}
	}
	//////
	//برسي اينكه هردو ثابت اند
	//p1
	if (recentlymove[p1[0]][1]/*xi1*/ == recentlymove[p1[1]][3] /*xf1*/ &&
		recentlymove[p1[0]][2]/*yi1*/ == recentlymove[p1[1]][4] /*yf1*/ &&
		recentlymove[p2[0]][1]/*xi2*/ == recentlymove[p2[1]][3] /*xf2*/ &&
		recentlymove[p2[0]][2]/*yi2*/ == recentlymove[p2[1]][4] /*yf2*/) {
		return 1;
	}
	return 0;
	///////////////////////////////////
}
// tabe asli ke baes harkat cursor mishe ta fard ENTER bezanad on noghteh ra bar migar danad ba estefadeh az ( int& pos1_x, int& pos1_y)
void move_with_keyboard(int n,int player, int& pos1_x, int& pos1_y, int& pos_x, int& pos_y, int recentlymove[][5]) {
	char ch;
	int playerR;
	if (player == 1)
		playerR = 2;
	else
		playerR = 1;
	do
	{
		ch = _getch();
		arrow_key(ch, pos_x, pos_y);
		WSAD_key(ch, pos_x, pos_y);
		if (Q_key(ch)) {
			if (check_draw(recentlymove))
				showStatus(n,playerR,3);
				
		}
		check_cursor_in_table(n, pos_x, pos_y);
		gotoxy2(pos_x, pos_y);
		pos1_x = pos_x;
		pos1_y = pos_y;
	} while (ch != 13);
}
//tanzim baray tasayi khas
void SetRecentlyMove(int player, int xi, int yi, int xf, int yf, int recentlymove[][5]) {
	//shift down
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j < 5; j++)
		{
			recentlymove[i + 1][j] = recentlymove[i][j];
		}

	}
	//end shift
	//adding new move
	recentlymove[0][0] = player;
	recentlymove[0][1] = xi;
	recentlymove[0][2] = yi;
	recentlymove[0][3] = xf;
	recentlymove[0][4] = yf;
}
//aghar harkat dorost bashad arry ra update mikonad
void update_arry(int player, int pos1_x, int pos1_y, int pos_x, int pos_y, int state[][25], int recentlymove[][5]) {
	state[((pos1_x + 1) / 2) - 1][((pos1_y + 1) / 2) - 1] = 0;
	state[((pos_x + 1) / 2) - 1][((pos_y) / 2)] = player;
	SetRecentlyMove(player, ((pos1_x + 1) / 2) - 1, ((pos1_y + 1) / 2) - 1, ((pos_x + 1) / 2) - 1, ((pos_y) / 2),recentlymove );
}


