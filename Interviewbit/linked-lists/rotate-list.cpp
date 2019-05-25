/*
 * Author : Jatin Rohilla
 * Date   : 22-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/rotate-list/
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
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==nullptr || A->next==nullptr){
        return A;
    }

    int len = 0;
    for(ListNode* head = A; head!=nullptr; head=head->next){ len++; }
    B = B%len;

    if(B==0){
        return A;
    }

    ListNode *trav, *newHead;

    trav = A;
    int n = len-B-1;
    while(n--){ trav = trav->next; }
    newHead = trav->next;
    trav->next = nullptr;

    trav = newHead;
    while(trav->next){
        trav = trav->next;
    }
    trav->next = A;
    return newHead;
}


int main(){

	cout<<"Hello World";

    return 0;
}

