#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
#include<fstream>
#include "str.h"
#include "global.h"
#include"book.h"
#include"account.h"
#include"librarian.h"
using namespace std;
class Singleton {
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance();
    void write(Account* &a2, Books* &b1, Librarian* &l1);
    void read(Account* &a2, Books* &b1, Librarian* &l1);
};
#endif