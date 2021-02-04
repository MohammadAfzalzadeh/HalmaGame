#pragma once

void read_pas(char pass[]){
    char read_char;
    int count_char=0;
	read_char = _getch();
	
    while (read_char!=13)
    {
        if((read_char >='A'&& read_char <= 'Z')||(read_char >='a'&& read_char <= 'z') ||(read_char >='0'&& read_char <= '9') ){
            printf("*");
			if(read_char=='0')
				pass[count_char]=read_char;
			else
				pass[count_char] = read_char-'0';
            count_char++;
			read_char = _getch();
        }
        /* 
        else if(read_char==8||read_char==127||read_char=='\b'){
            printf("\a");
            Etc_ch=getch();
            read_char='\0';
        }
        else
        {
            read_char='\0';
            read_char=getch();
           
        }
        */
    }  
	pass[count_char] = '\0';
	printf("\n");
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
    system("cls");
    printf("                     Log In page    \n");
    //بعدا حواست به این باشه که ممکنه نام کاربری(یا رمز عبور) از آرایه بیرون بزنه
	char username[100];
    char password[100];
    printf("enter your username:\n");
    gets_s(username);
    printf("enter your password:\n");
    read_pas(password);
    int s=search_in_file(username,password);
	if (s)
		strcpy(name, username);
    //sleep();
	return s;    
}


