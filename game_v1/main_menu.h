#pragma once

#include<stdio.h>
#include <windows.h>
#include <conio.h>

#include"log in.h"
#include"sign in.h"
#include"basickFunction.h"

//
//void sleep(unsigned int mseconds=10000) {
//    clock_t goal = mseconds + clock();
//    while (goal > clock());
//}


void arrow_key_menu(char ch,int &y){
    if (ch == 0 || ch == 224)
		ch = _getch();
	else if (ch == 80) {
		/*payyn*/
		y++;
	}

	else if (ch == 72) {
		/*bala*/
		y --;
	}
}
void WS_key_menu(char ch,int &y){
    if(ch=='W' || ch=='w')
        y--;
    if(ch=='S' || ch=='s')
        y++;    
}
void check_cursor(int &y,int ye,int max_move){
    if(y < 1 || y > max_move)
        y=ye;
}
int move_with_keyboard_menu(){
    int y=1,ye=1;
    gotoxy2(0, y);
    char ch;
	do
	{
        ye=y;
		ch = _getch();
		arrow_key_menu(ch , y);
		WS_key_menu(ch, y);
		check_cursor(y,ye,3);
		gotoxy2(0, y);
	} while (ch != 13);
    return y;
}
int menu(){
	while (1)
	{
		setTextColor(font_color, back_color);
		system("cls");
		printf("baraye vrood be bazi az yek ravesh zir estefadeh konid\n1)Log In\n2)Sign In\n3)EXIT");
		int answer = move_with_keyboard_menu();

		if (answer == 1)
		{
			int log = log_in();
			if (log)
				return 1;

		}
		else if (answer == 2) {
			sign_in();
		}
		else
			return 0;
	}   
}

