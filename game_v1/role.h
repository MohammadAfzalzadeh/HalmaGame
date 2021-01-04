#pragma once
extern int bazi_count;
extern const int leave_camp;
// check mi konad ke dar arry dar magsad aya khali hast aghar khali bashad 1 ra bar mighardanad vaghar na 0 ra bar mi gardanad
int barrasi_magsad(int x, int y, const int state[][25]) {
	x--;
	y--;
	x /= 2;
	y /= 2;
	if (state[x][y] == 0)
		return 1;
	return 0;
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
int check_role(int player, int pos1_x, int pos1_y, int x, int y, const int state[][25]) {
	if (barrasi_magsad(x, y, state) == 1 && barasi_mada(player, pos1_x, pos1_y, state) == 1)
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
