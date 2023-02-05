#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include"login_frame_f.h"
#include"insert_records.h"
#include"menu.h"
#include"borders.h"

using namespace std;

class employee
{
    protected:
    char name[40],designation[40],address[50],loan[40];
    int code,age,yoe,absent=0;
    float salary;

    public:

    int login(char);
    char insert_record(int);
    int display_record(int);
    char menu();
    void edit_record();

};

class salaryManagement : public employee
{
    static float federalRate,stateTax,unionTax,pensionBalance,bonus;
    public:

    friend void update_or_search_record(salaryManagement a[],int,char);
    friend int save_record(salaryManagement obj[],int,char);
    friend int delete_record(salaryManagement obj[],int&);
    void sitting(void);
    void setfederalRate(float);
    void setstateTax(float);
    void setunionTax(float);
    void setpensionBalance(float);
    void setBonus(float);
    void calculateSalary(void);
    int available(void);
};

float salaryManagement::federalRate;
float salaryManagement::stateTax;
float salaryManagement::unionTax;
float salaryManagement::pensionBalance;
float salaryManagement::bonus;

void salaryManagement::setfederalRate(float fr=0)
{
    federalRate = fr;
}

void salaryManagement::setstateTax(float st=0)
{
    stateTax = st;
}

void salaryManagement::setunionTax(float ut=0)
{
    unionTax = ut;
}

void salaryManagement::setpensionBalance(float pp=0)
{
    pensionBalance = pp;
}

void salaryManagement::setBonus(float b=0)
{
    bonus = b;
}

void salaryManagement::calculateSalary()
{
    salary = salary+salary*federalRate/100-salary*stateTax/100-salary*unionTax/100+pensionBalance+bonus;
}

int salaryManagement::available()
{
    return absent;
}

void border(void);
void gotoxy(int,int);
void changePassword(void);
void changeUsername(void);
void textbox(int,int);
int stringToInt(void);
float stringToFloat(void);

int employee::login(char c)
{
    system("color E4");
    return login_frame(c);
}

char employee::insert_record(int index)
{
    system("color E1");
    return insert_records(name,code,designation,yoe,salary,age,address,loan,index);
}

int employee::display_record(int index)
{
    system("color 8E");
    if(absent==1)
        return index;
    cout<<"\n\n";
    printf("          %10d.%20s%20d%25s%25d%15.2f%10d%25s%20s",index+1,name,code,designation,yoe,salary,age,address,loan);
    return index+1;
}


