#ifndef BOOK_H
#define BOOK_H


//BOOK CLASS
  class book
  {

      char bno[10];
      char bname[25];
      char author[20];
      char edition[10];
      int year_pub;
      int price;
      int copies;

  public:
    void edit();
    void enter_details();
    void dispaly();
    void list_book();
    ~book();
  };

#endif // BOOK_H
