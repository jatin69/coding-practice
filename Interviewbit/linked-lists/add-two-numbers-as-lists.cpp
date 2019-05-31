/*
 * Author : Jatin Rohilla
 * Date   : 21-05-2019
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
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

    ListNode* n1 = A;
    ListNode* n2 = B;

    // new number with dummy node at the starting
    ListNode* n3 = new ListNode(-1);
    ListNode* res = n3;

    int val;
    int base = 10;
    int carry = 0;

    while(n1 || n2){

        val = (n1 ? n1->val : 0) + (n2 ? n2->val : 0) + carry;
        if(val >= base){
            val = val % base;
            carry = 1;
        }
        else{
            carry = 0;
        }
        res->next = new ListNode(d3);
        res = res->next;

        n1 = (n1 ? n1->next : nullptr);
        n2 = (n2 ? n2->next : nullptr);
    }

    return n3->next;
}


int main(){

	cout<<"Hello World";

    return 0;
}

