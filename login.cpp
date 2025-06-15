#include<iostream>
#include "login.h"
#include"menu.h"
#include"global.h"
using namespace std;
str Login :: getterId(){
    return id;
}

str Login ::getterPassword() {
    return password;
}

int Login :: getter( Account* &a3 ,Librarian* &l1){
    str temp;
    cout<<"\n                 WELCOME TO THE LIBRARY\n\n";
    cout<<"Enter your ID Number: ";
    cin>>temp;
    id = temp;
    cout<<"\nEnter your password: ";
    cin>>temp;
    password = temp;
    Menu m1;
    int condition = 0;
    for(int i=0; i<p1; i++){
        if(a3[i].account_id == id && a3[i].account_password == password){
            if(a3[i].account_type=="STUDENT"){
                return 1;
            }
            else if(a3[i].account_type=="FACULTY MEMBER")
                return 2;
        }
    }
    if(ID == id && Password == password)
        return 3;
    for(int i=0; i<l3; i++){
        if(l1[i].librarian_id == id && l1[i].librarain_password == password){
            return 4;
        }
    }
    if(condition == 0){
        cout<<"\nInvalid Input!";
    }
    return 0;
}