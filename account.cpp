#include<iostream>
#include "account.h"
using namespace std;
void Account :: showAllAccount(){
    cout<<"\n     Account NO. "<<account_no<<"\n\nNAME : "<<account_name<<"\nType : "<<account_type<<"\nID : "<<account_id<<"\nPASSWORD : "<<account_password;
    cin.get();
}

void Account :: addAccount(){
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
        if(a==1)
            account_type = "STUDENT";
        else if(a==2)
            account_type = "FACULTY MEMBER";
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
        cout<<"ACCOUNT NOT FOUND!";
        cin.get();
    }
    else{
        for(int i=index-1; i<p1-1; i++){
            b1[i]=b1[i+1];
            b1[i].account_no=i+1;
        }
        p1--;
        cout<<"\nACCOUNT DELETED SUCCESSFULLY: ";
    }
}

void Account ::searchAccount(Account *& b1){
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
            flag = 1;
        }
    }
    if( flag == 0){
        cout<<"\nACCOUNT NOT FOUND!";
        cin.get();
    }
}

void Account ::modifyAccount(Account *& b1){
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
            cin.get();
        }
    }
    if(flag == 0){
        cout<<"\nACCOUNT NOT FOUND!";
        cin.get();
    }
}