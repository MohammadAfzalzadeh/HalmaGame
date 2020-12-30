#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


#include"basickFunction.h"
#include"start.h"
#include"screan.h"
#include"role.h"
#include"move.h"

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

int main() {
	int pos_x=0, pos_y=0;
	const int n=20;
	int state[25][25] = { {0} };//tol arayeh eslsh shvad
	int mohreh_dar_aval[7];
	int pos1_x, pos1_y;
	int turn=1;
	start(mohreh_dar_aval, state, n);
	do
	{
		if (turn==1)
		{
			showStatus(n, 1, 1);
			pos_x = 1;
			pos_y = 1;
			gotoxy2(pos_x, pos_y);
			move_with_keyboard1(n, pos1_x, pos1_y,pos_x,pos_y);
			lite(pos1_x,pos1_y,star_c,star);
			move_with_keyboard1(n, pos_x, pos_y, pos_x, pos_y);
			if (check_role(1, pos1_x, pos1_y,pos_x,pos_y,state) == 1 ) {
				update_screen(pos1_x, pos1_y, pos_x, pos_y, star, star_c);
				update_arry(1, pos1_x, pos1_y, pos_x,pos_y,state);
				turn = select_turn(turn, n);
			}
			else
			{
				showStatus(n, 1, 0);
			}
		}
		else if (turn == 2)
		{
			showStatus(n, 2, 1);
			pos_x = 2*n-1;
			pos_y = 2 * n - 1;
			gotoxy2(pos_x, pos_y);
			move_with_keyboard1(n, pos1_x, pos1_y, pos_x, pos_y);
			lite(pos1_x,pos1_y,number_c,number);
			move_with_keyboard1(n, pos_x, pos_y, pos_x, pos_y);
			if (check_role(2, pos1_x, pos1_y, pos_x, pos_y, state) == 1){
				update_screen(pos1_x, pos1_y, pos_x, pos_y, number, number_c);
				update_arry(2, pos1_x, pos1_y, pos_x, pos_y, state);
				turn = select_turn(turn,n);
			}
			else
			{
				showStatus(n, 2, 0);
			}
		}
	} while (true);
	
	gotoxy2(0,2*n+3);
	return 0;
}