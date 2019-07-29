/*
 * Author : Jatin Rohilla
 * Date   : 01-06-2019
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
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head){
            return nullptr;
        }

        unordered_map<Node*, Node*> m;

        Node* dummy = new Node(-1);
        Node* clone = dummy;
        Node* trav = head;

        // step 1 : simply copy, also create a map
        while(trav){
            clone->next = new Node(trav->val, nullptr, nullptr);
            m[trav] = clone->next;
            clone = clone->next;
            trav = trav->next;
        }


        // step 2 : set random pointers
        trav = head;
        while(trav){
            m[trav]->random = m[trav->random];
            trav = trav->next;
        }

        return dummy->next;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

