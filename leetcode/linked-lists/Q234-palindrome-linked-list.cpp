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
    ListNode* reverse(ListNode* head){
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

    bool isPalindrome(ListNode* head) {

        // edge cases
        if(!head || !head->next){
            return true;
        }

        // find mid
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevSlow = nullptr;
        while(fast && fast->next){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // cut after mid
        ListNode* l1 = head;
        ListNode* l2;

        bool isOddLen = false;
        if(fast==nullptr){
            // even length
            l2 = prevSlow->next;
            prevSlow->next = nullptr;
        }
        else{
            // odd length
            isOddLen = true;
            l2 = slow->next;
            prevSlow->next = nullptr;
        }

        // reverse later half
        l2 = reverse(l2);

        // compare if equal
        bool isPalindrome = true;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1 && t2 && t1->val == t2->val){
            t1 = t1->next;
            t2 = t2->next;
        }
        if(t1 || t2){
            isPalindrome = false;
        }

        // convert back later half
        l2 = reverse(l2);

        // join again
        if(isOddLen){
            prevSlow->next = slow;
            slow->next = l2;
        }
        else{
            prevSlow->next = l2;
        }

        return isPalindrome;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

