/*
 * Author : Jatin Rohilla
 * Date   : 27-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
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
ListNode* Solution::swapPairs(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* newHead = head->next;

    ListNode* parent = new ListNode(-1);
    parent->next = head;
    ListNode *n1, *n2;

    while(parent!=nullptr){
        n1 = parent->next;
        if(n1==nullptr){
            break;
        }
        n2 = n1->next;
        if(n2==nullptr){
            break;
        }

        parent->next = n2;
        n1->next = n2->next;
        n2->next = n1;

        parent = n1;
    }

    return newHead;
}


int main(){

	// 1, 2, 3, 4
	// 1,2,3
	// 1, 2
	// 1
	// 1,2,3,4,5

    return 0;
}

