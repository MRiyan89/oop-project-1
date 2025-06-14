#include<iostream>
#include<fstream>
#include "log.h"
using namespace std;

ofstream Logger::logfile;

void Logger::initialize() {
    //cout << "Initializing log file..." << endl;
    logfile.open("log.txt", ios::app);
    //cout << "Log file opened." << endl;
    if (!logfile.is_open()) {
        //cout << "ni chal raha j" << endl;
        cerr << "Error: Could not open log file." << endl;
    } 
    else {
        //cout << "Log file is open." << endl;
        logfile << "\nLog file initialized.\n";
    }
}

void Logger::record(const str& message) {
    const char* temp = message.getPtr();
    if (!temp) {
        cerr << "Error: Attempted to log an empty message." << endl;
        return;
    }

    if (logfile.is_open()) {
        for (int i = 0; i < message.amount(); i++) {
            logfile << temp[i];
            //cout << temp[i];
        }
        logfile << endl;
    } else {
        cerr << "Error: Log file is not open.\n";
    }
}

void Logger::close() {
    if (logfile.is_open()) {
        //cout << "Closing log file..." << endl;
        logfile << "Log file closed.\n\n";
        logfile.close();
    }
}
