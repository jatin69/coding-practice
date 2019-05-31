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
    ListNode* oddEvenList(ListNode* head) {

        if(head==nullptr || !head->next){
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* evenList = dummy;

        ListNode* trav = head;
        int index = 0;
        while(trav->next){
            index++;
            if(index & 1){
                evenList->next = trav->next;
                evenList = evenList->next;
                trav->next = trav->next->next;
            }
            else{
                trav = trav->next;
            }
        }

        evenList->next = nullptr;
        trav->next = dummy->next;
        return head;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

