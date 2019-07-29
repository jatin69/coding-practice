/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode* n1 = head;
        ListNode* n2 = n1->next;
        ListNode* nextNode = swapPairs(head->next->next);

        n2->next = n1;
        n1->next = nextNode;
        return n2;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

