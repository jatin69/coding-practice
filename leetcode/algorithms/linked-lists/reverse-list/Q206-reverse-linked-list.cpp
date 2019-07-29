/*
 * Author : Jatin Rohilla
 * Date   : 31-05-2019
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode;

        while(curr){
            nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

