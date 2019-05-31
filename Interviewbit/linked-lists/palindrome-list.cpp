/*
 * Author : Jatin Rohilla
 * Date   : 28-05-2019
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

ListNode* reverse(ListNode* head){
    if(!head || !head->next){
        return head;
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* nextNode;

    while(curr){
        nextNode = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int Solution::lPalin(ListNode* A) {
    ListNode* head = A;

    // edge cases
    if(!head || !head->next){
        return 1;
    }

    // find mid
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prevSlow = nullptr;
    while(fast && fast->next){
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // cut into 2 halves
    ListNode* l1 = head;
    ListNode* l2;

    if(fast==nullptr){
        // even
        l2 = prevSlow->next;
        prevSlow->next = nullptr;
    }
    else{
        l2 = slow->next;
        prevSlow->next = nullptr;
    }

    // reverse l2
    l2 = reverse(l2);

    // compare halves
    while(l1 && l2 && l1->val == l2->val){
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1 || l2){
        return 0;
    }
    return 1;
}


int main(){

	cout<<"Hello World";

    return 0;
}

