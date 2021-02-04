#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include<ctime>

//ketab khane hae ezafe
#include"basickFunction.h"
#include"start.h"
#include"role.h"
#include"screan.h"
#include"main_menu.h"
#include"save_game.h"
#include"puase_menu.h"
#include"move.h"
#include"amar.h"
#include"nahveh_anjam_bazi.h"
#include "AI.h"

#include"my_exit.h"


const int back_color = 15;
const int font_color = 0;
const char star = '*';
const char number = '#';
const int max_valid_move = 50;
int bazi_count = 0;

int main() {
	//fullscreen
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	//set title for console 
	SetConsoleTitle("halma project");
	// adad tasadofi
	srand(time(0));
	char name[100]="";
	if (!menu(name))
		exit(0);
	int pos_x=0, pos_y=0;
	//baze tarif n moheme ke (8,24) bashe
	int n, star_c , number_c, leave_camp;
	int state[25][25] = { {0} };//tol arayeh eslsh shvad
	int mohreh_dar_aval[7];
	int camp[25][25] = { 0 };
	int validmove[2][max_valid_move] = { 0 };
	int recentlymove[4][5] = { 0 };
	int pos1_x, pos1_y;
	int turn=1;
	int i = 0;
	int ps = 0;
	int is_comp = 1;
	//farakhni tabe start ta tvabe lazem az file start.h ra farakhni konad va mohasebat barayeh shoroe kar angam shvad 
	int nahveh = nahveh_bazi(name);
	if (nahveh == 1) {
		start(mohreh_dar_aval, state, n, camp, leave_camp, star_c, number_c);
		is_comp = 0;
	}
	else if (nahveh == 2)
	{
		start(mohreh_dar_aval, state, n, camp, leave_camp, star_c, number_c);
	}
	else {
		ReadSaveGame(state, camp, recentlymove, star_c, number_c, leave_camp, n, turn, bazi_count,is_comp);
		printTable(n, state, star_c, number_c);
	}
		
	//halge angam bazi ke bayad ta zamany ke bazi edameh darad anjam shvad va fela shart etmam nadrad
	do
	{
		//bazikon aval(*)
		if (turn==1)
		{
			showStatus(n, 1, 1,star_c,number_c,name);
			pos_x = 1;
			pos_y = 1;
			gotoxy2(pos_x, pos_y);
			//entekhabeh moreh shoro
			move_with_keyboard(n,1, pos1_x, pos1_y,pos_x,pos_y, recentlymove, star_c, number_c,state,camp,leave_camp,turn,is_comp,name);
			//motemayez kardan mohre shoro agar vogod dashdeh bashad
			lite(pos1_x,pos1_y,star_c,star,state);
			NormalMove(pos1_x, pos1_y, n, i, state, validmove);
			NormalJump(pos1_x, pos1_y, n, i, state, validmove);
			super_jump(pos1_x, pos1_y, n, i, state, validmove);
			lite_valid_move(i, validmove);
			gotoxy2(pos_x, pos_y);
			//entekhabeh magsad
			move_with_keyboard(n,1, pos_x, pos_y, pos_x, pos_y,recentlymove, star_c, number_c, state, camp, leave_camp, turn, is_comp,name);
			unlite_valid_move(i, validmove);
			// koliyeh ghavanin harkat dar in shart check mishvad(baray 1) 
			// fela barasi inke khane mabda dorst bashad va dar maghsad mohrehi nabashad
			if (check_role(1, pos1_x, pos1_y,pos_x,pos_y,state,validmove,i) == 1 ) {
				update_screen(pos1_x, pos1_y, pos_x, pos_y, star, star_c);
				update_arry(1, pos1_x, pos1_y, pos_x,pos_y,state, recentlymove);
				ps = EndGame(n, camp, state, turn,leave_camp);
				turn = select_turn(turn, n);
			}
			//harekt ghabeleh gaboll nabashad(1)
			else
			{
				//agaar harkat galat bashad mohreh entekhab shodeh ra be halat aval bar mi gardanad va payam monaseb ra chap mikonad
				unlite(pos1_x, pos1_y, star_c, star, state);
				showStatus(n, 1, 0, star_c, number_c,name);
			}
		}
		//bazikon dovom(#)
		else if (turn == 2)
		{
			if (is_comp)
			{
				AI_move(pos1_x, pos1_y, pos_x, pos_y, star_c, number_c, n, state, camp, turn, recentlymove, leave_camp,name);
				update_screen(pos1_x, pos1_y, pos_x, pos_y, number, number_c);
				update_arry(2, pos1_x, pos1_y, pos_x, pos_y, state, recentlymove);
				ps = EndGame(n, camp, state, turn, leave_camp);
				turn = select_turn(turn, n);
			}
			else
			{
				showStatus(n, 2, 1, star_c, number_c,name);
				pos_x = 2 * n - 1;
				pos_y = 2 * n - 1;
				gotoxy2(pos_x, pos_y);
				move_with_keyboard(n, 2, pos1_x, pos1_y, pos_x, pos_y, recentlymove, star_c, number_c, state, camp, leave_camp, turn, is_comp,name);
				lite(pos1_x, pos1_y, number_c, number, state);
				NormalMove(pos1_x, pos1_y, n, i, state, validmove);
				NormalJump(pos1_x, pos1_y, n, i, state, validmove);
				super_jump(pos1_x, pos1_y, n, i, state, validmove);
				lite_valid_move(i, validmove);
				gotoxy2(pos_x, pos_y);
				move_with_keyboard(n, 2, pos_x, pos_y, pos_x, pos_y, recentlymove, star_c, number_c, state, camp, leave_camp, turn, is_comp,name);
				unlite_valid_move(i, validmove);
				// koliyeh ghavanin harkat dar in shart check mishvad(baray 2) 
				// fela barasi inke khane mabda dorst bashad va dar maghsad mohrehi nabashad
				if (check_role(2, pos1_x, pos1_y, pos_x, pos_y, state, validmove, i) == 1) {
					update_screen(pos1_x, pos1_y, pos_x, pos_y, number, number_c);
					update_arry(2, pos1_x, pos1_y, pos_x, pos_y, state, recentlymove);
					ps = EndGame(n, camp, state, turn, leave_camp);
					turn = select_turn(turn, n);
				}
				//harekt ghabeleh gaboll nabashad(2)
				else
				{
					unlite(pos1_x, pos1_y, number_c, number, state);
					showStatus(n, 2, 0, star_c, number_c,name);
				}
			}
		}
	} while (!ps);
	showStatus(n, ps, 2, star_c, number_c,name);
	gotoxy2(0,2*n+3);
	return 0;
}