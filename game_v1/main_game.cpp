#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
//ketab khane hae ezafe
#include"basickFunction.h"
#include"start.h"
#include"role.h"
#include"screan.h"
#include"move.h"

//#include <ctime>
// moshkel (#include <ctime>)  hal she

const int back_color = 15;
const int font_color = 0;
const char star = '*';
const char number = '#';
const int star_c = 4;
const int number_c = 9;
const int leave_camp = 20;
int bazi_count = 0;

int main() {
	//tarig moteghyer ha
	int pos_x=0, pos_y=0;
	//baze tarif n moheme ke (8,24) bashe
	const int n=20;
	int state[25][25] = { {0} };//tol arayeh eslsh shvad
	int mohreh_dar_aval[7];
	int camp[25][25] = { 0 };
	int validmove[2][20] = { -1 };
	int pos1_x, pos1_y;
	int turn=1;
	int i = 0;
	int ps = 0;
	//farakhni tabe start ta tvabe lazem az file start.h ra farakhni konad va mohasebat barayeh shoroe kar angam shvad 
	start(mohreh_dar_aval, state, n,camp);
	//halge angam bazi ke bayad ta zamany ke bazi edameh darad anjam shvad va fela shart etmam nadrad
	do
	{
		//bazikon aval(*)
		if (turn==1)
		{
			showStatus(n, 1, 1);
			pos_x = 1;
			pos_y = 1;
			gotoxy2(pos_x, pos_y);
			//entekhabeh moreh shoro
			move_with_keyboard(n, pos1_x, pos1_y,pos_x,pos_y);
			//motemayez kardan mohre shoro agar vogod dashdeh bashad
			lite(pos1_x,pos1_y,star_c,star,state);
			NormalMove(pos1_x, pos1_y, n, i, state, validmove);
			NormalJump(pos1_x, pos1_y, n, i, state, validmove);
			lite_valid_move(i, validmove);
			gotoxy2(pos_x, pos_y);
			//entekhabeh magsad
			move_with_keyboard(n, pos_x, pos_y, pos_x, pos_y);
			unlite_valid_move(i, validmove);
			// koliyeh ghavanin harkat dar in shart check mishvad(baray 1) 
			// fela barasi inke khane mabda dorst bashad va dar maghsad mohrehi nabashad
			if (check_role(1, pos1_x, pos1_y,pos_x,pos_y,state) == 1 ) {
				update_screen(pos1_x, pos1_y, pos_x, pos_y, star, star_c);
				update_arry(1, pos1_x, pos1_y, pos_x,pos_y,state);
				ps = EndGame(n, camp, state, turn);
				turn = select_turn(turn, n);
			}
			//harekt ghabeleh gaboll nabashad(1)
			else
			{
				//agaar harkat galat bashad mohreh entekhab shodeh ra be halat aval bar mi gardanad va payam monaseb ra chap mikonad
				unlite(pos1_x, pos1_y, star_c, star, state);
				showStatus(n, 1, 0);
			}
		}
		//bazikon dovom(#)
		else if (turn == 2)
		{
			showStatus(n, 2, 1);
			pos_x = 2*n-1;
			pos_y = 2 * n - 1;
			gotoxy2(pos_x, pos_y);
			move_with_keyboard(n, pos1_x, pos1_y, pos_x, pos_y);
			lite(pos1_x,pos1_y,number_c,number, state);
			NormalMove(pos1_x, pos1_y, n, i, state, validmove);
			NormalJump(pos1_x, pos1_y, n, i, state, validmove);
			lite_valid_move(i, validmove);
			gotoxy2(pos_x, pos_y);
			move_with_keyboard(n, pos_x, pos_y, pos_x, pos_y);
			unlite_valid_move(i, validmove);
			// koliyeh ghavanin harkat dar in shart check mishvad(baray 2) 
			// fela barasi inke khane mabda dorst bashad va dar maghsad mohrehi nabashad
			if (check_role(2, pos1_x, pos1_y, pos_x, pos_y, state) == 1){
				update_screen(pos1_x, pos1_y, pos_x, pos_y, number, number_c);
				update_arry(2, pos1_x, pos1_y, pos_x, pos_y, state);
				ps = EndGame(n, camp, state, turn);
				turn = select_turn(turn,n);
			}
			//harekt ghabeleh gaboll nabashad(2)
			else
			{
				unlite(pos1_x, pos1_y, number_c, number, state);
				showStatus(n, 2, 0);
			}
		}
	} while (!ps);
	showStatus(n, ps, 2);
	gotoxy2(0,2*n+3);
	return 0;
}