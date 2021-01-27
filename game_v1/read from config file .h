#include<stdio.h>
#include<string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
struct myfile
{
    int Size=-1;
    int LeaveCampValue=-1;
    int BeadsOrder[8]={0};
    int  ColorPlayer[2]={0};
};
const int White=15;
const int Black=0;
const int Navy_Blue=1;
const int Green=2;
const int Cyan=3;
const int Red=4;
const int Purple=5;
const int Gray=8;
const int Yellow=6;
const int Blue=9;
const int Light_Green=10;
const int Light_Cyan=11;
const int Light_Red=12;
const int Pink=13;
const int Light_Yellow=14;
int rang(char rang[30]){
    char *ret;
    ret =strstr(rang,"white");
    if (ret)
    {
        return White;
    }
    ret =strstr(rang,"black");
    if (ret)
    {
        return Black;
    }
    ret =strstr(rang,"green");
    if (ret)
    {
        return Green;
    }
    ret =strstr(rang,"cyan");
    if (ret)
    {
        return Cyan;
    }
    ret =strstr(rang,"navy blue");
    if (ret)
    {
        return Navy_Blue;
    }
    ret =strstr(rang,"red");
    if (ret)
    {
        return Red;
    }
    ret =strstr(rang,"purple");
    if (ret)
    {
        return Purple;
    }
    ret =strstr(rang,"gray");
    if (ret)
    {
        return Gray;
    }
    ret =strstr(rang,"yellow");
    if (ret)
    {
        return Yellow;
    }
    ret =strstr(rang,"blue");
    if (ret)
    {
        return Blue;
    }
    ret =strstr(rang,"light green");
    if (ret)
    {
        return Light_Green;
    }
    ret =strstr(rang,"light cyan");
    if (ret)
    {
        return Light_Cyan;
    }
    ret =strstr(rang,"light red");
    if (ret)
    {
        return Light_Red;
    }
    ret =strstr(rang,"pink");
    if (ret)
    {
        return Pink;
    }
    ret =strstr(rang,"light yellow");
    if (ret)
    {
        return Light_Yellow;
    }
	return -1;
}

void delet_start_spase(char str[]) {
	while (str[0] == ' ' || str[0] == '\t')
	{
		int i;
		for (i = 1; str[i]; i++)
		{
			str[i - 1] = str[i];
		}
		str[i - 1] = str[i];
	}
}

myfile ReadConfigFile(){
    myfile read_file;
    FILE *config;
    char line_in_file[8][100];
    config=fopen("setting1.txt","rt");
    if (!config) {
        read_file.Size=0;
		printf("can\'t open file");
		return read_file;
	}
    for (int i = 0; i < 8; i++)
    {
        fgets(line_in_file[i],100,config);
		delet_start_spase(line_in_file[i]);
    }
    fclose(config);
    char *ret;
    for (int i = 0; i < 8; i++)
    {
        ret=strstr(line_in_file[i],"Size");
        if (ret)
        {
            read_file.Size=0;
            for (int j = 7; line_in_file[i][j] >= '0' && line_in_file[i][j] <= '9'; j++)
            {
               read_file.Size*=10;
               read_file.Size+=line_in_file[i][j]-48;
            }
            
        }
        else
        {
            ret=strstr(line_in_file[i],"leave_camp_value");
            if (ret)
            {
            read_file.LeaveCampValue=0;
            for (int j = 19; line_in_file[i][j] >= '0' && line_in_file[i][j] <= '9'; j++)
            {
               read_file.LeaveCampValue*=10;
               read_file.LeaveCampValue+=line_in_file[i][j]-48;
            }   
            }
            else
            {
                ret=strstr(line_in_file[i],"Beads_order");
                int arr_count=0;
                if (ret)
                {
                 for (int j = 0; line_in_file[i][j]; j++)
                 {
                  if (line_in_file[i][j] >= '0' && line_in_file[i][j] <= '9')
                  {
                    read_file.BeadsOrder[arr_count]=line_in_file[i][j]-48;
                    arr_count++;                      
                  }
                 }
                }
                else
                {
                 ret=strstr(line_in_file[i],"First_Color");
                 if(ret){
                    read_file.ColorPlayer[0]=rang(line_in_file[i]);
                 }   
                 ret=strstr(line_in_file[i],"Second_Color");
                 if(ret){
                    read_file.ColorPlayer[1]=rang(line_in_file[i]);
                 }  
                }
                
            }   
        }   
    }
return read_file;
}
void SetValueReadConfigFile(int &n,int &First_color,int &Secend_color,int &leave_camp_value ,int Beads_order[7]){
    myfile read=ReadConfigFile();
    n=read.Size;
    First_color=read.ColorPlayer[0];
    Secend_color=read.ColorPlayer[1];
    leave_camp_value=read.LeaveCampValue;
    for(int i=0;i<7;i++)
        Beads_order[i]=read.BeadsOrder[i];
    return;        
}
