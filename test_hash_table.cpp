using namespace std;
#include <iostream>
#include "usecase.cpp"


void test_get_key(){
    Element<int>  empty;
    if (empty.get_key()!=-1){
        cout<<"get_key failed on an empty element"<<endl;
    }
    Element<int> elt(13, 9);
    if (elt.get_key()!=9){
        cout<<"get_key failed on an integer element"<<endl;
    }
    Element<char> elt2('a', 4);
    if (elt2.get_key()!=4){
        cout<<"get_key failed on a char element"<<endl;
    }
}

void test_get_data(){
    Element<int>  empty;
    if (empty.get_data()!=0){
        cout<<"get_data failed on an empty element, got "<<empty.get_data()<<endl;
    }
    Element<int> elt(13, 9);
    if (elt.get_data()!=13){
        cout<<"get_data failed on an integer element"<<endl;
    }
    Element<char> elt2('a', 4);
    if (elt2.get_data()!='a'){
        cout<<"get_data failed on a char element"<<endl;
    }
}

void test_insert(){
    HashTable<int> empty(0);
    empty.insert(7, 11);
    if (empty.to_string()!=""){
        cout<<"inserting to empty HT caused error, got: "<<empty.to_string()<<endl;
    }
    HashTable<char> cHT(3);
    cHT.insert('a', 3);
    if (cHT.to_string()!="0: (a,3) \n1: \n2: \n"){
        cout<<"inserting to char HT caused error, got:  \n"<<cHT.to_string()<<endl;
    }
    HashTable<int> iHT(3);
    iHT.insert(12, 4);
    if (iHT.to_string()!="0: \n1: (12,4) \n2: \n"){
        cout<<"inserting to int HT caused error, got:  \n"<<iHT.to_string()<<endl;
    }
    iHT.insert(2, 1);
    if (iHT.to_string()!="0: \n1: (2,1) (12,4) \n2: \n"){
        cout<<"inserting to int HT caused error, got:  \n"<<iHT.to_string()<<endl;
    }
}

void test_remove(){
    HashTable<int> empty(0);
    empty.remove(0);
    if (empty.to_string()!=""){
        cout<<"removing from empty HT caused error, got: "<<empty.to_string()<<endl;
    }
    HashTable<char> cHT(3);
    cHT.insert('a', 3);
    cHT.insert('b', 9);
    cHT.remove(6);
    if (cHT.to_string()!="0: (b,9) (a,3) \n1: \n2: \n"){
        cout<<"removing from non member char HT caused error, got:  \n"<<cHT.to_string()<<endl;
    }
    cHT.remove(3);
    if (cHT.to_string()!="0: (b,9) \n1: \n2: \n"){
        cout<<"removing from member char HT caused error, got:  \n"<<cHT.to_string()<<endl;
    }
}

void test_member(){
    HashTable<int> empty(0);
    if (empty.member(12, 3)){
        cout<<"error claiming element was member of empty HT"<<endl;
    }
    HashTable<char> cHT(3);
    cHT.insert('a', 3);
    cHT.insert('b', 9);
    if (!cHT.member('a', 3)){
        cout<<"did not identify (a,3) as member in "<<cHT.to_string()<<endl;
    }
    if (cHT.member('b', 8)){
        cout<<"incorrectly identified (b,8) as member in "<<cHT.to_string()<<endl;
    }
}



int main(){
    test_get_key(); cout<<"completed test_get_key"<<endl;
    test_get_data(); cout<<"completed test_get_data"<<endl;
    test_insert(); cout<<"completed test_insert"<<endl;
    test_remove(); cout<<"completed test_remove"<<endl;
    test_member(); cout<<"completed test_member"<<endl;

    cout<<"completed testing"<<endl;
    return 0;
}
