
#include <iostream>
#include "usecase.cpp"
using namespace std;

int main(){
    std::string file="logins.csv";
    HashTable<string> *HT=create_table(file, 5);

    
    cout<<"Enter your username: ";
    string usr;
    cin>>usr;
    cout<<endl<<"Enter your password: ";
    string pwd;
    cin>>pwd;
    cout<<endl;
    bool granted= login(HT, usr, pwd);
    if (granted){
        cout<<"Access Granted"<<endl;
    }
    else{
        cout<<"Access Denied"<<endl;
    }
    


    return 0;
}