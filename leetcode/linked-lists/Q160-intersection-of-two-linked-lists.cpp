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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* trav;

        int lenA = 0;
        trav = headA;
        while(trav){
            lenA++;
            trav = trav->next;
        }

        int lenB = 0;
        trav = headB;
        while(trav){
            lenB++;
            trav = trav->next;
        }

        // lenA should be always more
        if(lenA < lenB){
            trav = headA;
            headA = headB;
            headB = trav;
        }

        int diff = abs(lenA-lenB);
        while(diff--){
            headA = headA->next;
        }

        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

