/*
 * Author : Jatin Rohilla
 * Date   : 21-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/insertion-sort-list/
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
ListNode* Solution::insertionSortList(ListNode* A) {

    ListNode* ul = A->next;

    ListNode* sortedList = new ListNode(-1);
    sortedList->next = A;
    sortedList->next->next = nullptr;
    ListNode* sl;
    ListNode* target;

    while(ul){
        sl = sortedList;
        while(sl->next && (sl->next->val <= ul->val)){   sl = sl->next;  }

        target = ul;
        ul = ul->next;

        target->next = sl->next;
        sl->next = target;
    }

    return sortedList->next;
}


int main(){

	cout<<"Hello World";

    return 0;
}

