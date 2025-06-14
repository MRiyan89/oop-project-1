#include<iostream>
#include "librarian.h"
using namespace std;
void Librarian :: showAllLibrarain(){
    cout<<"\n     LIBRARIAN NO. "<<librarian_no<<"\n\nNAME : "<<librarian_name<<"\nID : "<<librarian_id<<"\nPassword : "<<librarain_password;
    str msg("Entire detail seen of Librarian named: ");
    str msg2(msg + librarian_name);
    Logger::record(msg2);
    cin.get();
}

void Librarian::addLibrarain(){
    char temp[100];
    cout<<"\n               ADD Librarian NO. "<<librarian_no<< " DETAIL'S";
    cout<<"\n\nEnter name of the librarian: ";
    cin.getline(temp, 100);
    librarian_name = temp;
    cout<<"\nEnter the ID of the librarian: ";
    cin.getline(temp, 100);
    librarian_id = temp;
    cout<<"\nEnter the librarian account password: ";
    cin.getline(temp, 100);
    librarain_password = temp;
    cout<<"\nLibrarian DETAILS ADDED SUCCESSFULLY";
    str msg("A new Librarian added named: ");
    str msg2(msg + librarian_name);
    Logger::record(msg2);
    cin.get();
}

void Librarian :: deleteLibrarain(Librarian *&b1){
    str del_lib;
    char temp[100];
    int index = 0;
    cout<<"\n               DELETE Librarian Account";
    cout<<"\n\nEnter the librarian id or name to delete that librarian: ";
    cin.getline(temp, 100);
    del_lib = temp;
    for(int i=0; i<l3; i++){
        if(b1[i].librarian_name==del_lib || b1[i].librarain_password==del_lib){
            index=i+1;
        }
    }
    if(index == 0){
        cout<<"Librarian NOT FOUND!";
        cin.get();
    }
    else{
        for(int i=index-1; i<l3-1; i++){
            b1[i]=b1[i+1];
            b1[i].librarian_no=i+1;
        }
        l3--;
        cout<<"\nLibrarian DELETED SUCCESSFULLY: ";
    }
    str msg("deleted record of Librarian named: ");
    str msg2(msg + librarian_name);
    Logger::record(msg2);
}

void Librarian :: searchLibrarain(Librarian *& b1){
    char temp[100];
    str ser_lib;
    bool flag = 0;
    cout<<"\n                     SEARCH A Librarian";
    cout<<"\n\nEnter Librarian ID or name to search : ";
    cin.getline(temp, 100);
    ser_lib = temp;
    for(int i=0; i<l3; i++){
        if(ser_lib == b1[i].librarian_id || ser_lib == b1[i].librarian_name){
            b1[i].showAllLibrarain();
            str msg("Searched for a Librarian named: ");
            str msg2(msg + librarian_name);
            Logger::record(msg2);

            flag = 1;
        }
    }
    if(flag == 0){
        cout<<"\nLibrarian NOT FOUND!";
        cin.get();
    }
    
}

void Librarian ::modifyLibrarain(Librarian *& b1){
    char temp[100];
    str mod_lib;
    bool flag = 0;
    cout<<"\n                  MODIFY A Librarian";
    cout<<"\n\nEnter Librarain ID or name to modify : ";
    cin.getline(temp, 100);
    mod_lib = temp;
    for(int i=0; i<l3; i++){
        if(mod_lib == b1[i].librarian_id || mod_lib == b1[i].librarian_name){
            b1[i].addLibrarain();
            flag = 1;
            cout<<"\nLibrarian "<<b1[i].librarian_no<<" SUCCESSFULLY MODIFIED: ";
            str msg("Modified a Librarian named: ");
            str msg2(msg + librarian_name);
            Logger::record(msg2);
            cin.get();
        }
    }
    if(flag == 0){
        cout<<"\nLibrarian NOT FOUND!";
        cin.get();
    }

}

void Librarian :: serialize(fstream& f) {
    char* temp=nullptr;
    f.write((char*)&librarian_no, sizeof(int));
    int len = librarian_name.amount();
    temp=new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = librarian_name[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    len = librarian_id.amount();
    delete[] temp;
    temp=new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = librarian_id[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    len = librarain_password.amount();
    delete[] temp;
    temp=new char[len];
    for(int i = 0; i < len; i++) {
        temp[i] = librarain_password[i];
    }
    temp[len] = '\0';
    f.write((char*)&len, sizeof(int));
    f.write(temp, len);
    delete[] temp;
}

void Librarian :: deserialize(fstream& f) {
    f.read((char*)&librarian_no, sizeof(int));
    int len;
    f.read((char*)&len, sizeof(int));
    char* temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    librarian_name = temp;
    delete[] temp;
    f.read((char*)&len, sizeof(int));
    temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    librarian_id = temp;
    delete[] temp;
    f.read((char*)&len, sizeof(int));
    temp = new char[len + 1];
    f.read(temp, len);
    temp[len] = '\0';
    librarain_password = temp;
    delete[] temp;
}