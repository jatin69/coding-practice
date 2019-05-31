/*
 * Author : Jatin Rohilla
 * Date   : 31-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/k-reverse-linked-list/
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

ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* head = A;

    // edge cases
    if(!head || !head->next){
        return head;
    }
    if(B==1){
        return head;
    }

    // dummy node at starting
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* currPrev, *currHead;
    ListNode* prev = dummy;
    ListNode* curr = head;
    ListNode* nextNode;
    while(curr){
        currPrev = prev;
        currHead = curr;
        for(int i=0 ; i<B; ++i){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        currPrev->next = prev;
        currHead->next = curr;
        prev = currHead;
    }

    return dummy->next;
}


int main(){

	cout<<"Hello World";

    return 0;
}

