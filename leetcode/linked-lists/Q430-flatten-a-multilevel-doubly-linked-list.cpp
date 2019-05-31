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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr){
            return nullptr;
        }

        Node* walker = head;
        while(walker){
            if(walker->child){
                Node* nextWalker = walker->next;
                Node* last = walker->child;
                while(last->next){
                    last = last->next;
                }

                walker->next = walker->child;
                walker->child->prev = walker;
                walker->child = nullptr;
                last->next = nextWalker;

                if(nextWalker){
                    nextWalker->prev = last;
                }
            }
            walker = walker->next;
        }
        return head;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

