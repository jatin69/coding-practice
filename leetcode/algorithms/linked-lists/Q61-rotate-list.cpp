/*
 * Author : Jatin Rohilla
 * Date   : 01-06-2019
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        if(k==0){
            return head;
        }
        ListNode* trav = head;
        int len = 0;
        while(trav){
            len++;
            trav = trav->next;
        }
        k = k % len;
        if(k==0){
            return head;
        }
        k = len - k;
        k--;

        trav = head;
        while(k--){
            trav = trav->next;
        }

        ListNode* newHead;
        newHead = trav->next;
        trav->next = nullptr;

        trav = newHead;
        while(trav->next){
            trav = trav->next;
        }
        trav->next = head;

        return newHead;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

