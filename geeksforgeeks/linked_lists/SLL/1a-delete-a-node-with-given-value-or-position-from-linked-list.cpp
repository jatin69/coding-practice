/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

question -
1. delete a node with given value
https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/

2. delete a node at a given position
https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/

approach -
To delete a node, we need access to its previous element.

=> Treat head differently, as it has no previous
=> Rest all simple pointer manipulation

 
*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node* deleteNodeWithGivenValue(Node* head, int key){
	if(head==nullptr){
		return head;
	}
	
	if(head->data == key){
		Node* target = head;
		head = head->next;
		delete target;
		return head;
	}
	
	Node* trav = head;
	while(trav->next){
  		if(trav->next->data==key){
  			Node* target = trav->next;
			trav->next = trav->next->next;
			delete target;

			return head;
		}
		trav = trav->next;
	}

	return head;
	
}

Node* deleteNodeAtGivenPosition(Node* head, int pos){
	
	if(head==nullptr){
		return head;
	}
	
	if(pos==0){
		Node* target = head;
		head = head->next;
		delete target;
		return head;
	}
	
	Node* trav = head;
	pos = pos-1;
	while(pos--){
		trav = trav->next;
	}
	
	Node* target = trav->next;
	trav->next = trav->next->next;
	delete target;
	
	return head;
	
}


int main(){

	Node *head = makeSLL({
		1,2,3,4,5
	});
	printSLL(head);

//	int pos = 4;
//	head = deleteNodeAtGivenPosition(head, pos);
//	printSLL(head);

	int key = 5;
	head =deleteNodeWithGivenValue(head, key);
	printSLL(head);
	
    return 0;
}

