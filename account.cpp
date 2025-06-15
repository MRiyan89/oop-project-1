#include<iostream>
#include "account.h"
using namespace std;
void Account :: showAllAccount(){
    cout<<"\n     Account NO. "<<account_no<<"\n\nNAME : "<<account_name<<"\nType : "<<account_type<<"\nID : "<<account_id<<"\nPASSWORD : "<<account_password;
    str msg("Entire detail seen of account named: ");
    str msg2(msg + account_name);
    Logger::record(msg2);
    cin.get();
}

void Account :: addAccount(){
    if (p1 >= 10) {
        throw str("Maximum account limit reached");
    }
    int a = 0;
    char temp[100];
    cout<<"\n               ADD ACCOUNT NO. "<<account_no<< " DETAIL'S";
    cout<<"\n\nEnter Name of the person: ";
    cin.getline(temp, 100);
    account_name = temp;
    do{
        cout<<"\nEnter Type of the person: \n1- STUDENT\n2- FACULTY MEMBER : ";
        cin>>a;
        cin.ignore();
        if(a==1){
            account_type = "STUDENT";
            str msg("A new student account added named: ");
            str msg2(msg + account_name);
            Logger::record(msg2);}
        else if(a==2){
            account_type = "FACULTY MEMBER";
            str msg("A new faculty account added named: ");
            str msg2(msg + account_name);
            Logger::record(msg2);}
        else{
            cout<<"Wrong input!";
            a=0;
        }
    }while(a==0);
    cout<<"\nEnter ID of the person: ";
    cin.getline(temp, 100);
    account_id = temp;
    cout<<"\nEnter their Password: ";
    cin.getline(temp, 100);
    account_password = temp;
    cout<<"\nACCOUNT DETAILS ADDED SUCCESSFULLY";
    cin.get();
}

void Account :: deleteAccount(Account* &b1){
    if (p1 <= 0) {
        throw str("No accounts available to delete");
    }
    char temp[100];
    str del_account;
    int index = 0;
    cout<<"\n                 DELETE ACCOUNT";
    cout<<"\n\nEnter the person ID or Name to delete that account: ";
    cin.getline(temp, 100);
    del_account = temp;
    for(int i=0; i < p1; i++){
        if(b1[i].account_name==del_account || b1[i].account_id==del_account){
            index=i+1;
        }
    }
    if(index == 0){
        throw str("Account not found!");
    }
    else{
        for(int i=index-1; i<p1-1; i++){
            b1[i]=b1[i+1];
            b1[i].account_no=i+1;
        }
        p1--;
        cout<<"\nACCOUNT DELETED SUCCESSFULLY: ";
    }
    str msg("deleted record of an acocunt named: ");
    str msg2(msg + account_name);
    Logger::record(msg2);
}

void Account ::searchAccount(Account *& b1){
    if (p1 <= 0) {
        throw str("No accounts available to search");
    }
    char temp[100];
    str ser_account;
    bool flag = 0;
    cout<<"\n                 SEARCH AN ACCOUNT";
    cout<<"\n\nEnter person ID or name to search : ";
    cin.getline(temp, 100);
    ser_account = temp;
    for(int i=0; i<p1; i++){
        if(ser_account == b1[i].account_name || ser_account == b1[i].account_id){
            b1[i].showAllAccount();
            str msg("Searched for an account named: ");
            str msg2(msg + account_name);
            Logger::record(msg2);
            flag = 1;
        }
    }
    if( flag == 0){
        throw str("Account not found!");
    }
}

void Account ::modifyAccount(Account *& b1){
    if (p1 <= 0) {
        throw str("No accounts available to modify");
    }
    char temp[100];
    str mod_account;
    bool flag = 0;
    cout<<"\n                    MODIFY AN ACCOUNT";
    cout<<"\n\nEnter person ID or name to modify : ";
    cin.getline(temp, 100);
    mod_account = temp;
    for(int i=0; i<p1; i++){
        if(mod_account == b1[i].account_id || mod_account == b1[i].account_name){
            b1[i].addAccount();
            flag = 1;
            cout<<"\nACCOUNT "<<b1[i].account_no<<" SUCCESSFULLY MODIFIED: ";
            str msg("Modified an account named: ");
            str msg2(msg + account_name);
            Logger::record(msg2);
            cin.get();
        }
    }
    if(flag == 0){
        throw str("ACCOUNT NOT FOUND!");
    }
}

void Account :: serialize(fstream& f) {
    char* temp = nullptr;
    f.write((char*)&account_no, sizeof(int));
    f.write((char*)&book_no, sizeof(int));
    int len = account_name.amount();
    temp=new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = account_name[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    len = account_type.amount();
    delete[] temp;
    temp=new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = account_type[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    len = account_id.amount();
    delete[] temp;
    temp=new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = account_id[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    len = account_password.amount();
    delete[] temp;
    temp=new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = account_password[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    delete[] temp;
    for(int i = 0; i < book_no; i++) {
        f.write((char*)&book[i], sizeof(int));
    }
}

void Account :: deserialize(fstream& f) {
    f.read((char*)&account_no, sizeof(int));
    f.read((char*)&book_no, sizeof(int));
    int len;
    f.read((char*)&len, sizeof(int));
    char* temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    account_name = temp;
    delete[] temp;
    f.read((char*)&len, sizeof(int));
    temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    account_type = temp;
    delete[] temp;
    f.read((char*)&len, sizeof(int));
    temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    account_id = temp;
    delete[] temp;
    f.read((char*)&len, sizeof(int));
    temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    account_password = temp;
    delete[] temp;
    for(int i = 0; i < book_no; i++) {
        f.read((char*)&book[i], sizeof(int));
    }
}