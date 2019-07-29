/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
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
    // recursive
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* lastNode = head->next;
        ListNode* newHead = reverseList(head->next);
        lastNode->next = head;
        head->next = nullptr;
        return newHead;
    }
    // iterative
    ListNode* addTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;
        int d1, d2, val, carry = 0;

        while(carry || l1 || l2){
            d1 = l1 ? l1->val : 0;
            d2 = l2 ? l2->val : 0;
            val = d1 + d2 + carry;

            carry = val/10;
            val = val%10;

            l3->next = new ListNode(val);
            l3 = l3->next;

            l2 = l2 ? l2->next : nullptr;
            l1 = l1 ? l1->next : nullptr;
        }
        return dummy->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->next==nullptr && l1->val == 0){
            return l2;
        }
        if(l2->next==nullptr && l2->val == 0){
            return l1;
        }
        return reverseList(addTwoLists(reverseList(l1), reverseList(l2)));
    }
};

