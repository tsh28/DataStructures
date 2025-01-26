#include <iostream>

using namespace std; 

class Node { 
public: 
    int val; 
    Node* next ; 
    Node(): val(0), next(nullptr){}; 
    Node(int val): val(val), next(nullptr) {}; 
}; 

class SinglyLinkedList{
public: 
    SinglyLinkedList(): head(NULL){}; 

    bool isEmpty(){
        return head == nullptr; 
    }; 

    void insertFront(int val){
        Node* newNode = new Node(val); 
        newNode->next = head; 
        head = newNode; 
        return; 
    }; 

    void insertBack(int val){
        Node* newNode = new Node(val); 
        Node* tmp = head; 
        if (isEmpty()){
            head = tmp; 
            return; 
        }
        while (tmp->next){
            tmp = tmp->next; 
        }
        tmp->next = newNode; 
        return;       
        
    }; 

    void insertAt(int val, int index){
        if (index == 0) {
            insertFront(val); 
            return; 
        }
        if (index == -1) {
            insertBack(val); 
            return; 
        }
        Node* tmp = head; 
        Node* newNode = new Node(val);
        while (--index > 0) {
            tmp = head->next; 
        }
        Node* tpm_next = tmp->next; 
        tmp->next = newNode; 
        newNode->next = tpm_next; 
        return; 
    }; 

    void removeFront(){

    }; 

    void removeBack(){

    }; 

    void removeAt(int index){

    }; 
    void show(){
        if (isEmpty()){
            cout << "SLL is empty" << "\n"; 
        }
        Node* tmp_head = head; 
        while (tmp_head){
            cout << tmp_head->val << "->"; 
            tmp_head = tmp_head->next; 
        }
        cout << "null \n"; 
    }; 

private: 
    Node* head; 

}; 

int main() {
    SinglyLinkedList SLL; 
    SLL.insertFront(1);
    SLL.insertBack(3);  
    // SLL.insertBack(2); 
    SLL.insertAt(5,1); 
    SLL.show(); 
    return 0; 
}