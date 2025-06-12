#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include "str.h"
#include "admin.h"
#include "account.h"
#include "librarian.h"
using namespace std;
class Login : public Admin{
    str id , password;
public:
    int getter( Account* &, Librarian* &);
    str getterId();
    str getterPassword();
};
#endif