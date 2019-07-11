#ifndef BORROW_H
#define BORROW_H


// BORROW CLASS TO GET BOOK AND RETURN BOOK TO LIBARY
class borrow
        {
              char dno[10];
              int books_taken;
              char book_no1[5];
              char book_no2[5];
              int year[2];
              int month[2];
              int day[2];
        public:

            borrow();
            void set1(char *a);
            void get_book();
            void display(char *temp);
            void time1();
            void time2();
            void return_book();
            void book_taken_stud();
            int fine(int yr,int mon,int d);
            ~borrow();
            //friend class student;
        };

#endif // BORROW_H
