#pragma once
extern int bazi_count;
extern const int leave_camp;
// check mi konad ke dar arry dar magsad aya khali hast aghar khali bashad 1 ra bar mighardanad vaghar na 0 ra bar mi gardanad
int barrasi_magsad(int pos_x, int pos_y, const int state[][25],const int validmove[][20],int i) {
	int x = 0, y = 0;
	PosInScreanToArry(pos_x, pos_y, x, y);
	for (int j = 0; j < i; j++)
	{
		if (validmove[0][j] == x && validmove[1][j] == y)
			return 1;
	}
	return 0;
	/*x--;
	y--;
	x /= 2;
	y /= 2;
	if (state[x][y] == 0)
		return 1;
	return 0;*/
}
// dar sorat farakoni nobat ra avaz mikonad
int select_turn(int turn, int n) {
	//static int bazi_count = 0;
	gotoxy2(0, 2 * n + 2);
	printf("              ");
	bazi_count++;
	if (turn == 1)
		return 2;
	return 1;
}
// check mi konad ke dar arry dar mabda aya mohreie hast aghar bashad 1 ra bar mighardanad vaghar na 0 ra bar mi gardanad
int barasi_mada(int player, int pos1_x, int pos1_y, const int state[][25]) {
	pos1_x = (pos1_x - 1) / 2;
	pos1_y = (pos1_y - 1) / 2;
	if (state[pos1_x][pos1_y] == player)
		return 1;
	return 0;
}
//check mikonad ke aya gavanin harkat dorost hast ya na(fela barasi mabda va magsad)
int check_role(int player, int pos1_x, int pos1_y, int x, int y, const int state[][25],const int validmove[][20],int i) {
	if (barrasi_magsad(x, y, state,validmove,i) == 1 && barasi_mada(player, pos1_x, pos1_y, state) == 1)
		return 1;
	return 0;
}
//barasi inke kasi dar khane khod nabashad
//bazgasht( 0 => hichi to nist//1=> 1 bakhteh//2=> 2 bakhteh//3=> hardo bakhtan)
// in tabe khna tar shavad///
int LeaveCampCheck(int n,int player, const int camp[][25], int state[][25]) {
	if (bazi_count < leave_camp - 1)
		return 0;
	int a , b ;
	if (player == 1) {
		a = n;
		b = 7;
	}
	else
	{
		b = n;
		a = 7;
	}
	for (int i = n-a; i < b ; i++)
	{
		for (int j = n-a; j < b ; j++)
		{
			if (camp[i][j] == player && state[i][j] == player) {
				return 1;
			}
				
		}
	}
	return 0;
}
//barasi inke kasi(player) vardeh khane harif shode nafar vared shode ra barmigardanad
// in tabe khna tar shavad///
int VrodBeKhaneHrif(int player, const int state[][25], const int camp[][25],int n) {
	int harif,a,b;
	if (player == 1)
	{
		harif = 2;
		a = 7;
		b = n;
	}	
	else
	{
		harif = 1;
		a = n;
		b = 7;
	}
	for (int i = n-a; i < b; i++)
	{
		for (int j = n-a; j < b; j++)
		{
			if (camp[i][j] == harif && state[i][j] != player) {
				return 0;
			}
		}
	}
	return 1;
}
// barasi inke bazi tamam shode ya na
//return(barandeh or 0 or 3 tasavi);
int EndGame(int n, const int camp[][25], int state[][25], int player) {
	if (VrodBeKhaneHrif(player,state,camp,n)==1 )
		return player;
	int leave1 = LeaveCampCheck(n, 1, camp, state);
	int leave2 = LeaveCampCheck(n, 2, camp, state);
	if (leave1) {
		if (leave2)
			return 3;
		else
			return 2;
	}
	else
	{
		if (leave2)
			return 1;
		else
			return 0;
	}
}
// kod hae marbot be normal jump &&&&&& normal move tamiz shavad 
// moteghayer ha khosh nam shvand
// az tabe  is_x_y_in_table(int x, int y ,int n)--> vojod in nogteh dar jadval estefadeh shvad
void NormalMove (int pos_x, int pos_y,int n, int &i, const int state[][25], int validmove[][20]) {
	//tabdil pos_x va pos_y be x va y dar gadval
	int x=0, y=0;
	i = 0;
	PosInScreanToArry(pos_x, pos_y, x, y);
	//rast
	x++;
	if (x >= 0 && x < n) {
		if (state[x][y] == 0) {
			validmove[0][i] = x;
			validmove[1][i] = y;
			i++;
		}
	}
	x--;
	//bala
	y--;
	if (y >= 0 && y < n) {
		if (state[x][y] == 0) {
			validmove[0][i] = x;
			validmove[1][i] = y;
			i++;
		}
	}
	y++;
	//chap
	x--;
	if (x >= 0 && x < n) {
		if (state[x][y] == 0) {
			validmove[0][i] = x;
			validmove[1][i] = y;
			i++;
		}
	}
	x++;
	//pain
	y++;
	if (y >= 0 && y < n) {
		if (state[x][y] == 0) {
			validmove[0][i] = x;
			validmove[1][i] = y;
			i++;
		}
	}
	y--;
	//bala rast
	y--;
	x++;
	if (x >= 0 && x < n && y >= 0 && y < n) {
		if (state[x][y] == 0) {
			validmove[0][i] = x;
			validmove[1][i] = y;
			i++;
		}
	}
	y++;
	x--;
	//bala chap
	y--;
	x--;
	if (x >= 0 && x < n && y >= 0 && y < n) {
		if (state[x][y] == 0) {
			validmove[0][i] = x;
			validmove[1][i] = y;
			i++;
		}
	}	
	y++;
	x++;
	///paien rast
	x++;
	y++;
	if (x >= 0 && x < n && y >= 0 && y < n) {
		if (state[x][y] == 0) {
			validmove[0][i] = x;
			validmove[1][i] = y;
			i++;
		}
	}
	x--;
	y--;
	//paein chap
	y++;
	x--;
	if (x >= 0 && x < n && y >= 0 && y < n) {
		if (state[x][y] == 0) {
			validmove[0][i] = x;
			validmove[1][i] = y;
			i++;
		}
	}
	x++;
	y--;
}
void NormalJump (int pos_x, int pos_y,int n, int &i, const int state[][25], int validmove[][20]) {
	//tabdil pos_x va pos_y be x va y dar gadval
	int x = 0, y = 0;
	PosInScreanToArry(pos_x, pos_y, x, y);
	//rast
	x++;
	if (x >= 0 && x < n) {
		if (state[x][y] != 0 && state[x+1][y]==0 && is_x_y_in_table(x+1,y,n)) {
			validmove[0][i] = x+1;
			validmove[1][i] = y;
			i++;
		}
	}
	x--;
	//chap
	x--;
	if (x >= 0 && x < n) {
		if (state[x][y] != 0 && state [x-1][y]==0 && is_x_y_in_table(x - 1, y, n)) {
			validmove[0][i] = x - 1;
			validmove[1][i] = y;
			i++;
		}
	}
	x++;
	//bala
	y--;
	if (y >= 0 && y < n) {
		if (state[x][y] != 0 && state[x][y-1]==0 && is_x_y_in_table(x , y - 1, n)) {
			validmove[0][i] = x;
			validmove[1][i] = y-1;
			i++;
		}
	}
	y++;
	//payin
	y++;
	if (y >= 0 && y < n) {
		if (state[x][y] != 0 && state[x][y+1]==0 && is_x_y_in_table(x , y + 1, n)) {
			validmove[0][i] = x;
			validmove[1][i] = y+1;
			i++;
		}
	}
	y--;
	//payin rast
	x++;
	y++;
	if (x >= 0 && x < n && y >= 0 && y < n) {
		if (state[x][y] != 0 && state[x+1][y+1]==0 && is_x_y_in_table(x + 1, y+1, n)) {
			validmove[0][i] = x+1;
			validmove[1][i] = y + 1;
			i++;
		}
	}
	x--;
	y--;
	//payin chap
	x--;
	y++;
	if (x >= 0 && x < n && y >= 0 && y < n) {
		if (state[x][y] != 0 && state[x-1][y+1]==0 && is_x_y_in_table(x - 1, y + 1, n)) {
			validmove[0][i] = x - 1;
			validmove[1][i] = y + 1;
			i++;
		}
	}
	x++;
	y--;
	// bala rast
	x++;
	y--;
	if (x >= 0 && x < n && y >= 0 && y < n) {
		if (state[x][y] != 0 && state[x+1][y-1]==0 && is_x_y_in_table(x + 1, y-1, n)) {
			validmove[0][i] = x + 1;
			validmove[1][i] = y - 1;
			i++;
		}
	}
	x--;
	y++;
	//bala chap
	x--;
	y--;
	if (x >= 0 && x < n && y >= 0 && y < n) {
		if (state[x][y] != 0 && state[x-1][y-1]==0 && is_x_y_in_table(x - 1, y - 1, n)) {
			validmove[0][i] = x - 1;
			validmove[1][i] = y - 1;
			i++;
		}
	}
	x++;
	y++;
}
int tasavi_khas() {
	return 0;
}
void super_jump(int pos_x, int pos_y, int n, int& i, const int state[][25], int validmove[][20]) {
	int x = 0, y = 0;
	PosInScreanToArry(pos_x, pos_y, x, y);
	//bala
	//paein
	//rast
	//chap
	//bala rast
	//bala chap
	//paein rast
	//paein chap
}
