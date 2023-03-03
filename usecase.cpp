
#include <iostream>
#include "hash_table.cpp"
#include <fstream>
using namespace std;

template <typename T>
HashTable<T>* create_table(string fname, int m){
    HashTable<T> *ht = new HashTable<T>(m);
    ifstream f (fname);
    T u;
    int p;
    while (f>>u>>p){
        ht->insert(u,p);
    }
    return ht;
}

//============================================
// login
// This function searches a hash table for a given
// username and password
// PARAMETERS:
// - ht: hash table to be searched
// - username: the data of element that is being searched for of type T
// - password: string of the key value of the element being searched for
// RETURN:
// - access: bool of whether the username/password combo was found
// Precondition: No required preconditions
// Postcondition: unchanged hash table, and bool of whether access should 
//                be granted. 
//============================================
template <typename T>
bool login(HashTable<T>* ht, T username, string password){
    long pwd= stol(password);
    bool access= ht->member(username, pwd);
    return access;
}

