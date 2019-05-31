/*
 * Author : Jatin Rohilla
 * Date   : 22-05-2019
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
ListNode* Solution::partition(ListNode* A, int B) {

    ListNode* lessthanList = new ListNode(-1);
    ListNode* lt = lessthanList;

    ListNode* greaterThanList = new ListNode(-1);
    ListNode* gt = greaterThanList;

    ListNode* head = new ListNode(-1);
    head->next = A;

    ListNode* trav = head->next;
    while(trav){
       if(trav->val < B){
           lt->next = trav;
           lt = lt->next;
       }
       else{
           gt->next = trav;
           gt = gt->next;
       }
       trav = trav->next;
    }

    gt->next = nullptr;
    lt->next = greaterThanList->next;

    return lessthanList->next;
}


int main(){

	cout<<"Hello World";

    return 0;
}

