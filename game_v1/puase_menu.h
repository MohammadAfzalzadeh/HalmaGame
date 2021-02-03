#pragma once
int puase_menu_print() {
	setTextColor(0, 15);
	system("cls");
	printf("chose one item for contineu\n");
	printf("1)end game with saving\n");
	printf("2)end game without saving\n");
	return(move_with_keyboard_menu(2));
}

void puase_menu(int size, int state[][25], int camp[][25], int recentlymove[][5], int player1_color, int player2_color, int leave_camp_value, int turn, int bazi_count) {
	switch (puase_menu_print())
	{
	case 1:
		saving_game(size, state, camp, recentlymove, player1_color, player2_color, leave_camp_value, turn, bazi_count);
		exit(1);
	case 2:
		exit(1);

	default:
		break;
	}
}