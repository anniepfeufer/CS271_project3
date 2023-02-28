
#include<iostream>
using namespace std;

template <typename T>
class Element
{
    public:
    T data;
    int key;
    Element<T> *next;
    Element<T> *prev;

    Element(){
        next = nullptr; 
        prev=nullptr;}
    
    Element(T val, int k){
        data= val;
        key=k
        next = nullptr; 
        prev = nullptr;}
    int get_key(){
        return key;
    }
    T get_data(){
        return data;
    }
};

//I really dont know if we need linked lists as a class but I am not at all 
//sure how to implement an array of pointers to linked lists otherwise :(

template<typename T>
class LinkedList
{
    public:
    int len;
    Element<T> *head;
    Element<T> *tail;

    LinkedList(){
        len=0;
        head= nullptr;
        tail= nullptr;
    }
    LinkedList(Element<T> item){
        len=1;
        head= &item;
        tail= &item
    }
};

template<typename T>
class HashTable
{
    private:
    int m;
    LinkedList<T> *HT;

    public:
    HashTable(){
        m=0;
        HT==new LinkedList<T>[m]
    }
    HashTable(int slots){
        m= slots;
        HT==new LinkedList<T>[m]
    }
    void insert(T data, int key);
    void remove(int key);
    bool member(T data, int key);
    int hashFunc(int key);
    
};

template <typename T>
void HashTable<T>::insert(T data, int key){
    item=Element(data, key);
    slot=hashFunc(key);
    if HT[slot].head!= nullptr{
        item.next=HT[slot].head;
        item.next.prev=&item;
    }
    else{
        HT[slot].tail=&item;
    }
    HT[slot].head=&item;
}
