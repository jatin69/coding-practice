/*
 * Author : Jatin Rohilla
 * Date   : 13-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
 */


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* A, int B) {

    ListNode* head = A;
    ListNode* endTracker = A;

    int n = B;
    while(endTracker && n--){
        endTracker = endTracker->next;
    }

    if(n>0 || endTracker==nullptr){
        // remove head and return
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    // B is within range
    ListNode* targetNodeParent = head;
    while(endTracker->next){
        endTracker = endTracker->next;
        targetNodeParent = targetNodeParent->next;
    }

    ListNode* targetNode = targetNodeParent->next;
    targetNodeParent->next = targetNode->next;
    delete targetNode;

    return head;
}

int main(){

	//  todo : add testcases

    return 0;
}

