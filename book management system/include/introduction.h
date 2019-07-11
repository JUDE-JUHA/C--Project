#ifndef INTRODUCTION_H
#define INTRODUCTION_H
#include "borrow.h"
#include "book.h"
#include "student.h"


class introduction : public student ,public book ,public borrow
    {
        public:
            int intro();
            ~introduction();
    };

#endif // INTRODUCTION_H
