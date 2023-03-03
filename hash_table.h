//Hash Table declaration

#include<iostream>
using namespace std;

template <typename T>
class Element
{
    public:
    T data; 
    int key;
    Element<T> *next; //for chaining in hash table
    Element<T> *prev;  //for chaining in hash table

    Element(){
        data=0;
        key=-1;
        next = nullptr; 
        prev=nullptr;}
    
    Element(T val, int k){
        data= val;
        key=k;
        next = nullptr; 
        prev = nullptr;}
    int get_key(){
        return key;
    }
    T get_data(){
        return data;
    }

    ~Element(){
        delete next;
        delete prev;
    }
    
};

//==================================================
// We wanted to create a LinkedList class so that for our
// Hash Table array, we could easily store the head and tail
// pointers in slots of the array made in HashTable class
//==================================================
template<typename T>
class LinkedList
{
    public:
    int len;
    Element<T> *head; //head of chaining for hash table
    Element<T> *tail; //tail of chaining for hash table

    LinkedList(){
        len=0;
        head= nullptr;
        tail= nullptr;
    }
    LinkedList(Element<T> item){
        len=1;
        head= &item;
        tail= &item;
    }
    LinkedList operator=(Element<T> item){
        len=1;
        head=&item;
        tail=&item;
    }
    


};

template<typename T>
class HashTable
{
    private:
    int m; //number of slots in the hash table
    LinkedList<T> *HT; //array of linked lists

    public:
    HashTable(){
        m=0;
        HT=new LinkedList<T>[m];
    }
    HashTable(int slots){
        m= slots;
        HT=new LinkedList<T>[m];
    }
    void insert(T data, int key);
    void remove(int key);
    bool member(T data, int key);
    int hashFunc(int key);
    string to_string(void);

    ~HashTable(){
        delete [] HT;
    }
};