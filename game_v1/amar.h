#pragma once

struct amar_player
{
	char name[100];
	int total_game;
	int win_game;
	int draw_game;
	int lose_game;
};

void copy_my_struct_amar_player(amar_player &copy, amar_player &source) {
	strcpy(copy.name, source.name);
	copy.total_game = source.total_game;
	copy.win_game = source.win_game;
	copy.lose_game = source.lose_game;
	copy.draw_game = source.draw_game;
}

void add_player(char name[]) {
	FILE* amar;
	amar = fopen("amar.dat", "ab");
	if (!amar) {
		printf("can\'t add your user amar");
		return;
	}
	amar_player player;
	strcpy(player.name, name);
	player.draw_game = 0, player.lose_game = 0, player.win_game = 0, player.total_game = 0;
	fwrite(&player, sizeof(amar_player), 1, amar);
	fclose(amar);
}

void chenge_amar(char name[],int halat){
	// 0-->lose / 1-->win / 2-->draw
	FILE* amar;
	amar_player player;
	char* ret;
	amar = fopen("amar.dat", "r+b");
	if (!amar) {
		printf("can\'t add your user amar");
		return;
	}
	fread(&player, sizeof(amar_player), 1, amar);
	while (!feof(amar))
	{
		ret = strstr(name, player.name);
		if (ret)
			break;
		fread(&player, sizeof(amar_player), 1, amar);
	}
	player.total_game++;
	switch (halat)
	{
	case 0:
		player.lose_game++;
		break;
	case 1:
		player.win_game++;
		break;
	case 2:
		player.draw_game++;
		break;
	}

	fseek(amar, -1L * (long int)sizeof(amar_player), SEEK_CUR);
	fwrite(&player, sizeof(amar_player), 1, amar);
	fclose(amar);
}

amar_player search_best_player() {
	FILE* amar;
	amar_player max_player, player;
	max_player.draw_game = 0, max_player.lose_game = 0, max_player.total_game = 0, max_player.win_game = 0;
	amar = fopen("amar.dat", "rb");
	if (!amar) {
		printf("can\'t open file\n");
		return max_player;
	}
	fread(&player, sizeof(amar_player), 1, amar);
	while (!feof(amar))
	{
		if ((player.win_game < max_player.win_game));
		else if (player.win_game == max_player.win_game && player.draw_game < max_player.draw_game);
		else if (player.win_game == max_player.win_game && player.draw_game == max_player.draw_game && player.lose_game > max_player.lose_game);
		else
		{
			// agar har kom az shart hayeh bala bar garar bashad niyaz be gabegayy nist
			copy_my_struct_amar_player(max_player, player);
		}
		fread(&player, sizeof(amar_player), 1, amar);
	}
	return max_player;
}

amar_player search_worst_player() {
	FILE* amar;
	amar_player min_player, player;
	min_player.draw_game = 0, min_player.lose_game = 0, min_player.total_game = 0, min_player.win_game = 0;
	amar = fopen("amar.dat", "rb");
	if (!amar) {
		printf("can\'t open file\n");
		return min_player;
	}
	fread(&player, sizeof(amar_player), 1, amar);
	while (!feof(amar))
	{
		if (player.lose_game < min_player.lose_game);
		else if (player.lose_game == min_player.lose_game && player.draw_game > min_player.draw_game);
		else if (player.lose_game == min_player.lose_game && player.draw_game == min_player.draw_game && player.win_game > min_player.win_game);
		else
		{
			// agar har kom az shart hayeh bala bar garar bashad niyaz be gabegayy nist
			copy_my_struct_amar_player(min_player, player);
		}
		fread(&player, sizeof(amar_player), 1, amar);
	}
	return min_player;
}

amar_player search_my_amar(char name[]) {
	FILE* amar;
	amar_player player;
	player.draw_game = 0, player.lose_game = 0, player.total_game = 0, player.win_game = 0;
	char* ret;
	amar = fopen("amar.dat", "r+b");
	if (!amar) {
		printf("can\'t add your user amar");
		return player;
	}
	fread(&player, sizeof(amar_player), 1, amar);
	while (!feof(amar))
	{
		ret = strstr(name, player.name);
		if (ret)
			break;
		fread(&player, sizeof(amar_player), 1, amar);
	}
	return player;
}

void print_worst_and_best_player(char name[]) {
	amar_player max_player, min_player,I;
	setTextColor(0, 15);
	system("cls");
	max_player = search_best_player();
	min_player = search_worst_player();
	I = search_my_amar(name);
	printf("I:\n");
	printf("name: %s  total: %d  win: %d  draw: %d  lose: %d\n",I.name, I.total_game, I.win_game, I.draw_game, I.lose_game);
	printf("===============================================\n");
	printf("best player:\n");
	printf("name: %s  total: %d  win: %d  draw: %d  lose: %d\n", max_player.name, max_player.total_game, max_player.win_game, max_player.draw_game, max_player.lose_game);
	printf("===============================================\n");
	printf("worst player:\n");
	printf("name: %s  total: %d  win: %d  draw: %d  lose: %d\n", min_player.name, min_player.total_game, min_player.win_game, min_player.draw_game, min_player.lose_game);
	printf("===============================================\n");
	printf("please enter one key to go back");
	char* ch = new char;
	*ch = _getch();
	delete ch;
	return;
}