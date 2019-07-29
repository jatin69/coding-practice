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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* target;
        ListNode* trav = dummy;
        while(trav->next){
            if(trav->next->val == val){
                target = trav->next;
                trav->next = trav->next->next;
                delete target;
            }
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