void salaryManagement::sitting()
{
    system("color 8E");
    system("cls");
    border();
    char ch;

    gotoXY(50,5);
    cout<<"Sittings!!!";

    gotoXY(30,8);
    cout<<"Type 'u' ----------> to change the username.";

    gotoXY(30,11);
    cout<<"Type 'p' ----------> to change the passward.";

    gotoXY(30,14);
    cout<<"Type 'h' ----------> To know about the working.";

    gotoXY(30,17);
    cout<<"Type 'f' ----------> To change the federal rate.";

    gotoXY(30,20);
    cout<<"Type 's' ----------> To change the state tax.";

    gotoXY(30,23);
    cout<<"Type 't' ----------> To change the union tax.";

    gotoXY(30,26);
    cout<<"Type 'n' ----------> To add the pension.";

    gotoXY(30,29);
    cout<<"Type 'b' ----------> To give bonus.";

    gotoXY(30,32);
    cout<<"Type 'r' ----------> To return back to menu window.";

    gotoXY(30,35);
    cout<<"Enter your choice here : ";
    cin>>ch;

    switch(ch)
    {
        case 'u':

                    if(login('c')==1)
                    {
                        changeUsername();
                    }
                    else
                    {
                        system("cls");
                        border();

                        gotoXY(30,15);
                        cout<<"You are not authentic user...";

                        gotoXY(30,8);
                        cout<<"So , username cant be change.";
                    }
                    break;

        case 'p':

                    if(login('c')==1)
                    {
                        changePassword();
                    }
                    else
                    {
                        system("cls");
                        border();

                        gotoXY(30,15);
                        cout<<"You are not authentic user...";

                        gotoXY(30,8);
                        cout<<"So , Password cant be change.";
                    }
                    break;

        case 'h':

                    system("cls");
                    border();

                    gotoXY(50,5);
                    cout<<"About the software!!!";

                    gotoXY(30,15);
                    cout<<"Its a Payroll Management Software which is design to collect the data";
                    gotoXY(30,17);
                    cout<<"of employee , display the data of employee , search and update the data";
                    gotoXY(30,19);
                    cout<<"of employee , delete the data of employee , save the data of employee on";
                    gotoXY(30,21);
                    cout<<"permanent basis or temporary basis on users choice or user can quit without";
                    gotoXY(30,23);
                    cout<<"saving the data.";

                    gotoXY(30,27);
                    cout<<"Setting option is there to change the username , password , allowances related";
                    gotoXY(30,29);
                    cout<<"to employee salary with a proper authentication process. ";

                    //information

                    gotoXY(30,35);
                    cout<<"Enter to return back to menu window.";
                    getch();

                    break;

        case 'f':
                    system("cls");
                    border();

                    float fr;

                    gotoXY(50,5);
                    printf("Federal rate changing Window!!!");

                    gotoXY(30,15);
                    printf("Enter the new federal rate : ");
                    textbox(60,14);
                    gotoXY(62,15);
                    fr=stringToFloat();
                    setfederalRate(fr);

                    gotoXY(30,20);
                    cout<<"Enter to return back to menu window.";
                    getch();

                    break;

        case 's':
                    system("cls");
                    border();

                    float st;

                    gotoXY(50,5);
                    printf("State Tax changing Window!!!");

                    gotoXY(30,15);
                    printf("Enter the new Union Tax : ");

                    textbox(60,14);
                    gotoXY(62,15);
                    st=stringToFloat();
                    setstateTax(st);

                    gotoXY(30,20);
                    cout<<"Enter to return back to menu window.";
                    getch();

                    break;

        case 't':
                    system("cls");
                    border();

                    float ut;

                    gotoXY(50,5);
                    printf("Union Tax changing Window!!!");

                    gotoXY(30,15);
                    printf("Enter the new Union Tax : ");

                    textbox(60,14);
                    gotoXY(62,15);
                    ut=stringToFloat();
                    setunionTax(ut);

                    gotoXY(30,20);
                    cout<<"Enter to return back to menu window.";
                    getch();

                    break;

        case 'n':
                    system("cls");
                    border();
                    float p;

                    gotoXY(50,5);
                    printf("Pension adding Window!!!");

                    gotoXY(30,15);
                    printf("Enter the pension : ");

                    textbox(60,14);
                    gotoXY(62,15);
                    p=stringToFloat();
                    setpensionBalance(p);

                    gotoXY(30,20);
                    cout<<"Enter to return back to menu window.";
                    getch();

                    break;

        case 'b':
                    system("cls");
                    border();
                    float b;

                    gotoXY(50,5);
                    printf("Bonus adding Window!!!");

                    gotoXY(30,15);
                    printf("Enter the Bonus price : ");

                    textbox(60,14);
                    gotoXY(62,15);
                    b=stringToFloat();
                    setfederalRate(b);

                    gotoXY(30,20);
                    cout<<"Enter to return back to menu window.";
                    getch();

                    break;

        case 'r':
                   return ;

        default:

                   system("cls");
                   border();
                   gotoXY(30,15);
                   printf("Invalid Choice ....");

                   gotoXY(30,18);
                   printf("Enter to return back to the menu.");
                   getch();

    }

}


