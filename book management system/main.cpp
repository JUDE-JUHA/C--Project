
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include<iomanip>
#include <stdlib.h>
#include "borrow.h"
#include "student.h"
#include "book.h"
#include "introduction.h"

using namespace std;

void info()
{
    system("CLS");
                cout<<"**************************************************************************************************"<<endl;
                cout<<"                             WELCOME TO BOOK MANAGEMENT SYSTEM"<<endl;
                cout<<"**************************************************************************************************"<<endl<<endl;
                cout<<"\tThis Application is used to maintain books in the library ,it also record students list,"<<endl<<"\t  number of ";
                cout<<"books in library and fine details of the student."<<endl<<endl;
                cout<<"\tSome Important Details."<<endl;
                cout<<"\t     * Student can take only two books at a time."<<endl;
                cout<<"\t     * Only after returns the book they can able to take anther book."<<endl;
                cout<<"\t     * Student can keep the book for only 15 days."<<endl;
                cout<<"\t     * If the student doesn't return the book within 15 days, They have to pay fine."<<endl;
                //cout<<"\t     * The Fine calculated as per below details."<<endl;
                cout<<"\t     * After 15 days, per day one rupee fine should be payed."<<endl;
                cout<<"**************************************************************************************************"<<endl;
                cout<<"\t\t\t\t\t\t\t\t By :"<<endl;
                cout<<"\t\t\t\t\t\t\t\t        A.R.JUDE HARRIS"<<endl;
                cout<<"\t\t\t\t\t\t\t\t        17PCA108"<<endl;
                cout<<"**************************************************************************************************"<<endl;
                getch();
                system("CLS");
}
int main()
{
  info();
  introduction i;
  int n;
    n=i.intro();
    if (n==0)
        main();
    //student s;
    //s.dispaly2();
    return 0;
}
