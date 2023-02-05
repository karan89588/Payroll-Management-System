#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

void get(char name[]);
void border();
int stringToInt(void);
float stringToFloat(void);

char insert_records(char name[],int &code,char designation[],int &yoe,float &salary,int &age,char address[],char loan[],int c)
{
    char ch;

        border();
        gotoXY(50,5);
        cout<<"Record adding window...";

        gotoXY(30,9);
        cout<<"Enter records for "<<c+1<<" employee.";

        fflush(stdin);
        gotoXY(30,12);
        cout<<"Name : ";
        textbox(51,11);
        gotoXY(53,12);
        get(name);

        gotoXY(30,15);
        cout<<"Code : ";
        textbox(51,14);
        gotoXY(53,15);
        code=stringToInt();

        fflush(stdin);
        gotoXY(30,18);
        cout<<"Designation : ";
        textbox(51,17);
        gotoXY(53,18);
        get(designation);

        gotoXY(30,21);
        cout<<"Year of experience : ";
        textbox(51,20);
        gotoXY(53,21);
        yoe=stringToInt();

        gotoXY(30,24);
        cout<<"Salary : ";
        textbox(51,23);
        gotoXY(53,24);
        salary=stringToFloat();

        gotoXY(30,27);
        cout<<"Age : ";
        textbox(51,26);
        gotoXY(53,27);

        age=stringToInt();

        fflush(stdin);
        gotoXY(30,30);
        cout<<"Address : ";
        textbox(51,29);
        gotoXY(53,30);
        get(address);

        fflush(stdin);
        gotoXY(30,33);
        cout<<"Status of loan : ";
        textbox(51,32);
        gotoXY(53,33);
        get(loan);

        gotoXY(30,37);
        cout<<"Record added successfully...\n\n";

        gotoXY(30,40);
        cout<<"Type 'a' to add more and 'b' to return back to menu window.";
        cin>>ch;


        return ch;
}



