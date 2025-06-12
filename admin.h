#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "str.h"
using namespace std;
class Admin{
protected:
    str ID , Password;
public:
    Admin(){
        ID = "t";
        Password = "t";
    };
};
#endif