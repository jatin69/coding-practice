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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        bool hasCycle = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                hasCycle = true;
                break;
            }
        }

        if(!hasCycle){
            return nullptr;
        }

        ListNode* trav = head;
        while(trav!=slow){
            slow = slow->next;
            trav = trav->next;
        }
        return trav;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

