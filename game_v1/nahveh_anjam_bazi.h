#pragma once

int nahveh_bazi(char name[]) {
	while (1)
	{
		setTextColor(font_color, back_color);
		system("cls");
		int answer, menu_count;
		if (IsExistSaveFile()) {
			printf("yek mored ra entekhab konid\n");
			printf("1)bazi gadid vs human\n");
			printf("2)bazi gadid vs computer\n");
			printf("3)bazi ba save shodeh\n");
			printf("4)show my statistics and best statistics and worst statistics\n");
			printf("5)EXIT");
			menu_count = 5;
			answer = move_with_keyboard_menu(menu_count);
		}
		else
		{
			printf("yek mored ra entekhab konid\n");
			printf("1)bazi gadid vs human\n");
			printf("2)bazi gadid vs computer\n");
			printf("3)show my statistics and best statistics and worst statistics\n");
			printf("4)EXIT");
			menu_count = 4;
			answer = move_with_keyboard_menu(menu_count);
		}
		if (answer == menu_count) {
			gotoxy2(0, menu_count + 1);
			exit(0);
		}
		if (answer == menu_count - 1) {
			print_worst_and_best_player(name);
		}
		else
			return answer;
	}
}
