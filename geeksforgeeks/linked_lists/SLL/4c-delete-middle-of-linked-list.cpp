/*
 * Author : Jatin Rohilla
 * Date   : 26-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/delete-middle-of-linked-list/

approach -
find middle, keep track of its prev.
then delete it.

 */


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node* deleteMiddle(Node* head){
	
	// base cases
	if(head == nullptr){
		return head;
	}
	if(head->next == nullptr){
		delete head;
		head = nullptr;
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
	delete slow;
	return head;
}

int main(){


	Node *head = makeSLL({
//			1,2,3,4,5       // => 1,2,4,5
			1,2,3,4,5,6     // => 1,2,3,5,6
		});
	printSLL(head);

	head = deleteMiddle(head);
	printSLL(head);

    return 0;
}

