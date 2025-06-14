#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <fstream>
#include "str.h"
#include "global.h"
#include"log.h"
using namespace std;
class Account{
public:
    str account_name, account_type, account_id, account_password;
    int account_no = 0 ,book_no = 0;
    int book[10];
    void addAccount();
    void deleteAccount(Account* &);
    void searchAccount(Account* &);
    void modifyAccount(Account* &);
    void showAllAccount();
    void serialize(fstream& f);
    void deserialize(fstream& f);
};
#endif