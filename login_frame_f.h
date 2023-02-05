#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<cstring>

using namespace std;

void get(char name[]);
void gotoXY(int,int);
void border(void);
void textbox(int,int);

char username[30],password[30];

void changeUsername(void)
{
    system("cls");
    border();

    gotoXY(50,5);
    cout<<"Username Changing Window!!!";

    gotoXY(30,15);
    cout<<"Enter the new username : ";
    textbox(60,14);
    gotoXY(62,15);
    get(username);

    gotoXY(30,20);
    cout<<"Username Changed Successfully...";

    gotoXY(30,25);
    cout<<"Enter to return back to menu window.";
    getch();

    FILE *fp;
    fp=fopen("passuser.txt","w");
    fprintf(fp,"%s\n%s",username,password);
    fclose(fp);

    return ;

}


void changePassword(void)
{
    char ch;
    system("cls");
    border();

    gotoXY(50,5);
    cout<<"Password Changing Window!!!";

    gotoXY(30,15);
    cout<<"Enter the new Password : ";
    textbox(60,14);
    gotoXY(62,15);

        get(password);

    gotoXY(30,20);
    cout<<"Password Changed Successfully...";

    gotoXY(30,25);
    cout<<"Enter to return back to menu window.";
    getch();

    FILE *fp;
    fp=fopen("passuser.txt","w");
    fprintf(fp,"%s\n%s",username,password);
    fclose(fp);

    return ;

}

int login_frame(char c)
{
    FILE *fp;
    fp=fopen("passuser.txt","r");
    fscanf(fp,"%s\n%s",username,password);
    fclose(fp);

    int i=0,numberOfChance=3;
    char name[30],pwd[30],ch;
    while(numberOfChance--)
    {
        system("cls");
        border();
        if(c=='m')
        {
             gotoXY(55,5);
             cout<<"Login Window!!!";
        }
        else
        {
             gotoXY(55,5);
             cout<<"Confirmation Window!!!";
        }

        fflush(stdin);
        gotoXY(40,15);
        cout<<"Enter Username : ";
        textbox(60,14);
        gotoXY(62,15);
        get(name);

        fflush(stdin);
        gotoXY(40,19);
        cout<<"Enter Password : ";
        textbox(60,18);
        gotoXY(62,19);

        while(1)
        {
            ch=getch();
            if(ch==13)
            {
                pwd[i]='\0';
                break;
            }
            else if(ch==8)
            {
                i--;
                cout<<char(8);
                cout<<" ";
                cout<<char(8);
                pwd[i]='\0';
                continue;
            }
            else if(ch==32||ch==9||ch==8)
            {
                continue;
            }
            else
            {
                pwd[i]=ch;
                cout<<"*";
                i++;
            }
        }

        if(strcmp(name,username)==0&&strcmp(pwd,password)==0)
        {
            gotoXY(40,25);
            if(c=='m')
            {
                cout<<"Login Successful...";
                i=0;
                getch();
            }
            return 1;
        }
        else
        {
            if(c=='d')
                return 0;

            gotoXY(40,25);
            cout<<"Login Denied...";
            gotoXY(40,30);
            cout<<"You have just "<<numberOfChance<<" attempts left...";
            getch();
        }

}

gotoXY(40,35);
cout<<"Sorry , you are not the authentic user";
return 0;

}

