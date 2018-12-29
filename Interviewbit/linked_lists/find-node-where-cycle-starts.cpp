/*
 * Author : Jatin Rohilla
 * Date   : 03-07-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
link - https://www.interviewbit.com/problems/list-cycle/

Accepted.
*/

// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* Solution::detectCycle(ListNode* head) {

    // base case
    if(head==nullptr || head->next == nullptr){
        return nullptr;
    }

    // using floyd's to confirm cycle
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==nullptr || fast->next == nullptr){
            return nullptr;
        }
    }

    // cycle length
    int len = 1;
    fast = fast->next;
    while(slow!=fast){
        fast = fast->next;
        len++;
    }

    slow = head;
    fast = head;
    while(len--){
        fast = fast->next;
    }

    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;

}

