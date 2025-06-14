#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <iostream>
#include<fstream>
#include "global.h"
#include "str.h"
#include"log.h"
using namespace std;
class Librarian
{
public:
    str librarian_name, librarian_id, librarain_password;
    int librarian_no = 0;
    void addLibrarain();
    void deleteLibrarain(Librarian* &);
    void searchLibrarain(Librarian* &);
    void modifyLibrarain(Librarian* &);
    void showAllLibrarain();
    void serialize(fstream& f);
    void deserialize(fstream& f);
};
#endif