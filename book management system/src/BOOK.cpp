#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include<iomanip>
#include <stdlib.h>
#include "book.h"

using namespace std;

  void book :: enter_details()
    {
        system("CLS");
        cout<<"\t\tADD BOOK"<<endl;
        cout<<"***********************************"<<endl;
        cout<<"Enter book number :";
        cin>>bno;
        cout<<"Enter book name :";
        cin>>bname;
        cout<<"Enter book author name :";
        cin>>author;
        cout<<"Enter book edition :";
        cin>>edition;
        cout<<"Enter the year of publication :";
        cin>>year_pub;
        cout<<"Enter Book price :";
        cin>>price;
        cout<<"Enter the number of copies the book :";
        cin>>copies;
        fstream file;
        file.open("book.dat",ios::out|ios::app);
        file.write((char *)this,sizeof(book));
        file.close();
        getch();
        cout<<"**********THANK YOU********************"<<endl;

    }

    void book :: dispaly()
    {
        char temp[5];
        system("CLS");
        cout<<"Enter the book number :";
        cin>>temp;
        cout<<"******************output**********************"<<endl;
        fstream file;
        file.open("book.dat",ios::in);
        file.seekg(0,ios::beg);
        while(!file.eof())
        {
        file.read((char *)this,sizeof(book));
        {
         if(!(strcmp(temp,bno)))
         {
          cout<<"\t\t"<<"Book number :"<<bno<<endl;
          cout<<"\t\t"<<"Book name :"<<bname<<endl;
          cout<<"\t\t"<<"Book author name :"<<author<<endl;
          cout<<"\t\t"<<"Book edition :"<<edition<<endl;
          cout<<"\t\t"<<"Year of publication :"<<year_pub<<endl;
          cout<<"\t\t"<<"Book price :"<<price<<endl;
          cout<<"\t\t"<<"Number of copies the book :"<<copies<<endl;
          cout<<"**********************************************************************************************************"<<endl;
          break;
         }
        }
        }
        file.close();
    }

    void book :: list_book()
    {
        system("CLS");
        cout<<"******************************************output**********************************************************"<<endl;
        cout<<"   book no \t\t\t\tname\t\t\t\t    Author"<<endl;
        cout<<"**********************************************************************************************************"<<endl;
        fstream file;
        char temp[10];
        file.open("book.dat",ios::in);
        file.seekg(0,ios::beg);
        while(!file.eof())
        {
        file.read((char *)this,sizeof(book));
        {
         if(strcmp(temp,bno))
         {
             strcpy(temp,bno);
             cout<<setw(10)<<bno<<"\t\t"<<setw(25)<<bname<<"\t\t"<<setw(20)<<author<<endl;
         }
        }
        }

        file.close();
    cout<<"**********************************************************************************************************"<<endl;
    }

    void book :: edit()
    {

        char temp[5];
        long pos;
        system("CLS");
        cout<<"Enter the book number :";
        cin>>temp;
        cout<<"**********************************************output*************************************************"<<endl;
        fstream file;
        file.open("book.dat",ios::in|ios::out);
        file.seekg(0,ios::beg);
        while(!file.eof())
        {
        pos = file.tellg();
        file.read((char *)this,sizeof(book));
        {
         if(!(strcmp(temp,bno)))
         {
          cout<<"\t\t"<<"Book number :"<<bno<<endl;
          cout<<"\t\t"<<"Book name :"<<bname<<endl;
          cout<<"\t\t"<<"Book author name :"<<author<<endl;
          cout<<"\t\t"<<"Book edition :"<<edition<<endl;
          cout<<"\t\t"<<"Year of publication :"<<year_pub<<endl;
          cout<<"\t\t"<<"Book price :"<<price<<endl;
          cout<<"\t\t"<<"Number of copies the book :"<<copies<<endl;
          cout<<"**********************************************************************************************************"<<endl;
          break;
         }
        }
        }
        cout<<"**********************************************************************************************************"<<endl;
        cout<<"\t\t"<<"1.Edit Book number"<<endl;
        cout<<"\t\t"<<"2.Edit Book name"<<endl;
        cout<<"\t\t"<<"3.Edit Book author name"<<endl;
        cout<<"\t\t"<<"4.Edit Book edition"<<endl;
        cout<<"\t\t"<<"5.Edit Year of publication :"<<endl;
        cout<<"\t\t"<<"6.Edit Book price :"<<endl;
        cout<<"\t\t"<<"7.Edit Number of copies the book :"<<endl;
        int n,yn;
        cout<<"**********************************************output*****************************************************"<<endl;
        do
        {
        cout<<"Enter your option :";
        cin>>n;

        if (1==n)
        {
         cout<<"Enter Book number :";
         cin>>bno;
        }
        else if(2==n)
        {
         cout<<"Enter new book name :";
         cin>>bname;
        }
        else if(3==n)
        {
         cout<<"Enter Book author name :";
         cin>>author;
        }
        else if(4==n)
        {
          cout<<"Enter new Book edition :";
          cin>>edition;
        }
        else if(5==n)
        {
          cout<<"Enter  new the year of publication :";
          cin>>year_pub;
        }
        else if(6==n)
        {
          cout<<"Enter new Book price :";
          cin>>price;
        }
        else if(7==n)
        {
          cout<<"Enter new number of copies the book :";
          cin>>copies;
        }
        else
        {
          cout<<"Wrong Entry";
        }
        cout<<"Did you want to edit again"<<endl<<"yes = 1"<<endl<<"no = 2\n"<<"Enter yes/no :";
        cin>>yn;
        }
        while (yn==1);
        file.seekg(pos);
        file.write((char *)this, sizeof(book));
        file.close();
    }

book::~book()
{
    //dtor
}
