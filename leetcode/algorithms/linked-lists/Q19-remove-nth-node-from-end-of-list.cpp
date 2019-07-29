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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* parent = dummy;
        ListNode* end = dummy;
        while(n--){
            end = end->next;
        }

        while(end->next){
            parent = parent->next;
            end = end->next;
        }

        end = parent->next;
        parent->next = parent->next->next;
        delete end;
        return dummy->next;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

