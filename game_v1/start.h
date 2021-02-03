#pragma once
#include"read from config file .h"
extern const int back_color, font_color;
//chap jadval bazi dar val baestefadeh az por shodan arry
void printTable(int n, int state[][25],int First_color,int second_color) {
	int i, j;
	system("cls");
	for (i = 0; i <= n; i++)
	{
		setTextColor(0, 15);
		for (j = 0; j <= n; j++)
		{
			setTextColor(0, 15);
			if (i == 0) {
				if (j == 0) { printf("%c", 201); }
				else if (j == n) { printf("%c", 187); }
				else { printf("%c", 203); }
				if (j != n) printf("%c", 205);
			}
			else if (i == n) {
				if (j == 0) { printf("%c", 200); }
				else if (j == n) { printf("%c", 188); }
				else { printf("%c", 202); }
				if (j != n) printf("%c", 205);
			}
			else
			{
				if (j == 0) { printf("%c", 204); }
				else if (j == n) { printf("%c", 185); }
				else { printf("%c", 206); }
				if (j != n) printf("%c", 205);
			}
		}
		printf("\n");
		if (i != n) {
			for (j = 0; j <= n; j++)
			{
				printf("%c", 186);
				//mohreh ha
				if (state[j][i] == 1) {
					setTextColor(First_color, 15);
					printf("*");
				}
				else if (state[j][i] == 2) {
					setTextColor(second_color, 15);
					printf("#");
				}
				else {//state[j][i]==0
					setTextColor(0, 15);
					printf(" ");
				}
				setTextColor(0, 15);
			}

			printf("\n");
		}
	}
}
// baestefadeh az maghadir arry mohreh dar avl ke dar tabe start set mishe arry asli(state) ra bary nafar avl por mikonad
void start_p1(int state[][25], int mohreh_dar_aval[7]) {
	for (int i = 0; i < 7; i++)
	{
		int screw_count = 0;
		int space_to_full = (i + 1) - mohreh_dar_aval[i];
		space_to_full /= 2;
		int null_count = 0;
		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{

				if (x + y == i && screw_count < mohreh_dar_aval[i])
				{
					if (null_count < space_to_full)
						null_count++;
					else
					{
						state[x][y] = 1;
						screw_count++;
					}

				}
			}
		}
	}
}
// baestefadeh az maghadir arry mohreh dar avl ke dar tabe start set mishe arry asli(state) ra bary nafar dowom por mikonad
void start_p2(int state[][25], int mohreh_dar_aval[7], int n) {
	for (int i = 0; i < 7; i++)
	{
		int screw_count = 0;
		int space_to_full = (i + 1) - mohreh_dar_aval[i];
		space_to_full /= 2;
		int null_count = 0;
		for (int x = n - 1; x >= 0; x--)
		{
			for (int y = n - 1; y >= 0; y--)
			{
				if (x + y == ((2 * n) - 2 - i) && screw_count < mohreh_dar_aval[i])
				{
					if (null_count < space_to_full)
						null_count++;
					else
					{
						state[x][y] = 2;
						screw_count++;
					}

				}
			}
		}
	}
}
//copy kardan state royeh camp
void CopyToCamp(const int state[][25], int camp[][25],int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j= 0; j < n; j++)
		{
			camp[i][j] = state[i][j];
		}
	}
}
// eghdatat avaliyeh bazi(1-rang safhe bazi 2-farakhani start_p1 & start_p2 3-print table 4-CopyToCamp )
void start(int mohreh_dar_aval[], int state[][25],int &n,int camp[][25],int &leave_camp_value,int &First_color, int &Secend_color) {
	setTextColor(font_color, back_color);
	system("cls");
	SetValueReadConfigFile(n, First_color, Secend_color, leave_camp_value, mohreh_dar_aval);
	/*
	mohreh_dar_aval[0] = 1;
	mohreh_dar_aval[1] = 2;
	mohreh_dar_aval[2] = 3;
	mohreh_dar_aval[3] = 4;
	mohreh_dar_aval[4] = 5;
	mohreh_dar_aval[5] = 6;
	mohreh_dar_aval[6] = 5;
	*/
	start_p1(state, mohreh_dar_aval);
	start_p2(state, mohreh_dar_aval, n);
	printTable(n, state,First_color,Secend_color);
	CopyToCamp(state, camp,n);
}