/*
 * Author : Jatin Rohilla
 * Date   : 27-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/

*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

/* Initial Interpretation : delete n nodes after m nodes
special handling for m=0, as deletion of head */
Node* deleteNafterM(Node* head, int m, int n){

	if(head == nullptr){
		return head;
	}

	if(m==0){
		Node* target = nullptr;
		while(head && n--){
			target = head;
			head = head->next;
			delete target;
		}
	}
	else{
	 	Node* trav = head;
	 	m = m-1;
		while(m--){
			trav = trav->next;
		}

		Node* target = nullptr;
		while(trav && trav->next && n--){
			target = trav->next;
			trav->next = trav->next->next;
			delete target;
		}
	}
	
	return head;
}


/* Actual Interpretation : delete n nodes after m nodes & carry on till the end of linked list
m=0 will actually delete the whole list */
Node* skipMdeleteN(Node* head, int m, int n){

	if(head == nullptr){
		return head;
	}

	if(m==0){
		Node* target = nullptr;
		while(head){
			target = head;
			head = head->next;
			delete target;
		}
		return head;
	}
	
	m = m-1;   // to reach to previous node of target

	Node* trav = head;
	Node* target = nullptr;
	int x;
	
	while(trav){
		
		// skip
		x = m;
		while(trav && x--){
			trav = trav->next;
		}

		// delete
		x = n;
		while(trav && trav->next && x--){
			target = trav->next;
			trav->next = trav->next->next;
			delete target;
			// trav ( previous of target ) remains same
		}

		// move on to next iteration
		trav = trav ? trav->next : nullptr;
    }
	
	return head;
}

int main(){

	Node* head = makeSLL({
//		1,2,3,4,5,6,7,8     	// 2,2 => 1,2,5,6
//		1,2,3,4,5,6,7,8,9,10  	// 3,2 => 1,2,3,6,7,8
		1,2,3,4,5,6,7,8,9,10    // 1,1 => 1,3,5,7,9
	});
	printSLL(head);
	
	int m = 1;
	int n = 1;
//	head = deleteNafterM(head, m, n);
	head = skipMdeleteN(head, m, n);
	printSLL(head);
	
    return 0;
}

