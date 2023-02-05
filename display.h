#include<iostream>
#include<stdio.h>
using namespace std;

void display(char name[],int code,char designation[],int yoe,float salary,int age,char address[],int n)
{
//    char detail[100];
//    FILE *fp=NULL;
//    fp=fopen("Records.txt","r");
//    if(fp!=NULL){
//    while(!feof(fp))
//    {
//        fgets(detail,100,fp);
//        cout<<detail;
//    }
//    fclose(fp);
//    }
//    else
//        cout<<"Denied...\n";
      for(int i=0;i<n;i++){
            if(i==0)
      printf("%30s%30s%30s%30s%40s%30s%30s%40s","Serial no.","Name","Code","Designation","Year of experience","Salary","Age","Address");
      printf("\n\n%30s%30d%30s%40d%30.2f%30d%40s",name,code,designation,yoe,salary,age,address);
      }


}
