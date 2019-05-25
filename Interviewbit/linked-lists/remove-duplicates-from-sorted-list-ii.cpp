/*
 * Author : Jatin Rohilla
 * Date   : 15-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
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
ListNode* deleteDuplicates(ListNode* A) {

    if(A==nullptr || A->next == nullptr){
        return A;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    ListNode* parent = dummy;

    ListNode* trav = parent->next;
    ListNode* target;

    while(trav && trav->next){

        if(trav->val == trav->next->val){
            do{
                target = trav;
                trav = trav->next;
                delete target;
            }while(trav->next && trav->val == trav->next->val);

            target = trav;
            parent->next = trav->next;
            trav = parent->next;
            delete target;
        }
        else{
            parent = trav;
            trav = trav->next;
        }
    }

    return dummy->next;
}


int main(){

	cout<<"Hello World";

    return 0;
}

