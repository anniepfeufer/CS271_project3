
#include<iostream>
using namespace std;

template <typename T>
class Element
{
    private:
    T data;
    int key;
    Element<T> *next;
    Element<T> *prev;

    public:
    Element(){
        next = nullptr; 
        prev=nullptr;}
    
    Element(T val){
        data= val;
        next = nullptr; 
        prev=nullptr;}
    int get_key(){
        return key;
    }
    T get_data(){
        return data;
    }
};