int delete_record(salaryManagement a[],int &n)
{
    system("color E4");
    int codex;
    int j,valid=0;

    valid=a[0].login('d');
    if(valid==1)
    {
        system("cls");
        border();

        gotoXY(50,5);
        cout<<"Record Deleting Window!!!";

        gotoXY(30,10);
        cout<<"Enter the employee code to delete : ";
        textbox(66,9);
        gotoXY(68,10);
        codex=stringToInt();

        for(int j=0;j<n;j++)
        {
            if(a[j].code==codex)
            {
                gotoXY(30,15);
                cout<<"Employee record with code "<<codex<<" has been deleted form the record.";
                a[j].absent=1;
                gotoXY(30,20);
                cout<<"Press enter to return back to the menu window.";
                getch();
                return 1;
             }
         }
         gotoXY(30,25);
         cout<<codex<<" does not found in the records.";
         gotoXY(30,29);
         cout<<"Enter to return back to menu Window.";
         getch();
         return 0;

    }

    else
    {
         system("cls");
         border();
         gotoXY(30,15);
         cout<<"Record cannot be deleted as you are not the authorized person...";
         gotoXY(30,20);
         cout<<"Press enter to return back to the menu window.";
         getch();
         return 0;
    }

}

void employee::edit_record(void)
{
    system("color 8E");
    char ch;

    system("cls");
    border();

    gotoXY(50,5);
    cout<<"Edit Window!!!";

    gotoXY(30,10);
    cout<<"Select the field to be updated.";

    gotoXY(30,13);
    cout<<"Enter n ---------> to edit the name.";

    gotoXY(30,16);
    cout<<"Enter c ---------> to edit the code.";

    gotoXY(30,19);
    cout<<"Enter d ---------> to edit the designation.";

    gotoXY(30,22);
    cout<<"Enter y ---------> to edit the year of experience.";

    gotoXY(30,25);
    cout<<"Enter s ---------> to edit the salary.";

    gotoXY(30,28);
    cout<<"Enter a ---------> to edit the age.";

    gotoXY(30,31);
    cout<<"Enter r ---------> to edit the address.";

    gotoXY(30,34);
    cout<<"Enter q ---------> to return back to update window.";

    gotoXY(30,37);
    cout<<"Enter l ---------> to change the status of loan.";


    gotoXY(30,40);
    cout<<"Type your choice here : ";
    cin>>ch;

    system("cls");
    border();

    switch(ch)
   {
       case 'n':
           fflush(stdin);
           gotoXY(30,17);
           cout<<"Enter the new name : ";
           textbox(65,16);
           gotoXY(67,17);
           get(name);
           gotoXY(30,20);
           cout<<"Name updated successfully...";
           gotoXY(30,25);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'c':

           gotoXY(30,17);
           cout<<"Enter the new code : ";
           textbox(65,16);
           gotoXY(67,17);
           code=stringToInt();
           gotoXY(30,20);
           cout<<"code updated successfully...";
           gotoXY(30,25);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'd':

           fflush(stdin);
           gotoXY(30,17);
           cout<<"Enter the new designation : ";
           textbox(65,16);
           gotoXY(67,17);
           get(designation);
           gotoXY(30,20);
           cout<<"Designation updated successfully...";
           gotoXY(30,25);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'y':

           gotoXY(30,17);
           cout<<"Enter the new year of experience : ";
           textbox(65,16);
           gotoXY(67,17);
           yoe=stringToInt();
           gotoXY(30,20);
           cout<<"Year of experience updated successfully...";
           gotoXY(30,25);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 's':

           gotoXY(30,17);
           cout<<"Enter the updated salary : ";
           textbox(65,16);
           gotoXY(67,17);
           salary=stringToFloat();
           gotoXY(30,20);
           cout<<"Salary updated successfully...";
           gotoXY(30,25);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'a':

           gotoXY(30,17);
           cout<<"Enter the updated : ";
           textbox(65,16);
           gotoXY(67,17);
           age=stringToInt();
           gotoXY(30,20);
           cout<<"Age updated successfully...";
           gotoXY(30,25);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'r':

           fflush(stdin);
           gotoXY(30,17);
           cout<<"Enter the new address : ";
           textbox(65,16);
           gotoXY(67,17);
           get(address);
           gotoXY(30,20);
           cout<<"Address updated successfully...";
           gotoXY(30,25);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'l':

           fflush(stdin);
           gotoXY(30,17);
           cout<<"Enter the new Status of loan : ";
           textbox(65,16);
           gotoXY(67,17);
           get(loan);
           gotoXY(30,20);
           cout<<"Status of loan updated successfully...";
           gotoXY(30,25);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'q':

           return ;

       default:

           gotoXY(30,20);
           cout<<"Invalid choice.";
           gotoXY(30,23);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

     }

}


