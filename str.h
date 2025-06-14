#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class str {
	char* ptr;
	int size;
	int caps;
public:
	//int leng(int n);
	int leng(const char* ptr)const;
	str();
	str(const str& s);
	str(const char* ptr);
	str(char a);
    int amount()const;
    str appendind(const str& s) {
        return *this + s;
    }
    char* getPtr() const { return ptr; }
	str& operator=(const str& s);
	char operator[](int index)const;
	char& operator[](int index);
	bool operator==(const str& s);
	str operator +(const str& s);
	str& operator +=(const str& s);
	friend ostream& operator<< (ostream& os, const str& s);
    friend istream& operator>>(istream& is, str& s);

	int stoi();
	void itos(int n);
	void trim();
	str trim(const char* ptr);
    ~str();
};
#endif