/*
 * Author : Jatin Rohilla
 * Date   : 27-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
practice - https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

approach -

1. use stack, classic approach => useful when modification of linked list is read only.

2.	reverse later half of list,
	compare if first half and later half are now identical,
	then reverse again to restore back to original form.
	=> O(n) Solution and constant space.
	=> Modifies list, but later restores as well.

 */


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

// ********* Method 1 : Using Stack ************
// O(n) time and O(n) space

bool isPalindromeByStack(Node *head)
{
    stack<int>s;
    Node* n = head;
    while(n!=NULL){
        s.push(n->data);
        n = n->next;
    }
    n = head;
    while(n!=NULL){
        if(s.top()!=n->data)
            return false;
        n = n->next;
        s.pop();
    }
    return true;
}

// ********* Method 2 : Using Recursion ************
// O(n) time and O(n) space
// No good.


// ********* Method 3 : Using Reversal of LL *********
// O(n) time and O(1) space

bool isIdenticalSLL(Node* f, Node* s){
	while(f && s){
		if(f->data!=s->data){
			return false;
		}
		f = f->next;
		s = s->next;
	}
	
	return f==nullptr && s==nullptr;
}

Node* reverseSLL(Node* head){

  if(head==nullptr || head->next==nullptr){
  	return head;
  }

  Node *prev = nullptr;
  Node *curr = head;
  Node *nextNode = curr->next;

  while (curr != NULL) {
	nextNode = curr->next;
	curr->next = prev;
    prev = curr;
    curr = nextNode;
  }

  head = prev;
  return head;
}

bool isPalindromeByReversal(Node* head){
	
	if( head==nullptr || head->next==nullptr){
		return true;
	}
	
	Node* prev = nullptr;
	Node* slow = head;
	Node* fast = head;
	
	while(fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	
	// slow is mid & prev is its previous node

	Node *first, *middle, *second;
	
	bool isOdd = fast!=nullptr;
	// odd number of nodes
	if(isOdd){
		first = head;
		prev->next = nullptr;
		middle = slow;
		second = slow->next;
	}
	else{
		first = head;
		prev->next = nullptr;
		middle = nullptr;
		second = slow;
	}

//	printSLL(first);
//	printSLL(second);
	Node* secondRev = reverseSLL(second);
//	printSLL(secondRev);
	bool isIdentical = isIdenticalSLL(first, secondRev);
	second = reverseSLL(secondRev);

	// move to end of first list
	while(first->next!=nullptr){
		first = first->next;
	}
	
	if(isOdd){
		first->next = middle;
		middle->next = second;
	}
	else{
		first->next = second;
	}
	
//	printSLL(head);
	if(isIdentical){
		return true;
	}
	else{
		return false;
	}
}


int main(){

	Node* head = makeSLL({
		1,2,3,2,1
//  		1,2,1
	});
	printSLL(head);
	isPalindromeByReversal(head) ?  cout << "yes\n" : cout << "no\n";
	printSLL(head);
	
    return 0;
}

