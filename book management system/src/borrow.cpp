#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include<iomanip>
#include <stdlib.h>
#include "borrow.h"

using namespace std;

borrow::borrow()
{
    //ctor
}
//TO CACULATE FINE AMOUNT
int borrow::fine(int yr,int mon,int d)
{
    int year,month,day,n=0;
    int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(yr%400==0||(yr%4==0&&yr%100!=0))
    {
        m[1]=29;
    }
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year=1900 + ltm->tm_year;
    month= 1 + ltm->tm_mon;
    day=ltm->tm_mday;

    if (yr==year && mon==month)
    {
        n=d-day;
    }

     else if(yr==year && mon<month)
    {
        n=m[mon-1]-d;
        while(mon < month-1)
        {
         n=n+m[mon];
         mon++;
        }
        n=n+day;
    }
    else if(yr<year)
    {
        n=m[mon-1]-d;
        while(mon<12)
        {
         n=n+m[mon];
         mon++;
        }
        mon=0;
        while(mon<month-1)
        {
            n=n+m[mon];
        }
        n=n+day;
    }

    return n;

}

        //To set current time
           void borrow::time1()
        {
            int ti,mi,sec;
            time_t now = time(0);
            tm *ltm = localtime(&now);
            year[0]=1900 + ltm->tm_year;
            month[0]= 1 + ltm->tm_mon;
            day[0]=ltm->tm_mday;
            ti=1 + ltm->tm_hour;
            mi= 1 + ltm->tm_min;
            sec=1 + ltm->tm_sec;
            cout << "Year:"<<year[0]<<" "<< "Month:"<<month[0]<<" "<< "Day:"<<day[0]<<" "<< "Time:"<<ti<< ":"<<mi<< ":"<<sec<< endl;
        }
         //To set current time
           void borrow::time2()
        {
            int ti,mi,sec;
            time_t now = time(0);
            tm *ltm = localtime(&now);
            year[1]=1900 + ltm->tm_year;
            month[1]= 1 + ltm->tm_mon;
            day[1]=ltm->tm_mday;
            ti=1 + ltm->tm_hour;
            mi= 1 + ltm->tm_min;
            sec=1 + ltm->tm_sec;
            cout << "Year:"<<year[1]<<" "<< "Month:"<<month[1]<<" "<< "Day:"<<day[1]<<" "<< "Time:"<<ti<< ":"<<mi<< ":"<<sec<< endl;
        }

            // TO SET DEFAULT VALUE
            void borrow::set1(char *a)
            {
               strcpy(dno,a);
               books_taken=0;
               strcpy(book_no1,"0000");
               strcpy(book_no2,"0000");
               year[0]=0;
               month[0]=0;
               day[0]=0;
               year[1]=0;
               month[1]=0;
               day[1]=0;
               fstream file;
               file.open("borrow.dat",ios::app);
               file.write((char *)this,sizeof(borrow));
               file.close();
            }
            void borrow:: get_book()
            {

                char temp[10];
                long pos;
                system("CLS");
                cout<<"***************************************************"<<endl;
                cout<<"Enter student department number :";
                cin>>temp;
                cout<<"***************************************************"<<endl<<endl;
                int n;
                fstream file;
                file.open("borrow.dat",ios::out|ios::in);
                while(!file.eof())
                {
                    pos = file.tellg();
                    file.read((char *)this,sizeof(borrow));
                    {
                        if(!(strcmp(dno,temp)))
                        {
                            cout<<"\tstudent department number:"<<dno<<endl;
                            cout<<"\tNo of books taken:"<<books_taken<<endl;
                            if(books_taken>0)
                            {
                                cout<<"\t\tbook no:"<<book_no1<<endl;
                                cout<<"\t\tbook no:"<<book_no2<<endl;
                            }
                            break;
                        }
                    }
                }
                cout<<"***************************************************"<<endl;
             //cout<<"Year:"<<year<<" "<<"Month:"<<month<<" "<< "Day:"<<day<<endl;
             cout<<"How many book you want to take"<<endl<<"\t1 book or  2 books :";
             cin>>n;
             if (n==1 && books_taken<2)
             {
                 if(!(strcmp(book_no1,"0000")))
                 {
                 borrow::time1();
                 cout<<"Enter book number:";
                 cin>>book_no1;
                 cout<<"  THANK YOU  "<<endl;
                 books_taken=books_taken+1;
                 }
                 else
                 {
                 borrow::time2();
                 cout<<"Enter book number:";
                 cin>>book_no2;
                 cout<<"  THANK YOU  "<<endl;
                 }

             }


             else if(n==2 && books_taken==0)
             {
                 borrow::time1();
                 cout<<"Enter first book number:";
                 cin>>book_no1;

                 borrow::time2();
                 cout<<"Enter second book number:";
                 cin>>book_no2;

                 cout<<"  THANK YOU  "<<endl;
                 books_taken=books_taken+2;
             }
             else
                cout<<"You can't take book"<<endl;
            file.seekg(pos);
            file.write((char *)this,sizeof(borrow));
            file.close();
            }

            void borrow :: book_taken_stud()
            {
                system("CLS");
                char temp[10];
                fstream file;
                cout<<"\t\t\t\t"<<"STUDENTS  WHO TAKE BOOKS FROM LIBRARY"<<endl;
                cout<<"*************************************************************************************************************"<<endl;
                cout<<"DEPARTMENT NUMBER\tNUMBER OF BOOKS TAKEN\tBOOK-1\t\tDATE\t\tBOOK-2\t\tDATE"<<endl;
                cout<<"*************************************************************************************************************"<<endl;
                file.open("borrow.dat",ios::in);
                while(!file.eof())
                {
                    file.read((char *)this,sizeof(borrow));
                    {
                        if(strcmp(dno,temp))
                        {
                          strcpy(temp,dno);
                          if(books_taken!=0)
                          cout<<dno<<"\t\t\t"<<books_taken<<"\t\t"<<book_no1<<"\t\t"<<day[0]<<"/"<<month[0]<<"/"<<year[0]<<"\t"<<book_no2<<"\t\t"<<day[1]<<"/"<<month[1]<<"/"<<year[1]<<endl;
                        }
                    }
                }
                file.close();
                cout<<"*************************************************************************************************************"<<endl;
            }

            void borrow::display(char *temp)
            {
                //int n;
                fstream file;
                file.open("borrow.dat",ios::in);
                while(!file.eof())
                {
                    file.read((char *)this,sizeof(borrow));
                    {
                        if(!(strcmp(dno,temp)))
                        {
                            cout<<"student department number:"<<dno<<endl;
                            cout<<"No of books taken:"<<books_taken<<endl;
                            if(books_taken>0)
                            {
                                cout<<"book no:"<<book_no1<<" "<<"Year:"<<year[0]<<" "<<"Month:"<<month[0]<<" "<< "Day:"<<day[0]<<endl;
                                cout<<"book no:"<<book_no2<<" "<<"Year:"<<year[1]<<" "<<"Month:"<<month[1]<<" "<< "Day:"<<day[1]<<endl;

                            }
                            cout<<"**********************************************"<<endl;
                            break;
                        }
                    }
                }
                file.close();

            }
