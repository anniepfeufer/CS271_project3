
#include <iostream>
#include "hash_table.cpp"
using namespace std;

template <typename T>
//HashTable<T>* create_table(string fname, int m){
int create_table(){
    return 0;
}

template <typename T>
bool login(HashTable<T>* ht, T username, string password){
    int pwd= stoi(password);
    bool access= ht->member(username, pwd);
    return access;
}

