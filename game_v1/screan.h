#pragma once
#include"my_exit.h"
#include"amar.h"
//extern int PPS;
extern const int back_color, font_color, max_valid_move;
extern const char star, number;
//batavagoh be harkat mohreh ra gabega mikonad
void update_screen(int pos1_x, int pos1_y, int pos_x, int pos_y, char ch, int s_color) {
	gotoxy2(pos1_x, pos1_y);
	setTextColor(s_color, back_color);
	printf(" ");
	gotoxy2(pos_x, pos_y);
	setTextColor(s_color, back_color);
	printf("%c", ch);
	setTextColor(font_color, back_color);
}
// ghsmat payyen jadval ra be mizan lazem pak mikonad
void clear_screan_to_show_masg(int n) {
	gotoxy2(0, 2 * n + 1);
	for (int i = 0; i < 200; i++)
		printf(" ");
	gotoxy2(0, 2 * n + 1);
}
// vazeiyat bazi ra dar paien jadval chop mikonad
void showStatus(int n, int player, int validation,int player1_color,int player2_color,char name[],int is_comp=0,int ENDDASTI=0) {
	int color_s = player2_color;
	if(player==1)
		color_s=player1_color;
	setTextColor(color_s, back_color);
	static int i = 0;
	if (validation == 1)
	{
		if (i != 0)
			i--;
		if (i > 0)
			return;
		clear_screan_to_show_masg(n);
		if (player == 1)
			printf("The turn is player %c", star);
		else
			printf("The turn is player %c", number);


	}
	else if(validation==0)
	{
		clear_screan_to_show_masg(n);
		if (player == 1)
			printf("Invalid move\nPalyer %c :repeat again ", star);
		else
			printf("Invalid move\nPalyer %c :repeat again ", number);
		i = 2;
	}
	else if(validation==2)
	{
		clear_screan_to_show_masg(n);
		if (player == 3) {
			setTextColor(13, back_color);
			printf("This game ended without a winner");
			my_exit(name, 2);
		}
		else
		{
			setTextColor(color_s,back_color);
			printf("end game  and player %d win", player);
			if(player==1)
				my_exit(name, 1);
			else 
				my_exit(name, 0);
		}
		if (ENDDASTI == 1)
			exit(0);

	}
	else if (validation == 3) {
		char ch;
		int playerR;
		if (player == 1)
			playerR = 2;
		else
			playerR = 1;
		clear_screan_to_show_masg(n);
		printf("The opponent has demanded a draw. Do you accept?(Y/N)");
		if (is_comp) {
			int random = rand() % 2;
			if (random == 1) {
				printf("Y");
				//sleep
				showStatus(n, 3, 2, player1_color, player2_color,name, 1);
			}
			else
			{
				printf("N");
				//sleep
				showStatus(n, playerR, 1, player1_color, player2_color, name);
			}
		}
		else{
			do
			{
				ch = _getch();
			} while (ch!='y' && ch != 'Y' && ch != 'N' && ch != 'n');
			if (ch == 'y' || ch == 'Y')
				showStatus(n, 3, 2,player1_color,player2_color, name,1);
			else {
				showStatus(n, playerR, 1, player1_color, player2_color, name);

			}
		}//end else
	}
}
// mohreh entekhab shode ra motemayez mikonad
void lite(int pos_x, int pos_y, int color_s, char ch, const int state[][25]) {
	int player;
	if (ch == '*')
		 player = 1;
	else
		player = 2;
	int check_mabda = barasi_mada(player, pos_x, pos_y, state);
	if ( check_mabda== 1){
		gotoxy2(pos_x, pos_y);
		setTextColor(color_s, 6);
		printf("%c", ch);
		gotoxy2(pos_x, pos_y);	
	}
	
}
// agar harkat galat bashad mohreh ra be halat aval bar migardanad
//unlite kardan setare moshkel darehhhhhhhhhhhhhhh
void unlite(int pos_x, int pos_y, int color_s, char ch, const int state[][25]) {
	int player;
	if (ch == '*')
		player = 1;
	else
		player = 2;
	if (barasi_mada(player, pos_x, pos_y, state) == 0)
		return;
	gotoxy2(pos_x, pos_y);
	setTextColor(color_s, back_color);
	printf("%c", ch);
	gotoxy2(pos_x, pos_y);
}
///
void lite_valid_move(int i, int validmave[][50]) {
	int x, y, pos_x = 0, pos_y = 0;
	for (int j = 0; j < i; j++)
	{
		x = validmave[0][j];
		y = validmave[1][j];
		ArryToPosInScrean(pos_x, pos_y, x, y);
		gotoxy2(pos_x, pos_y);
		setTextColor(0, 8);
		printf(" ");
		gotoxy2(pos_x, pos_y);
	}
}
//
void unlite_valid_move(int i, int validmave[][50]) {
	int x, y, pos_x = 0, pos_y = 0;
	for (int j = 0; j < i; j++)
	{
		x = validmave[0][j];
		y = validmave[1][j];
		ArryToPosInScrean(pos_x, pos_y, x, y);
		gotoxy2(pos_x, pos_y);
		setTextColor(0, back_color);
		printf(" ");
		gotoxy2(pos_x, pos_y);
	}
}