void borrow:: return_book()
{
    char temp[10],bno[5];
    int fn;
    long pos;
    system("CLS");
    cout<<"Enter student id :";
    cin>>temp;
    fstream file;
    file.open("borrow.dat",ios::out|ios::in);
        while(!file.eof())
            {
                pos = file.tellg();
                file.read((char *)this,sizeof(borrow));
                    {
                        if(!(strcmp(dno,temp)))
                        {
                            cout<<"student department number:"<<dno<<endl;
                            cout<<"No of books taken:"<<books_taken<<endl;
                            if(books_taken>0)
                            {
                                cout<<"book no:"<<book_no1<<" "<<"Year:"<<year[0]<<" "<<"Month:"<<month[0]<<" "<< "Day:"<<day[0]<<endl;
                                cout<<"book no:"<<book_no2<<" "<<"Year:"<<year[1]<<" "<<"Month:"<<month[1]<<" "<< "Day:"<<day[1]<<endl;
                            }
                            break;
                        }
                    }
            }
            cout<<"Enter book number which you want to return :";
            cin>> bno;
            if (!(strcmp(book_no1,bno)))
            {
               fn=fine(year[0],month[0],day[0]);
               books_taken=books_taken-1;
               strcpy(book_no1,"0000");
               year[0]=0;
               month[0]=0;
               day[0]=0;
            }
            else if (!(strcmp(book_no2,bno)))
            {
               books_taken=books_taken-1;
               fn=fine(year[1],month[1],day[1]);
               strcpy(book_no1,"0000");
               year[0]=0;
               month[0]=0;
               day[0]=0;
            }
            else
                cout<<"Wrong entry"<<endl;
                fn=fn-15;
             file.seekg(pos);
             file.write((char *)this, sizeof(borrow));
             file.close();
                if(fn>0)
                    cout<<"your fine amount is "<<fn<<endl;
                else
                    cout<<"no fine"<<endl;

}
borrow::~borrow()
{
    //dtor
}
