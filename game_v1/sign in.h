#pragma once
struct amar_player_sign_in
{
	char name[100];
	int total_game;
	int win_game;
	int draw_game;
	int lose_game;
};

void add_player_amar(char name[]) {
	FILE* amar;
	amar = fopen("amar.dat", "ab");
	if (!amar) {
		printf("can\'t add your user amar");
		return;
	}
	amar_player_sign_in player;
	strcpy(player.name, name);
	player.draw_game = 0, player.lose_game = 0, player.win_game = 0, player.total_game = 0;
	fwrite(&player, sizeof(amar_player), 1, amar);
	fclose(amar);
}

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
	add_player_amar(username);
	//sleep();
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

