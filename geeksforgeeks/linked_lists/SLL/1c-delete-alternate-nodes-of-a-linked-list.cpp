/*
 * Author : Jatin Rohilla
 * Date   : 27-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/delete-alternate-nodes-of-a-linked-list/
practice - https://practice.geeksforgeeks.org/problems/delete-alternate-nodes/1

 */


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node* deleteAlternate(Node* head){
	
	if(head==nullptr || head->next==nullptr){
		return head;
	}
	
	Node *trav = head;
	Node *target = nullptr;
	
	while(trav && trav->next){
		target = trav->next;
		trav->next = trav->next->next;
		delete target;
		trav = trav->next;
	}
	
	return head;
}

int main(){

	Node* head = makeSLL({
//		1,2,3,4,5
		1,2,3,4
	});
	
	printSLL(head);
	head = deleteAlternate(head);
	printSLL(head);
	

    return 0;
}

