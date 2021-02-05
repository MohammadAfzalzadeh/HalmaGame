#pragma once
const int pass = 1;
const int user = 2;

int read_pas_user(char string[],int noe){
	//noe ==1  pass
	//noe ==2  user
    char read_char;
    int count_char=0;
	read_char = _getch();
	
    while (read_char!=13)
    {
        if((read_char >='A'&& read_char <= 'Z')||(read_char >='a'&& read_char <= 'z') ||(read_char >='0'&& read_char <= '9') ){
			if (noe == 1) {
				printf("*");
				if (read_char == '0')
					string[count_char] = read_char;
				else
					string[count_char] = read_char - '0';
			}
			else {
				printf("%c",read_char);
				string[count_char] = read_char;
			}
            count_char++;
			if (count_char > 30) {
				printf("\n max of username and password is 30 caracter\n");
				//sleep()
				return 0;
			}
        }
        else if(read_char==0||read_char==127 || read_char==-32){
            read_char=_getch();
            read_char='\0';
        }
		read_char = _getch();
    }  
	string[count_char] = '\0';
	printf("\n");
	return 1;
}
int search_in_file(char username[],char password[]){
    FILE * search_acount;
    char read[100];
    char * ret;
    search_acount=fopen("acount.dat","rb");
    if(!search_acount){
        printf("can not connet to file to check your user\n");
        return 0;
    }
    fread(read, sizeof(char), 100, search_acount);       
    while (!feof(search_acount))
    {
        ret=strstr(read,username);
        if(ret){
            fread(read, sizeof(char), 100, search_acount);
            ret=strstr(read,password);
            if(ret){
            	printf("your user found\n");
				fclose(search_acount);
            	return 1;
			}
               
        }
        //این خواندن برای مشابه نبودن پسورد نفر قبل با یوزر نفری دیگر
        fread(read, sizeof(char), 100, search_acount);
        // برای نفر بعد
        fread(read, sizeof(char), 100, search_acount);
    }
    
    fclose(search_acount);
    printf("your user not found\n");
    return 0;
}

int log_in(char name[]){
	char username[100];
	char password[100];
	int ps = 1;
	while (1)
	{
		system("cls");
		printf("                     Log In page    \n");
		printf("enter your username:\n");
		if (read_pas_user(password, user))
			ps = 2;
		printf("enter your password:\n");
		if (read_pas_user(password,pass) && ps == 2)
			ps = 0;
		else
			ps = 1;

	}    
	int s = search_in_file(username, password);
	if (s)
		strcpy(name, username);
	//sleep();
	return s;
}


