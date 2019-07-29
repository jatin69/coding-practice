/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* trav = head;
        ListNode* target;
        while(trav && trav->next){
            if(trav->val == trav->next->val){
                target = trav->next;
                trav->next = trav->next->next;
                delete target;
            }
            else{
                trav = trav->next;
            }
        }
        return head;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