void update_or_search_record(salaryManagement a[],int n,char c)
{
    system("color 61");
    char ch,name_[30],designation_[40],address_[40];
    int codex,flag=0,age_,yoe_;
    float salary_;

    border();
    gotoXY(50,5);
    if(c=='u')
           cout<<"Search the employee for editing!!!";
    else
           cout<<"Search employee window!!!";

    gotoXY(30,10);
    cout<<"Select the method by which you want to search a record.";

    gotoXY(30,13);
    cout<<"Enter n ---------> to search by name.";

    gotoXY(30,16);
    cout<<"Enter c ---------> to search by code.";

    gotoXY(30,19);
    cout<<"Enter d ---------> to search by designation.";

    gotoXY(30,22);
    cout<<"Enter y ---------> to search by year of experience.";

    gotoXY(30,25);
    cout<<"Enter s ---------> to search by salary.";

    gotoXY(30,28);
    cout<<"Enter a ---------> to search by age.";

    gotoXY(30,31);
    cout<<"Enter r ---------> to search by address.";

    gotoXY(30,34);
    cout<<"Enter q ---------> to return back to menu window.";

    gotoXY(30,36);
    cout<<"Type your choice here : ";
    cin>>ch;

    system("cls");
    border();

    switch(ch)
    {
       case 'n':
           gotoXY(50,5);
           cout<<"Searching record by name!!!";
           gotoXY(30,13);
           cout<<"Enter the name to be searched : ";
           fflush(stdin);
           textbox(62,12);
           gotoXY(65,13);
           get(name_);
           for(int j=0;j<n;j++)
           {
               if(strcmp(a[j].name,name_)==0)
               {
                   gotoXY(30,17);
                   cout<<"Record found...";
                   gotoXY(30,20);
                   if(c=='u')
                   {
                       cout<<"Press enter to go for correction.";
                       getch();
                       a[j].edit_record();
                   }
                   else
                   {
                       cout<<"Press enter to return back to menu window.";
                       getch();
                   }
                   return ;
               }
           }
                gotoXY(30,17);
                cout<<"Sorry , "<<name_<<" does not found in the list...";
                gotoXY(30,20);
                cout<<"Press enter to return back to menu window.";
                getch();
                return ;

       case 'c':

           gotoXY(50,5);
           cout<<"Searching window by code!!!";
           gotoXY(30,13);
           cout<<"Enter the code to be search : ";
           textbox(60,12);
           gotoXY(62,13);
           codex=stringToInt();
           for(int j=0;j<n;j++)
           {
               if(a[j].code==codex)
               {
                   gotoXY(30,17);
                   cout<<"Record found...";
                   gotoXY(30,20);
                   if(c=='u')
                   {
                       cout<<"Press enter to go for correction.";
                       getch();
                       a[j].edit_record();
                   }
                   else
                   {
                       cout<<"Press enter to return back to menu window.";
                       getch();
                   }
                   return ;
               }
           }
           gotoXY(30,16);
           cout<<"Record not found...";
           gotoXY(30,20);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'd':

           gotoXY(50,5);
           cout<<"Searching record by Designation!!!";
           gotoXY(30,13);
           cout<<"Enter the designation to be searched : ";
           fflush(stdin);
           textbox(69,12);
           gotoXY(71,13);
           get(designation_);
           for(int j=0;j<n;j++)
           {
               if(strcmp(a[j].designation,designation_)==0)
               {
                   gotoXY(30,17);
                   cout<<"Record found...";
                   gotoXY(30,20);
                   if(c=='u')
                   {
                        cout<<"Press enter to go for correction.";
                        getch();
                        a[j].edit_record();
                   }
                   else
                   {
                       cout<<"Press enter to return back to menu window.";
                       getch();
                   }
                   return ;
               }
           }
               gotoXY(30,17);
               cout<<"Sorry , "<<designation_<<" does not found in the list...";
               gotoXY(30,20);
               cout<<"Press enter to return back to menu window.";
               getch();
               return ;

       case 'y':

           gotoXY(50,5);
           cout<<"Searching window by year of experience!!!";
           gotoXY(30,13);
           cout<<"Enter the year of experience to be search : ";
           textbox(73,12);
           gotoXY(75,13);
           yoe_=stringToInt();
           for(int j=0;j<n;j++)
           {
               if(a[j].yoe==yoe_)
               {
                   gotoXY(30,17);
                   cout<<"Record found...";
                   gotoXY(30,20);
                   if(c=='u')
                   {
                       cout<<"Press enter to go for correction.";
                       getch();
                       a[j].edit_record();
                   }
                   else
                   {
                       cout<<"Press enter to return back to menu window.";
                       getch();
                   }
                   return ;
               }
           }
           gotoXY(30,16);
           cout<<"Record not found...";
           gotoXY(30,20);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 's':

           gotoXY(50,5);
           cout<<"Searching window by salary!!!";
           gotoXY(30,13);
           cout<<"Enter the amount of salary to be search : ";
           textbox(71,12);
           gotoXY(73,13);
           cin>>salary_;
           for(int j=0;j<n;j++)
           {
               if(a[j].salary==salary_)
               {
                   gotoXY(30,17);
                   cout<<"Record found...";
                   gotoXY(30,20);
                   if(c=='u')
                   {
                        cout<<"Press enter to go for correction.";
                        getch();
                        a[j].edit_record();
                   }
                   else
                   {
                       cout<<"Press enter to return back to menu window.";
                       getch();
                   }
                  return ;
               }
           }
           gotoXY(30,16);
           cout<<"Record not found...";
           gotoXY(30,20);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'a':

           gotoXY(50,5);
           cout<<"Searching window by Age!!!";
           gotoXY(30,13);
           cout<<"Enter the age to be search : ";
           textbox(69,12);
           gotoXY(71,13);
           age_=stringToInt();
           for(int j=0;j<n;j++)
           {
               if(a[j].age==age_)
               {
                   gotoXY(30,17);
                   cout<<"Record found...";
                   gotoXY(30,20);
                   if(c=='u')
                   {
                        cout<<"Press enter to go for correction.";
                        getch();
                        a[j].edit_record();
                   }
                   else
                   {
                       cout<<"Press enter to return back to menu window.";
                       getch();
                   }
                  return ;
               }
           }
           gotoXY(30,16);
           cout<<"Record not found...";
           gotoXY(30,20);
           cout<<"Press enter to return back to menu window.";
           getch();
           return ;

       case 'r':

           gotoXY(50,5);
           cout<<"Searching record by address!!!";
           gotoXY(30,13);
           cout<<"Enter the address to be search : ";
           fflush(stdin);
           textbox(63,12);
           gotoXY(65,13);
           get(address_);
           for(int j=0;j<n;j++)
           {
               if(strcmp(a[j].address,address_)==0)
               {
                   gotoXY(30,17);
                   cout<<"Record found...";
                   gotoXY(30,20);
                   if(c=='u')
                   {
                        cout<<"Press enter to go for correction.";
                        getch();
                        a[j].edit_record();
                   }
                   else
                   {
                       cout<<"Press enter to return back to menu window.";
                       getch();
                   }
                  return ;
               }
           }
               gotoXY(30,17);
               cout<<"Sorry , "<<address_<<" does not found in the list...";
               gotoXY(30,20);
               cout<<"Press enter to return back to menu window.";
               getch();
               return ;

       case 'q':

               return ;

       default:

               cout<<"Invalid choice.";
               return ;
       }
}

