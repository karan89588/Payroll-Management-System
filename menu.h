#include<iostream>
#include<windows.h>
using namespace std;

char menu_opt()
{
    system("cls");
    char ch;
    gotoXY(50,5);
    cout<<"Welcome to Payroll Management System!!!";

    border();

    gotoXY(30,13);
    cout<<"Please, select your choice.";

    gotoXY(30,17);
    cout<<"Enter i ----------> Insert record.";

        gotoXY(30,20);
    cout<<"Enter d ----------> Delete record.";

        gotoXY(30,23);
    cout<<"Enter u ----------> Update record.";

        gotoXY(30,26);
    cout<<"Enter p ----------> Print records.";

    gotoXY(30,29);
    cout<<"Enter s ----------> Search record.";

    gotoXY(30,32);
    cout<<"Enter a ----------> Settings.";

    gotoXY(30,35);
    cout<<"Enter q ----------> Quit.";


    gotoXY(30,38);
    cout<<"Type Your Choice Here.";

    cin>>ch;

    return ch;

}
