/*
 * Author : Jatin Rohilla
 * Date   : 27-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/

Statement -
In output, No node should have a greater node on the right side
i.e. delete all nodes which have graeter value on the right side

approach -
reverse list for easy max comparisons.
if curr >= max, update max, move forward
else delete this node using prev
( prev is max because all between nodes have already been deleted )
reverse list to restore order

Time - O(n)
Space - O(1)

*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"


/* Initial Interpretation of the Question
=> Deletes nodes which has a greater value Node on the right side in the original list */
Node* deleteRightGreater(Node* head){

	if(head==nullptr || head->next==nullptr){
		return head;
	}
	
	// dummy node
	head = new Node( INT_MAX, head);
	
	Node* prev = head;
	Node* trav = head->next;
	Node* target = nullptr;
	
	while(trav && trav->next ){
		
		if(trav->data < trav->next->data){
			target = trav;
			trav = trav->next;
			// prev remains same
			prev->next = prev->next->next;
			delete target;
		}
		else{
			prev = trav;
			trav = trav->next;
		}
	}
	
	target = head;
	head = head->next;
	delete target;
	return head;
}


Node* reverseSLL(Node* head){
	
	if(head==nullptr || head->next == nullptr){
		return head;
	}
	
	Node* prev = nullptr;
	Node* curr = head;
	Node* nextNode = nullptr;
	
	while(curr!=nullptr){
		nextNode = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = nextNode;
	}
	
	head = prev;
	return head;
}

/* Actual Interpretation
=> No node should have a greater value node in the output */
Node* deleteLesserNodes(Node* head){
	
	// Reverse for easy comparisons : o(n)
	head = reverseSLL(head);

	// delete lesser Nodes
	Node* max  = head;
	Node* trav = head->next;

	Node* target = nullptr;
	Node* prev = nullptr;

	while(trav){
		// if equal nodes ?
		// still update max, as it will be later used as previous
		if(trav->data >= max->data){
			max = trav;
			trav = trav->next;
		}
		else{
			target = trav;
			trav = trav->next;
			prev = max;			// max is prev always
			prev->next = prev->next->next;
			delete target;
		}
	}
	
	// retain original order : o(n)
	head = reverseSLL(head);

	return head;
}


int main(){

	Node* head = makeSLL({
//		12,15,10,11,5,6,2,3
		12,10,11,5,6,15,2,3     // => 15, 3
//		10,20,30,40,50,60
//		60,50,40,30,20,10
	});
	printSLL(head);
	
	head = deleteLesserNodes(head);
	printSLL(head);
	
    return 0;
}

