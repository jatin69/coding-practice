/*
 * Author : Jatin Rohilla
 * Date   : 15-05-2019
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
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {

    ListNode* C = new ListNode(-1);

    ListNode* h1 = A;
    ListNode* h2 = B;
    ListNode* res = C;

    while(h1 && h2){

        if(h1->val <= h2->val){
            res->next = new ListNode(h1->val);
            res = res->next;
            h1 = h1->next;
        }
        else{
            res->next = new ListNode(h2->val);
            res = res->next;
            h2 = h2->next;
        }
    }

    while(h1){
        res->next = new ListNode(h1->val);
        res = res->next;
        h1 = h1->next;
    }

    while(h2){
        res->next = new ListNode(h2->val);
        res = res->next;
        h2 = h2->next;
    }

    return C->next;
}

int main(){

	cout<<"Hello World";

    return 0;
}

