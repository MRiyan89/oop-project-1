#ifndef LOG_H
#define LOG_H
#include<iostream>
#include<fstream>
#include"str.h"
using namespace std;
class Logger {
private:
    static ofstream logfile;
public:
    static void initialize();
    static void record(const str& message);
    static void close();
};
#endif