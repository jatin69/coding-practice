/*
 * Author : Jatin Rohilla
 * Date   : 26-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/make-middle-node-head-linked-list/

approach -
find middle, keep track of its prev.
remove it from that location, and add it before head.

*/

#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node* makeMiddleNodeHead(Node* head){

	// base cases
	if(head == nullptr || head->next==nullptr){
		return head;
	}
	
	Node* prev = nullptr;
	Node* slow = head;
	Node* fast = head;      // => if even no of nodes, use second middle

	while(slow && fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	// mid is at slow node, prev is its previous
	prev->next = prev->next->next;
	slow->next = head;
	head = slow;

	return head;
}

int main(){


	Node *head = makeSLL({
//			1,2,3,4,5       // => 1,2,4,5
			1,2,3,4,5,6     // => 1,2,3,5,6
		});
	printSLL(head);

	head = makeMiddleNodeHead(head);
	printSLL(head);

    return 0;
}

