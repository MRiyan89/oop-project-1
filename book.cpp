#include<iostream>
#include "book.h"
using namespace std;
void Books :: show_all_books(){
    cout<<"\n     Book no. "<<book_no<<"\n\nName : "<<book_name<<"\nAuthor : "<<book_author<<"\nGenre : "<<book_type<<"\nCode : "<<book_code;
    cin.get();
}

void Books::add_book() {
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
    cin.get();
}

void Books :: delete_book(Books* &b1){
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
        cout<<"BOOK NOT FOUND!";
        cin.get();
    }
    else{
        for(int i = index-1; i < a1-1; i++){
            b1[i]=b1[i+1];
            b1[i].book_no=i+1;
        }
        a1--;
        cout<<"\nBOOK DELETED SUCCESSFULLY: ";
    }
}

void Books :: search_book(Books* &b1){
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
        cout<<"\nBOOK NOT FOUND!";
        cin.get();
    }
}

void Books :: modify_book(Books* &b1){
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
            cin.get();
        }
    }
    if(flag == 0){
        cout<<"\nBOOK NOT FOUND!";
        cin.get();
    }
}