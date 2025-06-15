#include<iostream>
#include<fstream>
#include"global.h"
#include"singleton.h"
#include"login.h"
#include"menu.h"
#include"log.h"
using namespace std;

int a1 = 0;
int p1 = 0;
int l3 = 0;

int main(){
    Singleton *s = s->getInstance();
    Logger::initialize();
    int switch1 = 0;
    str msg("Program started.");
    Logger::record(msg);
    Menu m1;
    Login l2;

    Account *acc1 = new Account[10];
    Books *b1 = new Books[10];
    Librarian *l1 = new Librarian[10];
    try{
    s->read(acc1,b1,l1);}
    catch(const str& e){
        std::cout << "\nError: " << e << "\n";
    }
    do{
        str id, password;
        switch1 = l2.getter(acc1, l1);
        id = l2.getterId();
        password = l2.getterPassword();
        if(switch1==4){
            do {
                m1.librarian();
                cin>>switch1;
                cin.ignore();
                switch (switch1) {
                    case 1: {
                        try{
                        acc1[p1].account_no = p1+1;
                        acc1[p1].addAccount();
                        p1++;}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 2: {
                        try{
                        acc1->deleteAccount(acc1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 3: {
                        std::cout<<"\n   TOTAL ACCOUNTS : "<<p1;
                        for(int i=0; i<p1; i++){
                            std::cout<<"\n                       ACCOUNT DETAIL'S";
                            acc1[i].showAllAccount();
                        }
                        break;
                    }
                    case 4: {
                        try{
                        acc1->searchAccount(acc1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 5: {
                        try{
                        acc1->modifyAccount(acc1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 6: {
                        try{
                        b1[a1].book_no = a1+1;
                        b1[a1].add_book();
                        a1++;}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 7: {
                        try{
                        b1->delete_book(b1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 8: {
                        std::cout<<"\n   TOTAL BOOKS : "<<a1;
                        for(int i=0; i<a1; i++){
                            std::cout<<"\n               BOOK DETAIL'S";
                            b1[i].show_all_books();
                        }
                        break;
                    }
                    case 9: {
                        try{
                        b1->search_book(b1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 10: {
                        try{
                        b1->modify_book(b1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 11: {
                        switch1 = 0;
                        break;
                    }
                    case 12: {
                        switch1 = -1;
                        break;
                    }
                    default: {
                        std::cout<<"\nInvalid input!\n\nTry Again:\n";
                    }
                }
            }
            while(!(switch1==0 || switch1 == -1));
        }

        if(switch1==1 || switch1==2){
            int a = switch1;
            do{
                switch1 = a;
                if(switch1 == 1)
                    m1.student();
                else if(switch1 == 2)
                    m1.facultyMember();
                cin>>switch1;
                cin.ignore();
                switch (switch1){
                    case 1:{
                        int condition = 0;
                        try{
                            for (int i = 0; i < p1; i++){
                                if (acc1[i].account_id == id && acc1[i].account_password == password){
                                    if (acc1[i].account_type == "STUDENT"){
                                        str book;
                                        char temp[100];
                                        std::cout << "\nEnter Book name or code to issue: ";
                                        cin.getline(temp, 100);
                                        book = temp;
                                        for (int j = 0; j < a1; j++){
                                            if (book == b1[j].book_name || book == b1[j].book_code){
                                                if(acc1[i].book_no < 4){
                                                    acc1[i].book[acc1[i].book_no] = j;
                                                    acc1[i].book_no++;
                                                    std::cout << "\nBook issued successfully\n "
                                                            "\n\n           RECEIPT \n\n"
                                                            "Account Type : "<<acc1[i].account_type
                                                        <<"\nName : "<<acc1[i].account_name
                                                        <<"\nID   : "<<acc1[i].account_id
                                                        <<"\nNo. of book issues : "<<acc1[i].book_no
                                                        <<"\nBook Name : "<<b1[j].book_name
                                                        <<"\nBook Type : "<<b1[j].book_type
                                                        <<"\nBook Code : "<<b1[j].book_code;
                                                    condition = 1;
                                                }
                                                else{
                                                    condition =1;
                                                    throw str("Book Issue Limit Exceed!");
                                                    
                                                }
                                            }
                                        }
                                    }
                                    else{
                                        str book;
                                        char temp[100];
                                        std::cout << "\nEnter Book name or code to issue: ";
                                        cin.getline(temp, 100);
                                        book = temp;
                                        for (int j = 0; j < a1; j++){
                                            if (book == b1[j].book_name || book == b1[j].book_code){
                                                if(acc1[i].book_no < 10){
                                                    acc1[i].book[acc1[i].book_no] = j;
                                                    acc1[i].book_no++;
                                                    std::cout << "\nBook issued successfully\n "
                                                            "\n\n          RECEIPT \n\n"
                                                            "Account Type : "<<acc1[i].account_type
                                                        <<"\nName : "<<acc1[i].account_name
                                                        <<"\nID   : "<<acc1[i].account_id
                                                        <<"\nNo. of book issues : "<<acc1[i].book_no
                                                        <<"\nBook Name : "<<b1[j].book_name
                                                        <<"\nBook Type : "<<b1[j].book_type
                                                        <<"\nBook Code : "<<b1[j].book_code;

                                                    condition = 1;
                                                }
                                                else{
                                                    condition =1;
                                                    throw str("Book Issue Limit Exceed!");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if(condition == 0){
                                throw str("Book is not available");
                            }
                        }
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        cin.get();
                        break;
                    }
                    case 2:{
                        int condition =0;
                        try{
                            for (int i = 0; i < p1; i++){
                                if (acc1[i].account_id == id && acc1[i].account_password == password){
                                    if (acc1[i].account_type == "STUDENT" || acc1[i].account_type == "FACULTY MEMBER"){
                                        str book;
                                        char temp[100];
                                        std::cout<<"\nEnter Book name or code to return: ";
                                        cin.getline(temp, 100);
                                        book = temp;
                                        for(int j =0 ;j<a1; j++){
                                            if(b1[j].book_name == book || b1[j].book_code == book){
                                                if(acc1[i].book_no==1){
                                                    if(acc1[i].book[0]==j){
                                                        acc1[i].book[0]=0;
                                                        condition = 1;
                                                        acc1[i].book_no--;
                                                        std::cout<<"\nBook returned successfully\n";
                                                    }
                                                }
                                                for(int k=0;k<acc1[i].book_no-1;k++){
                                                    if(acc1[i].book[k]==j){
                                                        acc1[i].book[k]=acc1[i].book[k+1];
                                                        condition = 1;
                                                        acc1[i].book_no--;
                                                        std::cout<<"\nBook returned successfully\n";
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if(condition==0){
                                throw str("This Book is never issued!");
                            }
                        }
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        cin.get();
                        break;
                    }

                    case 3:{
                        int condition = 0;
                        for (int i = 0; i < p1; i++){
                            if (acc1[i].account_id == id && acc1[i].account_password == password){
                                if (acc1[i].account_type == "STUDENT" || acc1[i].account_type == "FACULTY MEMBER"){
                                    for(int k=0; k<acc1[i].book_no; k++){
                                        std::cout<<"\n\nBook Issued : " << k+1<<endl;
                                        b1[acc1[i].book[k]].show_all_books();
                                        condition = 1;
                                    }
                                }
                            }
                        }
                        try{
                            if(condition==0){
                                std::cout<<"\nNo, Book issued yet!: \n";
                            }
                        }
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        cin.get();
                        break;
                    }

                    case 4: {
                        switch1 = 0;
                        break;
                    }
                    case 5: {
                        switch1 = -1;
                        break;
                    }
                    default:{
                        std::cout<<"\nInvalid input!\n\nTry Again:\n";
                    }
                }
            }
            while(!(switch1==0 || switch1 == -1));
        }

        if(switch1==3){
            do {
                m1.admin();
                cin>>switch1;
                cin.ignore();
                switch (switch1) {
                    case 1: {
                        try{
                            l1[l3].librarian_no = l3+1;
                            l1[l3].addLibrarain();
                            l3++;
                        }
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 2: {
                        try{
                        l1->deleteLibrarain(l1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 3: {
                        try{
                        l1->searchLibrarain(l1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 4: {
                        try{
                        l1->modifyLibrarain(l1);}
                        catch(const str& e){
                            std::cout << "\nError: " << e << "\n";
                        }
                        break;
                    }
                    case 5: {
                        std::cout<<"\n   TOTAL Librarians : "<<l3;
                        for(int i=0; i<l3; i++){
                            std::cout<<"\n                 Librarian DETAIL'S";
                            l1[i].showAllLibrarain();
                        }
                        break;
                    }
                    case 6: {
                        switch1 = 0;
                        break;
                    }
                    case 7: {
                        switch1 = -1;
                        break;
                    }
                    default:{
                        std::cout<<"\nInvalid input!\n\nTry Again:\n";
                        break;
                    }
                }
            }
            while(!(switch1==0 || switch1 == -1));
        }
    }
    while(!(switch1 == -1));
    try{
        s->write(acc1,b1,l1);
    }
    catch(const str& e){
        std::cout << "\nError: " << e << "\n";
    }
    delete[] acc1;
    delete[] b1;
    delete[] l1;
    Logger::record("Program ended");
    Logger::close();
    return 0;
}