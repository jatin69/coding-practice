/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/insert-node-middle-linked-list/
 */

#include<bits/stdc++.h>
using namespace std;

#include "SLL.h"

// simply works for odd len
// need to make it work for even len
Node* insertAtMid(Node* head, int key){

	if(head==nullptr){
		head = new Node(key);
		return head;
	}
	

	Node* slow = head;

	/*
	When fast = head, 			middle will be (n/2)th node
	When fast = head->next, 	middle will be (n-1)th node
	
	Here, we use head->next, because
	for insertion at middle in even length lists, we need access to its prev node.
	*/
	Node* fast = head->next;


	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}

	// middle Node is `slow`
	
	Node* temp = new Node(key);
	temp->next = slow->next;
	slow->next = temp;
	
	return head;

}

int main(){

	Node *head = makeSLL({
//	  		1,2,4
			1,2,4,5
		});
	printSLL(head);

	head = insertAtMid(head,3);
	printSLL(head);

    return 0;
}
