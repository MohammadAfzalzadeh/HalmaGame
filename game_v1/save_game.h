#pragma once
const int max_arr = 25;
void saving_game(int size,int state[][max_arr],int camp[][max_arr], int recentlymove[][5],int player1_color, int player2_color,int leave_camp_value,int turn,int bazi_count) {
	FILE* outfile;
	outfile = fopen("save_game.dat", "wb");
	if (!outfile)
	{
		printf("I can\'t save game !!");
		return;
	}
	// write size
	fwrite(&size, sizeof(int), 1, outfile);
	// write state in file
	for (int i = 0; i < max_arr; i++)
	{
		fwrite(&state[i], sizeof(int),max_arr,outfile);
	}
	// write camp in file
	for (int i = 0; i < max_arr; i++)
	{
		fwrite(&camp[i], sizeof(int), max_arr, outfile);
	}
	// write recentlymove in file
	for (int i = 0; i < 4; i++)
	{
		fwrite(&recentlymove[i], sizeof(int), 5, outfile);
	}
	// write players_color
	fwrite(&player1_color, sizeof(int), 1, outfile);
	fwrite(&player2_color, sizeof(int), 1, outfile);
	//write leave_camp_value
	fwrite(&leave_camp_value, sizeof(int), 1, outfile);
	//write turn and bazi count
	fwrite(&turn, sizeof(int), 1, outfile);
	fwrite(&bazi_count, sizeof(int), 1, outfile);
	fclose(outfile);
	printf("the game saved :)");
	return;
}

int IsExistSaveFile() {
	FILE* infile;
	infile = fopen("save_game.dat", "rb");
	if (!infile) {
		return 0;
	}
	int size;
	fread(&size, sizeof(int), 1, infile);
	fclose(infile);
	if (size > 0 && size < 22)
		return 1;
	return 0;
}

void ReadSaveGame(int state[][25], int camp[][25], int recentlymove[][5], int &player1_color, int &player2_color, int &leave_camp_value, int &size, int &turn, int &bazi_count) {
	FILE* infile;
	infile = fopen("save_game.dat", "rb");
	if (!infile) {
		printf("I can\'t open save game !!");
		return ;
	}
	// write size
	fread(&size, sizeof(int), 1, infile);
	// write state in file
	for (int i = 0; i < max_arr; i++)
	{
		fread(&state[i], sizeof(int), max_arr, infile);
	}
	// write camp in file
	for (int i = 0; i < max_arr; i++)
	{
		fread(&camp[i], sizeof(int), max_arr, infile);
	}
	// write recentlymove in file
	for (int i = 0; i < 5; i++)
	{
		fread(&recentlymove[i], sizeof(int), 5, infile);
	}
	// write players_color
	fread(&player1_color, sizeof(int), 1, infile);
	fread(&player2_color, sizeof(int), 1, infile);
	//write leave_camp_value
	fread(&leave_camp_value, sizeof(int), 1, infile);
	//write turn and bazi count
	fread(&turn, sizeof(int), 1, infile);
	fread(&bazi_count, sizeof(int), 1, infile);
	fclose(infile);
}
