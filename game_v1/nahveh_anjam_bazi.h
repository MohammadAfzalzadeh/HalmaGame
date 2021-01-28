#pragma once

int nahveh_bazi() {
		setTextColor(font_color, back_color);
		system("cls");
		int answer,menu_count;
		if (IsExistSaveFile()) {
			printf("yek mored ra entekhab konid\n");
			printf("1)bazi gadid\n");
			printf("2)bazi ba save shodeh\n");
			printf("3)EXIT");
			menu_count = 3;
			answer = move_with_keyboard_menu(menu_count);
		}
		else
		{
			printf("yek mored ra entekhab konid\n");
			printf("1)bazi gadid\n");
			printf("2)EXIT");
			menu_count = 2;
			answer = move_with_keyboard_menu(menu_count);
		}
		if (answer == menu_count) {
			gotoxy2(0, menu_count + 1);
			exit(0);
		}
		return answer;
}
