#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

void gotoXY(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

char c=205;

void border()
{
    int i;

    for(i=16;i<=117;i++) //Top and Bottom Border line
    {
        gotoXY(i,3);
        printf("%c",205); //puts(style);
        gotoXY(i,45);
        printf("%c",205); //puts(style);
    }

    for(i=3;i<=45;i++) //Left and Right Border Line
    {
        gotoXY(18, i);
        printf("%c",186); //puts(style);
        gotoXY(115, i);
        printf("%c",186); //puts style;
    }
}

void get(char name[])
{
    cin.getline(name,40);
    name[strlen(name)]='\0';
}

void textbox(int x,int y)
{
    x=x>78?78:x;
    y=y>50?45:y;
    for(int i=x;i<x+40;i++)   //x-axis
    {
        gotoXY(i,y);
        printf("%c",45);


        gotoXY(i,y+2);
        printf("%c",45);
    }
    for(int i=y;i<=y+2;i++) //y-axis
    {
        gotoXY(x,i);
        printf("%c",'.');

        gotoXY(x+40,i);
        printf("%c",'.');
    }
}

int stringToInt(void)
{
    char ch,age[30];
    int i=0,agei=0;
//    cin>>age;
//    age[strlen(age)]='\0';
//    cout<<age;
    //cout<<"\n\n     Enter your age : ";
    while(1)
    {
        ch=getch();
        if(ch>=48&&ch<=57)
        {
            age[i]=ch;
            cout<<age[i];
            i++;
        }
        else if(ch==8)
        {
            i--;
            cout<<char(8);
            cout<<" ";
            cout<<char(8);
            age[i]='\0';
            continue;
        }
        else if(ch==13)
        {
            age[i]='\0';
            break;
        }
        else
            continue;
    }

    i=0;
    while(i<strlen(age))
    {
        agei=agei*10+(age[i]-'0');
        i++;
    }

    //cout<<"\n     Age in integer : "<<agei;
    return agei;
}

float stringToFloat(void)
{
    char ch,salary[30];
    int i=0;
    float salaryi=0,multiplier=0.1;
//    cin>>age;
//    age[strlen(age)]='\0';
//    cout<<age;
    //cout<<"\n\n     Enter your age : ";
    while(1)
    {
        ch=getch();
        if(ch>=48&&ch<=57||ch==46)
        {
            salary[i]=ch;
            cout<<salary[i];
            i++;
        }
        else if(ch==8)
        {
            i--;
            cout<<char(8);
            cout<<" ";
            cout<<char(8);
            salary[i]='\0';
            continue;
        }
        else if(ch==13)
        {
            salary[i]='\0';
            break;
        }
        else
            continue;
    }

    i=0;
    while(i<strlen(salary))
    {
        if(salary[i]!=46)
        {
            salaryi=salaryi*10+(salary[i]-'0');
            i++;
        }
        else
        {
            i++;
            while(i<strlen(salary))
            {
                salaryi=salaryi+(salary[i]-'0')*multiplier;
                multiplier*=0.1;
                i++;
            }
        }
    }

    //cout<<"\n     Age in integer : "<<agei;
    return salaryi;
}

