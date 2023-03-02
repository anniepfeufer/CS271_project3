#include "hash_table.h"

template <typename T>
void HashTable<T>::insert(T data, int key){
    Element<T> *item= new Element<T>(data, key);
    int slot=hashFunc(key);
    if (HT[slot].head!= nullptr){
        item->next=HT[slot].head;
        item->next->prev=item;
    }
    else{
        HT[slot].tail=item;
    }
    HT[slot].head=item;
}

template <typename T>
 void HashTable<T>::remove(int key) {
        int index = hashFunc(key);
        Element<T>* currentElement = HT[index].head;
        while (currentElement != nullptr) {
            if (currentElement->key == key) {
                if (currentElement->prev == nullptr) {
                    HT[index].head = currentElement->next;
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
    Element<T> *curr=HT[slot].head;
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
        HTstring= HTstring + std::to_string(i)+ ": ";
        Element<T>* curr=HT[i].head;
        while (curr!= nullptr){
            T d=curr->data;
            int k=curr->key;
            HTstring=HTstring + "(" +std::to_string(d)+","+std::to_string(k)+") ";
            curr=curr->next;
        }
        HTstring=HTstring+ "\n";
    }
    return HTstring;
}
