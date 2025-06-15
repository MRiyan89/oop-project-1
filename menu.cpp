#include<iostream>
#include"menu.h"
using namespace std;
void Menu :: admin(){
    cout<<"\n                  ADMIN PORTAL \n\n";
    cout<<"           'Choose a Number'\n";
    cout<<"1- Add an Librarian account\n";
    cout<<"2- Delete an Librarian account\n";
    cout<<"3- Search an Librarian account\n";
    cout<<"4- Modify an Librarian account\n";
    cout<<"5- Show all Librarian accounts Details\n";
    cout<<"6- go back to main menu \n";
    cout<<"7- exit from code\nYour choice: ";
    
}

void Menu :: student(){
    cout<<"\n                    STUDENT PORTAL\n\n";
    cout<<"           'Choose a Number'\n";
    cout<<"Choose '1' for book issue\n";
    cout<<"Choose '2' for book return\n";
    cout<<"Choose '3' to get details of issued books\n";
    cout<<"Choose '4' to go back to main menu\n";
    cout<<"Choose '5' to exit from code\nYour choice: ";
}

void Menu :: librarian(){
    cout<<"\n                 LIBRARIAN PORTAL\n\n";
    cout<<"           'Choose a Number'\n";
    cout<<"1- Add an account\n";
    cout<<"2- Delete an account\n";
    cout<<"3- Show all accounts Details\n";
    cout<<"4- Search an account\n";
    cout<<"5- Modify an account\n";
    cout<<"6- Add a book\n";
    cout<<"7- Delete a book\n";
    cout<<"8- Show all books Details\n";
    cout<<"9- Search a book\n";
    cout<<"10- Modify a book\n";
    cout<<"11- To go back to main menu: \n";
    cout<<"12- To exit from code\nYour choice: ";
}

void Menu :: facultyMember(){
    cout<<"\n                  FACULTY PORTAL\n\n";
    cout<<"           'Choose a Number'\n";
    cout<<"Choose '1' for book issue\n";
    cout<<"Choose '2' for book return\n";
    cout<<"Choose '3' to get details of issued books\n";
    cout<<"Choose '4' to go back to main menu\n";
    cout<<"Choose '5' to exit from code\nYour choice: ";
}