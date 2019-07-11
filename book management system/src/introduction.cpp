#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include<iomanip>
#include <stdlib.h>
#include "introduction.h"
#include "borrow.h"
#include "book.h"
#include "student.h"

using namespace std;


int introduction :: intro()
        {
            int n;

        do{
            cout<<"**********************************************************************************************************"<<endl;
            cout<<"\t\t\t"<<"          WELCOME TO BOOK MANAGMENT SYSTEM"<<endl;
            cout<<"**********************************************************************************************************"<<endl;
            cout<<"\t0.   INFO ABOUT THE APPLICATION"<<endl;
            cout<<"\t1.   CREATE STUDENT ACCOUNT"<<endl;
            cout<<"\t2.   ADD BOOK"<<endl;
            cout<<"\t3.   EDIT STUDENT ACCOUNT"<<endl;
            cout<<"\t4.   UPDATE BOOK DETAILS"<<endl;
            cout<<"\t5.   TO GET A BOOK FROM LIBRARY"<<endl;
            cout<<"\t6.   TO DISPLAY STUDENTS INFORMATION"<<endl;
            cout<<"\t7.   TO DISPLAY BOOK DETAILS"<<endl;
            cout<<"\t8.   RETURN BOOK TO LIBRARY"<<endl;
            cout<<"\t9.   STUDENT LISTS"<<endl;
            cout<<"\t10.  BOOK LIST"<<endl;
            cout<<"\t11.  DISPLAY THE STUDENT LIST WHO HAVE TAKEN BOOKS"<<endl;
            cout<<"\t12.  Exit"<<endl;
            cout<<"************************************************************************************************************"<<endl;
            cout<<"Enter your option :";

            cin>>n;


            if(n==1){
                 student::enter_details1();
                 getch();
                 system("CLS");
                 //break;
                 }

            else if(n==2){
              book::enter_details();
              getch();
              system("CLS");
              //break;
              }

            else if(n==3){
              student::edit();
              getch();
              system("CLS");
              //break;
            }

            else if(n==4){
              book::edit();
              getch();
              system("CLS");
              //break;
              }

            else if(n==5){
               borrow::get_book();
               getch();
               system("CLS");
               //break;
               }

            else if(n==6){
              student :: dispaly2();
              getch();
              system("CLS");
              //break;
              }

            else if(n==7){
                book::dispaly();
                getch();
                system("CLS");
                //break;
                }

            else if(n==8){
                borrow::return_book();
                getch();
                system("CLS");
                //break;
                }

            else if(n==9){
                student::student_list();
                getch();
                system("CLS");
                //break;
            }

            else if(n==10){
                book::list_book();
                getch();
                system("CLS");
                //break;
            }
            else if(n==11){
                borrow::book_taken_stud();
                getch();
                system("CLS");
                //break;
            }
            else if(n==12)
                break;

            else if(n==13)
            {
                system("CLS");
                cout<<"**************************************************************************************************"<<endl;
                cout<<"                            WELCOME TO BOOK MANAGEMENT SYSTEM"<<endl;
                cout<<"**************************************************************************************************"<<endl<<endl;
                cout<<"\tThis Application is used to maintain books in the library ,it also record students list,"<<endl<<"\t  number of ";
                cout<<"books in library and fine details of the student."<<endl<<endl;
                cout<<"\tSome Important Details."<<endl;
                cout<<"\t     * Student can take only two books at a time."<<endl;
                cout<<"\t     * Only after returns the book they can able to take anther book."<<endl;
                cout<<"\t     * Student can keep the book for only 15 days."<<endl;
                cout<<"\t     * If the student doesn't return the book within 15 days, They have to pay fine."<<endl;
                //cout<<"\t     * The Fine Calculated as per below details."<<endl;
                cout<<"\t     * After 15 days, per day one rupee fine should be payed."<<endl;
                cout<<"**************************************************************************************************"<<endl;
                cout<<"\t\t\t\t\t\t\t\t By :"<<endl;
                cout<<"\t\t\t\t\t\t\t\t        A.R.JUDE HARRIS"<<endl;
                cout<<"\t\t\t\t\t\t\t\t        17PCA108"<<endl;
                cout<<"**************************************************************************************************"<<endl;
                getch();
                system("CLS");
            }

            else if(n==0)
            {
                cout<<"Wrong Input"<<endl;
                break;
            }

            else{
                cout<<"Wrong input "<<endl;
                getch();
                system("CLS");
                //break;
            }
          }
          while(1);
           cout<<"The value of n is : "<<n;
           return(n);
           getch();
        }

introduction::~introduction()
{
    //dtor
}
