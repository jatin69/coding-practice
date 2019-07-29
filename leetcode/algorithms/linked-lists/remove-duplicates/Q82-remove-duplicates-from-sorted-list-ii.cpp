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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *target, *curr;

        ListNode *trav = dummy;
        while(trav && trav->next && trav->next->next){
            // if a culprit is found
            if(trav->next->val == trav->next->next->val){
                // ask culprit to clean itself up
                curr = trav->next;
                while(curr && curr->next && (curr->val == curr->next->val)){
                    target = curr->next;
                    curr->next = curr->next->next;
                    delete target;
                }
                // once cleaned, clean the culprit
                target = trav->next;
                trav->next = trav->next->next;
                delete target;
            }
            // if not a culprit, simply move on
            else{
                trav = trav->next;
            }
        }
        return dummy->next;
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

