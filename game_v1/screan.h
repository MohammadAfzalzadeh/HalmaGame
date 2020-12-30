#pragma once
extern const int back_color, font_color;
extern const char star, number;
void update_screen(int pos1_x, int pos1_y, int pos_x, int pos_y, char ch, int s_color) {
	gotoxy2(pos1_x, pos1_y);
	setTextColor(s_color, back_color);
	printf(" ");
	gotoxy2(pos_x, pos_y);
	setTextColor(s_color, back_color);
	printf("%c", ch);
	setTextColor(font_color, back_color);
}
void clear_screan_to_show_masg(int n) {
	gotoxy2(0, 2 * n + 1);
	for (int i = 0; i < 200; i++)
		printf(" ");
	gotoxy2(0, 2 * n + 1);
}
void showStatus(const int n, int player, int validation) {
	static int i = 0;
	if (validation == 1)
	{
		if (i != 0)
			i--;
		if (i > 0)
			return;
		clear_screan_to_show_masg(n);
		if (player == 1)
			printf("bazi nobate %c ast", star);
		else
			printf("bazi nobate %c ast", number);


	}
	else
	{
		clear_screan_to_show_masg(n);
		if (player == 1)
			printf("harkat gabel gabol nist\ndo bare %c bazi konad ", star);
		else
			printf("harkat gabel gabol nist\ndo bare %c bazi konad", number);
		i = 2;
	}
}
void lite(int pos_x, int pos_y, int color_s ,char ch) {
	gotoxy2(pos_x, pos_y);
	setTextColor(color_s, 6);
	printf("%c", ch);
	gotoxy2(pos_x, pos_y);
}