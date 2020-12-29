#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
//#include <ctime>
// moshkel (#include <ctime>)  hal she
// 0- vasat chin kardan jadval
//0.1-khaneh hay jadval bozog shavad
//functional sazy va fayl sazi
const int back_color = 15;
const int font_color = 0;
const char star = '*';
const char number = '#';
const int star_c = 4;
const int number_c = 9;
void gotoxy1(int, int);
void sleep(unsigned int mseconds) {
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
void setTextColor(int textColor, int backColor ) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle, colorAttribute);
}
///start.h
void printTable(int n,int state[][25]) {
	int i,j;
	system("cls");
	for ( i = 0; i <= n; i++)
	{
		setTextColor(0, 15);
		for ( j = 0; j <= n; j++)
		{
			setTextColor(0, 15);
			if (i == 0) {
				if (j == 0) { printf("%c",201); }
				else if (j==n){ printf("%c", 187); }
				else { printf("%c", 203); }
				if (j!=n) printf("%c",205);
			}
			else if (i == n) {
				if (j == 0) { printf("%c", 200); }
				else if (j == n) { printf("%c", 188); }
				else { printf("%c", 202); }
				if (j != n) printf("%c",  205);
			}
			else
			{
				if (j == 0) { printf("%c", 204); }
				else if (j == n) { printf("%c", 185); }
				else { printf("%c", 206); }
				if (j != n) printf("%c", 205);
			}
		}
		printf("\n");
		if (i != n) {
			for (j = 0; j <= n; j++)
			{
				printf("%c", 186);
				//mohreh ha
				if (state[j][i]==1) {
					setTextColor(4, 15);
					printf("*");
				}
				else if(state[j][i] == 2){
					setTextColor(9, 15);
					printf("#");
				}
				else {//state[j][i]==0
					setTextColor(0, 15);
					printf(" ");
				}
				setTextColor(0, 15);
			}
			
			printf("\n");
		}
	}
}
//start.h
void start_p1( int state[][25], int mohreh_dar_aval[7]) {
	for (int i = 0; i < 7; i++)
	{
		int screw_count = 0;
		int space_to_full = (i + 1)-mohreh_dar_aval[i];
		space_to_full /= 2;
		int null_count = 0;
		for (int x = 0; x < 20; x++)
		{
			for (int  y = 0; y < 20; y++)
			{
				
				if (x+y==i && screw_count < mohreh_dar_aval[i])
				{
					if (null_count < space_to_full)
						null_count++;
					else
					{
						state[x][y] = 1;
						screw_count++;
					}
					
				}
			}
		}
	}
}
//start.h
void start_p2(int state[][25], int mohreh_dar_aval[7], int n) {
	for (int i = 0; i < 7; i++)
	{
		int screw_count = 0;
		int space_to_full = (i + 1) - mohreh_dar_aval[i];
		space_to_full /= 2;
		int null_count = 0;
		for (int x = n-1; x >= 0; x--)
		{
			for (int y = n-1; y >= 0; y--)
			{
				if (x + y == ((2*n)-2-i) && screw_count < mohreh_dar_aval[i])
				{
					if (null_count < space_to_full)
						null_count++;
					else
					{
						state[x][y] = 2;
						screw_count++;
					}
					
				}
			}
		}
	}
}
//role.h
int barrasi_magsad(int x, int y,const int state[][25]) {
	x--;
	y--;
	x /= 2; 
	y /= 2;
	if (state[x][y] == 0)
		return 1;
	return 0;
}
void gotoxy1(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = y;
	cursorCoord.Y = x;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
void gotoxy2(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
//move.h
void arrow_key(char ch,int& pos_x, int& pos_y) {
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
//move.h
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
//move.h
void check_couecer_in_table(int n, int& pos_x, int& pos_y){
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
//move.h
void move_with_keyboard1(int n, int& pos1_x, int& pos1_y,int &pos_x,int &pos_y) {
	char ch;
	do
	{
		ch = _getch();
		arrow_key(ch, pos_x, pos_y);
		WSAD_key(ch, pos_x, pos_y);
		//else break;
		check_couecer_in_table(n, pos_x, pos_y);
		gotoxy2(pos_x, pos_y);
		pos1_x = pos_x;
		pos1_y = pos_y;
	} while (ch != 13);
}
//screan.h
void update_screen(int pos1_x,int pos1_y,int pos_x,int pos_y,char ch,int s_color) {
	gotoxy2(pos1_x,pos1_y);
	printf(" ");
	gotoxy2(pos_x,pos_y);
	setTextColor(s_color, back_color);
	printf("%c",ch);
	setTextColor(font_color, back_color);
}
//role.h
int select_turn(int turn,int n) {
	gotoxy2(0, 2 * n+2);
	printf("              ");
	if (turn == 1)
		return 2;
	return 1;
}
//role.h
int barasi_mada(int player,int pos1_x,int pos1_y, const int state[][25]) {
	pos1_x = (pos1_x - 1) / 2;
	pos1_y = (pos1_y - 1) / 2;
	if (state[pos1_x][pos1_y] == player)
		return 1;
	return 0;
}
//role.h
int check(int player, int pos1_x, int pos1_y, int x,int y, const int state[][25]) {
	if (barrasi_magsad(x, y, state) == 1 && barasi_mada(player, pos1_x, pos1_y, state) == 1)
		return 1;
	return 0;
}
void update_arry(int player, int pos1_x, int pos1_y,int pos_x,int pos_y, int state[][25]) {
	state[((pos1_x+1)/2)-1][((pos1_y+1)/2)-1] = 0;
	state[((pos_x+1)/2)-1][((pos_y)/2)] = player;
}
//screan.h
void clear_screan_to_show_masg(int n){
	gotoxy2(0, 2 * n + 1);
	for (int i = 0; i < 200; i++)
		printf(" ");
	gotoxy2(0, 2 * n + 1);
}
//screan.h
void showStatus(const int n,int player ,int validation) {
	static int i = 0;
	if (validation==1)
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
int main() {
	int pos_x;
	int pos_y;
	const int n=20;
	setTextColor(font_color, back_color);
	system("cls");
	//scanf("%d",&n);
	int state[25][25] = { {0} };//tol arayeh eslsh shvad
	int mohreh_dar_aval[7];
	mohreh_dar_aval[0] = 1;
	mohreh_dar_aval[1] = 2;
	mohreh_dar_aval[2] = 3;
	mohreh_dar_aval[3] = 4;
	mohreh_dar_aval[4] = 5;
	mohreh_dar_aval[5] = 6;
	mohreh_dar_aval[6] = 5;
	start_p1(state,mohreh_dar_aval);
	start_p2(state, mohreh_dar_aval,n);
	printTable(n,state);
	//allegro();	
	pos_x = 1;
	pos_y = 1;
	int turn = 1;
	int pos1_x,pos1_y;
	gotoxy2(pos_x, pos_y);
	do
	{
		if (turn==1)
		{
			/*pos_x = 0;
			pos_y = 2 * n + 1;
			gotoxy2(pos_x, pos_y);
			printf("%c",star);*/
			showStatus(n, 1, 1);
			pos_x = 1;
			pos_y = 1;
			gotoxy2(pos_x, pos_y);
			move_with_keyboard1(n, pos1_x, pos1_y,pos_x,pos_y);
			move_with_keyboard1(n, pos_x, pos_y, pos_x, pos_y);
			if (check(1, pos1_x, pos1_y,pos_x,pos_y,state) == 1 ) {
				update_screen(pos1_x, pos1_y, pos_x, pos_y, star, star_c);
				update_arry(1, pos1_x, pos1_y, pos_x,pos_y,state);
				turn = select_turn(turn, n);
			}
			else
			{
				showStatus(n, 1, 0);
			}
			gotoxy2(pos_x, pos_y);
		}
		if (turn == 2)
		{
			showStatus(n, 2, 1);
			pos_x = 1;
			pos_y = 1;
			gotoxy2(pos_x, pos_y);
			move_with_keyboard1(n, pos1_x, pos1_y, pos_x, pos_y);
			move_with_keyboard1(n, pos_x, pos_y, pos_x, pos_y);
			if (check(2, pos1_x, pos1_y, pos_x, pos_y, state) == 1){
				update_screen(pos1_x, pos1_y, pos_x, pos_y, number, number_c);
				update_arry(2, pos1_x, pos1_y, pos_x, pos_y, state);
				turn = select_turn(turn,n);
			}
			else
			{
				showStatus(n, 2, 0);
			}
			gotoxy2(pos_x, pos_y);
		}
	} while (true);
	
	gotoxy2(0,2*n+3);
	return 0;
}