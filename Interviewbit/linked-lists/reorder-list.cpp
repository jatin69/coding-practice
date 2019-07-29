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
ListNode* reverseList(ListNode* head){
    if(!head || !head->next){ return head; }

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

ListNode* Solution::reorderList(ListNode* head) {
    if(!head || !head->next || !head->next->next){ return head; }

    // find middle (use the lower node for even length lists)
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    // disconnect after middle
    ListNode* list1 = head;
    ListNode* list2 = slow->next;
    slow->next = nullptr;

    // reverse list2
    list2 = reverseList(list2);

    // merge with list1
    ListNode* target;
    while(list2){
        target = list2;
        list2 = list2->next;
        target->next = list1->next;
        list1->next = target;
        list1 = list1->next->next;
    }
    return head;
}


