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