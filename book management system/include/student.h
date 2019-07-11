#ifndef STUDENT_H
#define STUDENT_H


// STUDENT CLASS
class student
{
    char d_no[10];
    char name[20];
    char department[20];
    char dob[12];
 public:

    student(){}
    student(char *n,char *d,char *dep,char *dp);
    student(student &a);
    void enter_details1();
    void dispaly2();
    void edit();
    void student_list();
    ~student();
    };

#endif // STUDENT_H
