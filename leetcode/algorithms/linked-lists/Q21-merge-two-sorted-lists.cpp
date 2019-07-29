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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                l3->next = l1;
                l1 = l1->next;
                l3 = l3->next;
            }
            else{
                l3->next = l2;
                l2 = l2->next;
                l3 = l3->next;
            }
        }
        if(l1){
            l3->next = l1;
        }
        else{
            l3->next = l2;
        }
        return dummy->next;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

