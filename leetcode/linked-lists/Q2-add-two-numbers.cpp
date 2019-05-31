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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;

        int d1, d2, val, carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            d1 = (l1 ? l1->val : 0);
            d2 = (l2 ? l2->val : 0);
            val = (d1 + d2 + carry);
            carry = val/10;
            val = val%10;
            l3->next = new ListNode(val);
            l3 = l3->next;
            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);
        }

        return dummy->next;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

