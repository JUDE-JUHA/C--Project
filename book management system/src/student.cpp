#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include<iomanip>
#include <stdlib.h>
#include "student.h"
#include "borrow.h"
#include "book.h"
#include "student.h"

using namespace std;
 //student :: student()
     //   {
     //       strcpy(name,"No Details");
    //        strcpy(d_no,"No Details");
    //        strcpy(department,"No Details");
    //        strcpy(dob,"No Details");

 //       }
    student :: student(char *n,char *d,char *dep,char *db)
       {
           strcpy(name,n);
           strcpy(d_no,d);
           strcpy(department,dep);
           strcpy(dob,db);
       }
    student :: student(student &a)
    {
        strcpy(name,a.name);
        strcpy(d_no,a.d_no);
        strcpy(department,a.department);
        strcpy(dob,a.dob);
    }
    void student :: enter_details1()
    {
        system("CLS");
        cout<<"\t\tADD STUDENT INFORMATION"<<endl;
        cout<<"*******************************************************"<<endl;
        cout<<"Enter d_no of student :";
        cin>>d_no;
        cout<<"Enter student name :";
        cin>>name;
        cout<<"Enter the department name :";
        cin>>department;
        cout<<"Enter student's date of birth :";
        cin>>dob;
        fstream file;
        file.open("stud.dat",ios::out|ios::app);
        file.write((char *)this,sizeof(student));
        file.close();
        borrow c;
        c.borrow::set1(d_no);
    }
    void student :: dispaly2()
    {
        char temp[10];
        int n=0;
        system("CLS");
        cout<<"Enter the d_no of the student :";
        cin>>temp;
        cout<<"******************output**********************"<<endl;
        fstream file;
        file.open("stud.dat",ios::in);
        file.seekg(0,ios::beg);
        while(!file.eof())
        {
        file.read((char *)this,sizeof(student));
        {
         if(!(strcmp(temp,d_no)))
        {
        cout<<"Enter d_no of student :"<<d_no<<endl;
        cout<<"Enter student name :"<<name<<endl;
        cout<<"Enter the department name :"<<department<<endl;
        cout<<"Enter student's date of birth :"<<dob<<endl;
        cout<<"**********************************************"<<endl;
        n=1;
        break;
        }
        }
        }
        file.close();
        if(n==0)
            cout<<"NO SUCH INFORMATION"<<endl;
            cout<<"**********************************************"<<endl;
        if(n==1)
        {
        borrow b;
        b.borrow::display(d_no);
        }
    }
    void student :: edit()
    {
        char temp[10];
        long pos;
        int n=0;
        system("CLS");
        cout<<"Enter the d_no of the student :";
        cin>>temp;
        cout<<"********************************************"<<endl;
        fstream file;
        file.open("stud.dat",ios::in|ios::out);
        file.seekg(0,ios::beg);
        while(!file.eof())
        {
        pos = file.tellg();
        file.read((char *)this,sizeof(student));
        {
         if(!(strcmp(temp,d_no)))
        {
        cout<<"Enter d_no of student :"<<d_no<<endl;
        cout<<"Enter student name :"<<name<<endl;
        cout<<"Enter the department name :"<<department<<endl;
        cout<<"Enter student's date of birth :"<<dob<<endl;
        cout<<"**********************************************"<<endl;
        n=1;
        break;
        }
        }
        }
        if(n==1)
        {
        cout<<"**********************************************"<<endl;
        cout<<"1.Edit name"<<endl;
        cout<<"2.Edit department"<<endl;
        cout<<"3.Edit date of birth"<<endl;
        cout<<"4.Edit d_no"<<endl;
        int n,yn;
    do
    {
        cout<<"Enter your option :";
        cin>>n;

        if(1==n)
        {
         cout<<"Enter new student name :";
         cin>>name;
        }
        else if (2==n)
        {
         cout<<"Enter the department name :";
         cin>>department;
        }
        else if(3==n)
        {
         cout<<"Enter student's date of birth :";
         cin>>dob;
        }
        else if(4==n)
        {
          cout<<"Enter new d_no of student :";
          cin>>d_no;
        }
        else
        {
          cout<<"Wrong Entry";
        }
        cout<<"Did you want to edit again"<<endl<<"yes = 1"<<endl<<"no = 2\n"<<"Enter yes/no :";
        cin>>yn;
    }


        while (yn==1);
    }

         if(n==0)
        {
            cout<<"There is no such data."<<endl;
            getch();

        }

        file.seekg(pos);
        file.write((char *)this, sizeof(student));
        file.close();

    }

    void student:: student_list()
    {
        char temp[10];
        system("CLS");
        cout<<"********************************************output********************************************************"<<endl;
        fstream file;
        file.open("stud.dat",ios::in);
        file.seekg(0,ios::beg);
        cout<<"\t\t"<<"    D_NO\t\t  NAME\t\tDEPARTMENT"<<endl;
        cout<<"**********************************************************************************************************"<<endl;
        while(!file.eof())
        {
        file.read((char *)this,sizeof(student));
        {
         if(strcmp(temp,d_no))
         {
         strcpy(temp,d_no);
         cout<<"\t\t"<<setw(10)<<d_no<<setw(20)<<name<<setw(20)<<department<<endl;
        }
        }
        }
        cout<<"**********************************************************************************************************"<<endl;

        file.close();

        }

student::~student()
{
    //dtor
}