char employee::menu(void)
{
    system("color E2");
    return menu_opt();
}

int save_record(salaryManagement a[],int n,char ch)
{
    int index=0;
    system("color E5");
    FILE *fp=NULL;

    char date[15],time[10];

    gotoXY(30,17);
    cout<<"Enter today's Date (dd/mm/yy) : ";
    fflush(stdin);
    textbox(61,16);
    gotoXY(63,17);
    get(date);

    gotoXY(30,20);
    cout<<"Enter time (hh.mm.ss) : ";
    fflush(stdin);
    textbox(61,19);
    gotoXY(63,20);
    get(time);


    if(ch=='w')
    {
        fp=fopen("Record.txt","w");
    }
    else if(ch=='a')
    {
        fp=fopen("Record.txt","a");
    }
    else
    {
        fp=NULL;
    }

    if(fp!=NULL)
    {
        fprintf(fp,"\n\n                              Date: %s Time : %s",date,time);
        fprintf(fp,"\n\n\n%20s%20s%20s%25s%25s%15s%10s%25s%20s","Serial no.","Name","Code","Designation","Year of experience","Salary","Age","Address","Loan Status");
        for(int j=0;j<n;j++)
        {
            if(a[j].available()!=1){       //if available then return 0 else 1.
            index++;
            fprintf(fp,"\n\n%20d.%20s%20d%25s%25d%15.2f%10d%25s%20s",index,a[j].name,a[j].code,a[j].designation,a[j].yoe,a[j].salary,a[j].age,a[j].address,a[j].loan);
            }
        }
        fclose(fp);

        return 1;

    }
       fclose(fp);
       return 0;


}

