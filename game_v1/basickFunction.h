#pragma once
//
void gotoxy1(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = y;
	cursorCoord.Y = x;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
//tabe har kat Cursor 
void gotoxy2(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
//tabe delay
void sleep(unsigned int mseconds) {
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
//tabeh rang amizi
void setTextColor(int textColor, int backColor) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle, colorAttribute);
}
void PosInScreanToArry(int pos_x, int pos_y, int& x, int& y) {
	x = (pos_x + 1) / 2 -1;
	y = pos_y / 2;
}
void ArryToPosInScrean(int &pos_x, int &pos_y, int x, int y) {
	pos_x = (x + 1) * 2 - 1;
	pos_y = 2 * y+1;
}
int is_x_y_in_table(int x,int y,int n) {
	if (x<0 || x>n - 1 || y<0 || y>n - 1)
		return 0;
	return 1;
}