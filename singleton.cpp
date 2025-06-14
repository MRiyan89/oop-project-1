#include<iostream>
#include"singleton.h"
using namespace std;

Singleton* Singleton::instance = nullptr;

Singleton* Singleton :: getInstance() {
    if (!instance) {
        instance = new Singleton();
    }
    return instance;
}

void Singleton :: write(Account* &a2, Books* &b1, Librarian* &l1) {
    fstream f("data.bin", ios::out | ios::binary);
    if (!f.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    f.write((char*)&p1, sizeof(int));
    for (int i = 0; i < p1; i++) {
        a2[i].serialize(f);
    }
    f.write((char*)&a1, sizeof(int));
    for (int i = 0; i < a1; i++) {
        b1[i].serialize(f);
    }
    f.write((char*)&l3, sizeof(int));
    for (int i = 0; i < l3; i++) {
        l1[i].serialize(f);
    }
    f.close();
}
void Singleton :: read(Account* &a2, Books* &b1, Librarian* &l1) {
    fstream f("data.bin", ios::in | ios::binary);
    if (!f.is_open()) {
        cerr << "No existing data file found, starting fresh" << endl;
        return;
    }
    f.read((char*)&p1, sizeof(int));
    for (int i = 0; i < p1; i++) {
        a2[i].deserialize(f);
    }
    f.read((char*)&a1, sizeof(int));
    for (int i = 0; i < a1; i++) {
        b1[i].deserialize(f);
    }
    f.read((char*)&l3, sizeof(int));
    for (int i = 0; i < l3; i++) {
        l1[i].deserialize(f);
    }
    f.close();
}