/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

question : Reverse a linked list from position m to n. Do it in one-pass
https://leetcode.com/problems/reverse-linked-list-ii/

Example -
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

Accepted.
 */


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x, ListNode* _next=NULL){
			val = x;
			next = _next;
	  }
  };

void print(ListNode* _head){
	ListNode* head = _head;
	while(head->next!=NULL){
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << head->val << " -> NULL";
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
	
	// base case
	if(head==NULL){
		return head;
	}
	
	// trivial case
	if(m==n){
		return head;
	}

	// setting two pointer n-m gap apart, aiding single traversal
	int gapCount = n-m;
	ListNode* p1 = head;
	ListNode* p2 = head;
	while(gapCount--){
		p2 = p2->next;
	}
	

	ListNode* beforeStart = NULL;       
	ListNode* afterEnd = NULL;

	int distanceToHead = m-1;       // separate handling when m=1
	if(distanceToHead){
		
		// move to prev
		int start = m-2;    // -1 to handle index & -1 to get prev
		while(start--){
			p1 = p1->next;
			p2 = p2->next;
		}
		beforeStart = p1;     

		// move forward to actual indexes
		p1 = p1->next;     
		p2 = p2->next;     
	}
	
	afterEnd = p2->next;
	
	
	// start reversal
	ListNode* prev = afterEnd;  // will point to last
	ListNode* curr = p1;        
	ListNode* nextNode = curr->next;
	
	
	while(curr!=afterEnd){

		nextNode = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = nextNode;
	}
	
	if(beforeStart){
		beforeStart->next = p2;
	}else{
		head = prev;
	}
 	
	print(head);
	return head;
}


int main(){

	ListNode* head =
	new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
//	new ListNode(1, new ListNode(2, new ListNode(3)));
//	new ListNode(1);
	print(head);
	cout << "\n";
	
	reverseBetween(head,2,4);
//	reverseBetween(head,3,5);
//	reverseBetween(head,1,1);
//	reverseBetween(head,1,4);
//	reverseBetween(head,1,5);
//	reverseBetween(head,3,3);
//	reverseBetween(head,4,5);

    return 0;
}

