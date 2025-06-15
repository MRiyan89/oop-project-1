#include<iostream>
#include "book.h"
using namespace std;
void Books :: show_all_books(){
    cout<<"\n     Book no. "<<book_no<<"\n\nName : "<<book_name<<"\nAuthor : "<<book_author<<"\nGenre : "<<book_type<<"\nCode : "<<book_code;
    str msg("Entire detail seen of book named: ");
    str msg2(msg + book_name);
    Logger::record(msg2);
    cin.get();
}

void Books::add_book() {
    if (a1 >= 10) {
        throw str("Maximum book limit reached");
    }
    char temp[100];
    cout<<"\n                   ADD BOOK NO. "<< book_no << " DETAIL'S";
    cout<<"\n\nEnter title of the book: ";
    cin.getline(temp, 100);
    book_name = temp;
    cout<<"\nEnter the Author name of that book: ";
    cin.getline(temp, 100);
    book_author = temp;
    cout<<"\nEnter the book genre: ";
    cin.getline(temp, 100);
    book_type = temp;
    cout<<"\nEnter the book code: ";
    cin.getline(temp, 100);
    book_code = temp;
    cout<<"\nBOOK DETAILS ADDED SUCCESSFULLY";
    str msg("A new book added named: ");
    str msg2(msg + book_name);
    Logger::record(msg2);
    cin.get();
}

void Books :: delete_book(Books* &b1){
    if (a1 <= 0) {
        throw str("No books available to delete");
    }
    str del_book;
    int index = 0;
    cout<<"\n                 DELETE BOOK";
    cout<<"\n\nEnter the book code or name to delete that book: ";
    char temp[100];
    cin.getline(temp, 100);
    del_book = temp;
    for(int i=0; i < a1; i++){
        if(b1[i].book_name == del_book || b1[i].book_code == del_book){
            index=i+1;
        }
    }

    if(index == 0){
        throw str("BOOK NOT FOUND!");
    }
    else{
        for(int i = index-1; i < a1-1; i++){
            b1[i]=b1[i+1];
            b1[i].book_no=i+1;
        }
        a1--;
        cout<<"\nBOOK DELETED SUCCESSFULLY: ";
    }
    str msg("deleted record of book named: ");
    str msg2(msg + book_name);
    Logger::record(msg2);
}

void Books :: search_book(Books* &b1){
    if (a1 <= 0) {
        throw str("No books available to search");
    }
    str ser_book;
    bool flag = 0;

    cout<<"\n               SEARCH A BOOK";
    cout<<"\n\nEnter book code or name to search : ";
    char temp[100];
    cin.getline(temp, 100);
    ser_book = temp;
    for(int i=0; i<a1; i++){
        if(ser_book == b1[i].book_code || ser_book == b1[i].book_name){
            b1[i].show_all_books();
            flag = 1;
        }
    }
    if(flag == 0){
        throw str("BOOK NOT FOUND!");
    }
    else{
        str msg("Searched for a book named: ");
        str msg2(msg + book_name);
        Logger::record(msg2);
        }
}

void Books :: modify_book(Books* &b1){
    if (a1 <= 0) {
        throw str("No books available to modify");
    }
    str mod_book;
    bool flag = 0;
    cout<<"\n             MODIFY A BOOK";
    cout<<"\n\nEnter book code or name to modify : ";
    char temp[100];
    cin.getline(temp, 100);
    mod_book = temp;
    for(int i=0; i<a1; i++){
        if(mod_book == b1[i].book_code || mod_book == b1[i].book_name){
            b1[i].add_book();
            flag = 1;
            cout<<"\nBOOK "<<b1[i].book_no<<" SUCCESSFULLY MODIFIED: ";
            str msg("Modified a book named: ");
            str msg2(msg + book_name);
            Logger::record(msg2);
            cin.get();
        }
    }
    if(flag == 0){
        throw str("BOOK NOT FOUND!");
    }
    
}
void Books :: serialize(fstream& f) {
    char* temp= nullptr;
    f.write((char*)&book_no, sizeof(int));
    int len = book_name.amount();
    temp=new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = book_name[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    len = book_author.amount();
    delete[] temp;
    temp = new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = book_author[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    
    len = book_type.amount();
    delete[] temp;
    temp = new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = book_type[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    
    len = book_code.amount();
    delete[] temp;
    temp = new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = book_code[i];
    }
    temp[len]='\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    delete[] temp;
}

void Books :: deserialize(fstream& f) {
    f.read((char*)&book_no, sizeof(int));
    int len;
    f.read((char*)&len, sizeof(int));
    char* temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    book_name = temp;
    delete[] temp;
    f.read((char*)&len, sizeof(int));
    temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    book_author = temp;
    delete[] temp;
    f.read((char*)&len, sizeof(int));
    temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    book_type = temp;
    delete[] temp;
    f.read((char*)&len, sizeof(int));
    temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    book_code = temp;
    delete[] temp;
}