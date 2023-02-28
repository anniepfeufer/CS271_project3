
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
        key=k;
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
        tail= &item;
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
};

template <typename T>
void HashTable<T>::insert(T data, int key){
    Element<T> item=Element<T>(data, key);
    int slot=hashFunc(key);
    if (HT[slot].head!= nullptr){
        item->next=HT[slot]->head;
        item->next->prev=&item;
    }
    else{
        HT[slot].tail=&item;
    }
    HT[slot].head=&item;
}
template <typename T>
 void HashTable<T>::remove(int key) {
        int index = hashFunc(key);
        Element<T>* currentElement = HT[index];
        while (currentElement != nullptr) {
            if (currentElement->key == key) {
                if (currentElement->prev == nullptr) {
                    HT[index] = currentElement->next;
                } else {
                    currentElement->prev->next = currentElement->next;
                }
                if (currentElement->next != nullptr) {
                    currentElement->next->prev = currentElement->prev;
                }
                delete currentElement;
                return;
            }
            currentElement = currentElement->next;
        }
 }

template <typename T>
int HashTable<T>::hashFunc(int key){
    return key%m;
}

template <typename T>
bool HashTable<T>::member(T data, int key){
    int slot= hashFunc(key);
    bool found=false;
    Element<T> *curr=HT[slot]->head;
    while (found==false && curr!=nullptr){
        if (curr->key==key && curr->data==data){
            found=true;
        }
        curr=curr->next;
    }
    return found; 
}

template <typename T>
string HashTable<T>::to_string(void){
    string HTstring;
    for (int i=0; i<m; i++){
        HTstring= HTstring + std::to_string(i)+ ":";
        Element<T>* curr=HT[i]->head;
        while (curr!= nullptr){
            T d=curr->data;
            int k=curr->key;
            HTstring=HTstring + "(" +std::to_string(d)+", "+std::to_string(k)+")";
            curr=curr->next;
        }
        if (i!=m-1){HTstring=HTstring+ "\n";}
    }
    return HTstring;
}
