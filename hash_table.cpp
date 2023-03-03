//Class implementation for HashTable

#include "hash_table.h"

//============================================
// insert
// This function inserts a value into the hash table
// at the specified slot based on the hash of the key.
// PARAMETERS:
// - data: data of to be inserted element with type T
// - key: int that determines slot of element in the HT
// RETURN:
// - none
// Precondition: No required preconditions
// Postcondition: Ends with a Hash Table containing
//                the inserted item at slot corresponding to key
//============================================

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


//============================================
// remove
// This function removes a value from the hash table
// at the specified slot based on the hash of the key.
// PARAMETERS:
// - key: int that determines slot of element in the HT
//        that is to be removed
// RETURN:
// - none
// Precondition: No required preconditions
// Postcondition: Ends with a Hash Table containing
//                all previous elements, except that with
//                the inputted key
//============================================

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
                //delete currentElement;
                return;
            }
            currentElement = currentElement->next;
        }
}

//============================================
// hashFunc
// This function hashes an inputted key
// PARAMETERS:
// - key: int that gets hashed
// RETURN:
// - key%m: hashed key
// Precondition: No required preconditions
// Postcondition: does not change the key, returns a hashed value of the key.
//============================================

template <typename T>
int HashTable<T>::hashFunc(int key){
    return key%m;
}


//============================================
// member
// This function searches for an element with data/key
// pair in the HT and retruns whether the element is in the HT
// PARAMETERS:
// - data: data of element with type T
// - key: int that determines slot of element in the HT
// RETURN:
// - found: bool of whether element is in HT
// Precondition: No required preconditions
// Postcondition: unchanged HT, and found is whether the element was found
//============================================


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

//============================================
// to_string
// This function converts the HT to a string, so it can be printed
// or compared to expected HT
// PARAMETERS:
// - none
// RETURN:
// - HTstring: string representation of the Hash Table
// Precondition: No required preconditions
// Postcondition: unchanged HT, and a string representation of the HT
//============================================

template <typename T>
string HashTable<T>::to_string(void){
    string HTstring;
    for (int i=0; i<m; i++){
        HTstring= HTstring + std::to_string(i)+ ": ";
        Element<T>* curr=HT[i].head;
        while (curr!= nullptr){
            T d=curr->data;
            int k=curr->key;
            if (std::is_same<T, char>::value){
                std::string s(1, d);
                HTstring=HTstring + "(" +s+","+std::to_string(k)+") ";
            }
            else{
                HTstring=HTstring + "(" +std::to_string(d)+","+std::to_string(k)+") ";
            }
            curr=curr->next;
        }
        HTstring=HTstring+ "\n";
    }
    return HTstring;
}
