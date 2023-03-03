
#include <iostream>
#include <istream>
#include "usecase.cpp"
using namespace std;

int main(){
    std::string file="logins.csv";
    HashTable<string> *HT=create_table<string>(file, 5);

    
    cout<<"Enter your username: ";
    string usr;
    getline(cin, usr);
    cout<<endl<<"Enter your password: ";
    string pwd;
    getline(cin, pwd);
    cout<<endl;
    bool granted= login<string>(HT, usr, pwd);
    if (granted){
        cout<<"Access Granted"<<endl;
    }
    else{
        cout<<"Access Denied"<<endl;
    }
    
    return 0;
}