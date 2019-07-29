/*
 * Author : Jatin Rohilla
 * Date   : 31-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
public:
    SinglyListNode* head;

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(!head){
            return -1;
        }
        if(index < 0){
            return -1;
        }
        if(index == 0){
            return head->val;
        }

        SinglyListNode* trav = head;
        while(trav && index--){
            trav = trav->next;
        }
        if(trav==nullptr || index > 0){
            return -1;
        }
        return trav->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode* curr = new SinglyListNode(val);
        curr->next = head;
        head = curr;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(!head){
            addAtHead(val);
            return;
        }
        SinglyListNode* trav = head;
        while(trav->next){
            trav = trav->next;
        }
        trav->next = new SinglyListNode(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0 ){
            addAtHead(val);
            return;
        }
        if(index < 0){
            addAtHead(val);
            return;
        }

        int parentIndex = index - 1;
        SinglyListNode* trav = head;
        while(trav && parentIndex--){
            trav = trav->next;
        }
        if(trav==nullptr || parentIndex > 0){
            return;
        }
        if(trav->next == nullptr){
            addAtTail(val);
        }
        else{
            SinglyListNode* newNode = new SinglyListNode(val);
            newNode->next  = trav->next;
            trav->next = newNode;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(!head){
            return;
        }
        if(index < 0){
            return;
        }
        SinglyListNode* target;
        if(index == 0){
            target = head;
            head = head->next;
            delete target;
            return;
        }
        int parentIndex = index - 1;
        SinglyListNode* trav = head;
        while(trav && parentIndex--){
            trav = trav->next;
        }
        if(parentIndex > 0){
            return;
        }
        if(trav->next != nullptr){
            target = trav->next;
            trav->next = trav->next->next;
            delete target;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){

	cout<<"Hello World";

    return 0;
}

