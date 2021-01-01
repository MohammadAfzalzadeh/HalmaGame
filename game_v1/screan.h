#pragma once
extern const int back_color, font_color,star_c,number_c;
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
void showStatus(const int n, int player, int validation) {
	int color_s;
	if (player == 1)
		color_s = star_c;
	else
		color_s = number_c;
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
	else
	{
		clear_screan_to_show_masg(n);
		if (player == 1)
			printf("Invalid move\nPalyer %c :repeat again ", star);
		else
			printf("Invalid move\nPalyer %c :repeat again ", number);
		i = 2;
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
void unlite(int pos_x, int pos_y, int color_s, char ch, const int state[][25]) {
	int player;
	if (ch == '*')
		player = 1;
	else
		player = 2;
	gotoxy2(pos_x, pos_y);
	setTextColor(color_s, back_color);
	printf("%c", ch);
	gotoxy2(pos_x, pos_y);
}