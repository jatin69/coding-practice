/*
 * Author : Jatin Rohilla
 * Date   : 30-05-2019
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
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {

    ListNode* dummyHead = new ListNode(-1);
    dummyHead->next = A;

    ListNode* prev = dummyHead;
    ListNode* head = A;

    int m = B-1;
    while(m--){
        prev = head;
        head = head->next;
    }

    ListNode* curr = head;

    ListNode* initialPrev = prev;
    ListNode* initialCurr = curr;

    ListNode* nextNode;

    int times = C-B+1;
    while(times--){
        nextnode = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }

    initialPrev->next = prev;
    initialCurr->next = curr;

    return dummyHead->next;
}


int main(){

	cout<<"Hello World";

    return 0;
}

