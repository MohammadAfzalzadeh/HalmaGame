#pragma once
//#include"../basickFunction.h"
//#include"log in.h"
//#include"main_menu.cpp"
/*
void read_pas(char pass[]){
    char read_char;
    int count_char=0;
    read_char=getch();
    while (read_char!=13)
    {
        printf("*");
        pass[count_char]=read_char;
        count_char++;
        read_char=getch();
    }  
	printf("\n");
}
*/
/*
void sleep(unsigned int mseconds=10000) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
*/
int apend_to_file(char username[],char password[]){
    FILE * add_acount;
    add_acount=fopen("acount.dat","ab");
    if(!add_acount){
        printf("can not connet to file to add your user\n");
        return 0;
    }
    fwrite(username, sizeof(char), 100, add_acount) ; 
    fwrite(password, sizeof(char), 100, add_acount) ;        
    fclose(add_acount);
    printf("your user added\n");
	//sleep();
   // menu();
   // log_in();
	return 1;
}

int sign_in(){
    system("cls");
    printf("                     Sign In page    \n");
    //بعدا حواست به این باشه که ممکنه نام کاربری(یا رمز عبور) از آرایه بیرون بزنه
    char username[100];
    char password[100];
    printf("enter your username:\n");
    gets_s(username);
    printf("enter your password:\n");
    read_pas(password);
	int apend = apend_to_file(username, password);
	return(apend);
}

