#include<iostream>
using namespace std;
#include"str.h"

int str::leng(const char* ptr)const {
	int count = 0;
	for (int i = 0; ptr[i] != '\0'; i++) {
		count++;
	}
	return count;
}

int str::amount()const {
    int count = 0;
    for (int i = 0; this->ptr[i] != '\0'; i++) {
        count++;
    }
    return count;
}
str::str() {
	//cout << "default constructor" << endl;
	caps = 0;
	size = 0;
	ptr = NULL;
}
str::str(const str& s) {
	//cout << "copy constructor" << endl;
	int len = leng(s.ptr);
	this->ptr = new char[len];
	this->caps = len;
	this->size = len;
	for (int i = 0; i < len; i++) {
		this->ptr[i] = s.ptr[i];
	}
	this->ptr[size] = '\0';
}
str::str(const char* ptr) {
	int len = leng(ptr);
	this->caps = len;
	this->size = len;
	this->ptr = new char[len];
	for (int i = 0; i < len; i++) {
		this->ptr[i] = ptr[i];
	}
	this->ptr[size] = '\0';
}
str::str(char a) {
	this->ptr = new char[1];
	this->size = 1;
	this->caps = 1;
	this->ptr[0] = a;
}
str& str:: operator=(const str& s1) {
	this->ptr = nullptr;
	this->size = s1.size;
	this->caps = s1.caps;
	this->ptr = new char[s1.size];
	for (int i = 0; i < this->size; i++) {
		this->ptr[i] = s1.ptr[i];
	}
	this->ptr[size] = '\0';
	return *this;
}
char str::operator[](int index)const {
	return this->ptr[index];
}
char& str::operator[](int index) {
	return this->ptr[index];
}
ostream& operator<<(ostream& os, const str& s) {
	for (int i = 0; i < s.size; i++) {
		cout << s.ptr[i];
	}
	return os;
}
istream& operator>>(istream& is, str& s) {
    char temp[1000];
    is >> temp;
    s = str(temp);
    return is;
}

int str::stoi() {
	int res = 0;
	for (int i = 0; i < this->size; i++) {
		res * 10;
		res = res + (this->ptr[i] - '0');
	}
	return res;
}

void str::itos(int n) {
	int count = 0, temp = n;
	str res;
	while (n > 0) {
		count++;
		n = n / 10;
	}
	this->size = count;
	this->caps = count;
	this->ptr = new char[count];
	for (int i = count - 1; i >= 0; i--) {
		this->ptr[i] = (temp % 10) + '0';
		temp = temp / 10;
	}
}
void str::trim() {

	for (int i = size - 1; i >= 0; i--) {

		if (this->ptr[i] == ' ') {
			for (int j = i; j < size - 1; j++) {
				this->ptr[j] = this->ptr[j + 1];
			}
			this->size--;
		}
	}
	this->ptr[size] = '\0';
}
str str::trim(const char* ptr) {
	str res(ptr);
	res.trim();
	return res;
}
bool str::operator==(const str& s) {
	if (this->size != s.size) {
		return false;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->ptr[i] != s.ptr[i]) {
			return false;
		}
	}
	return true;
}

bool str::operator!=(const str& s) {
    if (this->size != s.size) {
        return true;
    }
    for (int i = 0; i < this->size; i++) {
        if (this->ptr[i] != s.ptr[i]) {
            return true;
        }
    }
    return false;
}

str str ::operator+(const str& s) {
	str res;
	res.size = this->size + s.size;
	res.caps = this->caps + s.caps;
	res.ptr = new char[res.size];
	for (int i = 0; i < this->size; i++) {
		res.ptr[i] = this->ptr[i];
	}
	for (int i = 0; i < s.size; i++) {
		res.ptr[i + this->size] = s.ptr[i];
	}
	return res;
}
str& str ::operator+=(const str& s) {
	str res;
	res.size = this->size + s.size;
	res.caps = this->caps + s.caps;
	res.ptr = new char[res.size];
	for (int i = 0; i < this->size; i++) {
		res.ptr[i] = this->ptr[i];
	}
	for (int i = 0; i < s.size; i++) {
		res.ptr[i + this->size] = s.ptr[i];
	}
	*this = res;

	return *this;

}
str::~str() {
    delete[] this->ptr;
}