int main()
{
    char ch,name[40],pass[40];
    int totalNumberOfRecord=0,totalDeletedRecord=0,index;
    salaryManagement a[10];
    border();
    system("color E4");
    gotoXY(50,5);
    cout<<"/ \\";
    gotoXY(48,6);
    cout<<" /   \\";
    gotoXY(48,7);
    cout<<" |   |";
    gotoXY(48,8);
    cout<<" |   |";
        gotoXY(60,5);
    cout<<"/ \\";
    gotoXY(58,6);
    cout<<" /   \\";
    gotoXY(58,7);
    cout<<" |   |";
    gotoXY(58,8);
    cout<<" |   |";
        gotoXY(70,5);
    cout<<"/ \\";
    gotoXY(68,6);
    cout<<" /   \\";
    gotoXY(68,7);
    cout<<" |   |";
    gotoXY(68,8);
    cout<<" |   |";
    gotoXY(30,15);
    cout<<"W E L C O M E    T O    G R A P H I C    E R A    U N I V E R S I T Y.";
    gotoXY(30,20);
    cout<<"P A Y R O L L    M A N A G E M E N T    S Y S T E M.";
        gotoXY(50,25);
    cout<<"/ \\";
    gotoXY(48,26);
    cout<<" /   \\";
    gotoXY(48,27);
    cout<<" |   |";
    gotoXY(48,28);
    cout<<" |   |";
        gotoXY(60,25);
    cout<<"/ \\";
    gotoXY(58,26);
    cout<<" /   \\";
    gotoXY(58,27);
    cout<<" |   |";
    gotoXY(58,28);
    cout<<" |   |";
        gotoXY(70,25);
    cout<<"/ \\";
    gotoXY(68,26);
    cout<<" /   \\";
    gotoXY(68,27);
    cout<<" |   |";
    gotoXY(68,28);
    cout<<" |   |";
    gotoXY(50,40);
    cout<<"Made by Karan Maurya.";
    getch();
    if(a[0].login('m')==1)
    {

        while(1)
        {
            ch=a[0].menu();
            system("cls");
            switch(ch)
            {
               case 'i':

                        while(1)
                        {
                             ch=a[totalNumberOfRecord].insert_record(totalNumberOfRecord-totalDeletedRecord);
                             a[totalNumberOfRecord].calculateSalary();
                             totalNumberOfRecord++;
                             if(ch=='a')
                             {
                                  system("cls");
                             }
                             else
                                  break;
                        }

                        break;
              case 'd':

                       if(totalNumberOfRecord==0||totalNumberOfRecord-totalDeletedRecord==0)
                       {

                            system("cls");
                            border();

                            gotoXY(30,15);
                            cout<<"Record is empty.";
                            gotoXY(30,20);
                            cout<<"Press enter to return back to menu function.";
                            getch();
                       }
                       else
                       {
                           totalDeletedRecord=totalDeletedRecord+delete_record(a,totalNumberOfRecord);
                       }

                       break;

               case 'p':
                        system("cls");
                        border();
                        gotoXY(50,5);
                        cout<<"Print method choosing window!!!";
                        gotoXY(30,15);
                        cout<<"Enter c ----------> to view the current records entered.";

                        gotoXY(30,19);
                        cout<<"Enter p ----------> to view the previous saved records.";

                        gotoXY(30,23);
                        cout<<"Type your choice here : ";
                        cin>>ch;
                        if(ch=='c')
                        {
                            system("cls");
                            if(totalNumberOfRecord==0||totalNumberOfRecord-totalDeletedRecord==0)
                            {
                                border();

                                gotoXY(30,15);
                                cout<<"No current records are present.";
                                gotoXY(30,20);
                                cout<<"Press enter to return back to menu function.";
                                getch();
                            }
                            else
                            {
                                int index=0;
                                for(int i=0;i<totalNumberOfRecord;i++)
                                {
                                    if(i==0){
                                        printf("\n\n                                                                                  Record Printing Window");
                                        printf("\n\n          # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
                                        printf("\n\n          # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
                                        printf("\n\n\n          %10s%20s%20s%25s%25s%15s%10s%25s%20s","Serial no.","Name","Code","Designation","Year of experience","Salary","Age","Address","Status of Loan");
                                        printf("\n\n          ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
                                        }
                                    index=a[i].display_record(index);
                                }
                                printf("\n\n          ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
                                cout<<"\n\n\n\n";
                                cout<<"                                                                                  Enter to return back to menu window.";
                                getch();
                            }
                        }
                        else
                        {
                            system("cls");

                            FILE *fp=NULL;
                            char str[210];

                            fp=fopen("Record.txt","r");

                            while(feof(fp)==0)
                            {
                                fgets(str,210,fp);
                                cout<<str<<endl;
                            }

                            fclose(fp);

                            cout<<"\n\n\n\n                               Enter to return back to menu window.";
                            getch();


                        }

                    break;

          case 'u':
                   if(totalNumberOfRecord==0||totalNumberOfRecord-totalDeletedRecord==0)
                   {
                        system("cls");
                        border();

                        gotoXY(30,15);
                        cout<<"Record is empty.";
                        gotoXY(30,20);
                        cout<<"Press enter to return back to menu function.";
                        getch();
                   }
                   else
                   {
                        system("cls");
                        update_or_search_record(a,totalNumberOfRecord,'u');
                   }
                   break;

          case 's':
                   if(totalNumberOfRecord==0||totalNumberOfRecord-totalDeletedRecord==0)
                   {
                       system("cls");
                       border();
                       gotoXY(30,15);
                       cout<<"Record is empty.";
                       gotoXY(30,20);
                       cout<<"Press enter to return back to menu function.";
                       getch();
                    }
                    else
                    {
                       system("cls");
                       update_or_search_record(a,totalNumberOfRecord,'s');
                    }
                    break;

          case 'a':
                   a[0].sitting();
                   break;

          case 'q':

                    system("cls");
                    border();

                    gotoXY(50,5);
                    cout<<"Record Saving Window!!!";

                    gotoXY(30,8);
                    cout<<"Type 'w' ----------> to overwrite the previous records.";
                    gotoXY(30,10);
                    cout<<"Type 'a' ----------> to add on to the previously saved records.";
                    gotoXY(30,12);
                    cout<<"Type 'q' ----------> to quit without saving records.";

                    gotoXY(30,14);
                    cout<<"Enter your choice : ";
                    cin>>ch;
                    if(ch!='q')
                    {
                         if(save_record(a,totalNumberOfRecord,ch)==1)
                         {
                              gotoXY(30,24);
                              cout<<"Record Saved Successfully...";
                         }
                         else
                         {
                              gotoXY(30,24);
                              cout<<"Sorry ,  record not saved due to lack of memory...";
                         }
                    }

                    gotoXY(30,29);
                    cout<<"Thank You for providing so important data...";

                    gotoXY(30,34);
                    cout<<"Thank You for Visiting us...";
                    gotoXY(0,45);

                    return 0;

          default:

                    system("cls");
                    border();

                    gotoXY(30,15);
                    cout<<"Invalid choice...";

                    gotoXY(30,20);
                    cout<<"Enter to return back to menu window.";
                    getch();

          }
       }
    }


           gotoXY(0,45);
           return 0;

}
