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
        Node* tmp = head; 
        if (isEmpty()){
            return; 
        }
        head = head->next; 
    }; 

    void removeBack(){
        if (isEmpty()){
            return; 
        }
        if (!head->next){
            head = nullptr; 
            return; 
        }
        Node* current = head; 
        while (current->next->next){
            current = current->next; 
        }
        current->next = nullptr; 
        return; 
    }; 

    void removeAt(int index){
        if (index == 0) {
            removeFront(); 
            return; 
        }
        if (index == -1) {
            removeBack(); 
            return; 
        }

        Node* current = head; 
        while (--index){
            current = current->next; 
        }
        Node* current_next = current->next; 
        current->next = current->next->next; 
        delete current_next; 
        return; 
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
    SLL.insertAt(10,1);
    SLL.insertAt(20,2); 
    cout << "After insert: "; 
    SLL.show(); 
    SLL.removeFront(); 
    // SLL.removeBack(); 
    SLL.removeAt(1); 
    SLL.show(); 
    return 0; 
}