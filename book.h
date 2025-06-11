#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include "global.h"
#include"str.h"
using namespace std;
class Books
{
public:
    str book_name, book_author, book_type, book_code;
    int book_no = 0;
    void add_book();
    void delete_book(Books* &);
    void search_book(Books* &);
    void modify_book(Books* &);
    void show_all_books();
};
#endif