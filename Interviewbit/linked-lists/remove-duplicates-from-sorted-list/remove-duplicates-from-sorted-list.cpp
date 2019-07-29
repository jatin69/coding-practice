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
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==nullptr || A->next==nullptr){
        return A;
    }

    ListNode* trav = A;
    ListNode* target;
    while(trav && trav->next){
        if(trav->val == trav->next->val){
            target = trav->next;
            trav->next = trav->next->next;
            delete target;
        }
        else{
            trav->next;
        }
    }

    return A;
}

// 1,1,1,2,2,2


int main(){

	cout<<"Hello World";

    return 0;
}

