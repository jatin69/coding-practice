/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/insert-node-n-th-node-end/

*/


#include<bits/stdc++.h>
using namespace std;

#include "SLL.h"

Node* addNodeAfterNthNodeFromEnd(Node* head, int n, int key){

	if(head==nullptr){
		return head;
	}

	int trav = n;

	// setup two node at `n` distance from each other
	Node* p1 = head;
	Node* p2 = head;
	while(trav--){
		p2 = p2->next;
	}

	// Now simply trav until p2 is null
	while(p2){
		p1 = p1->next;
		p2 = p2->next;
	}

	// p1 is the required node
//	cout << "p1 is "<<p1->data << endl;
	Node *temp = new Node(key, p1->next);
	p1->next = temp;
	
	return head;
	
}

int main(){

  Node *head = makeSLL({1,2,3,4,6,7,8});
  printSLL(head);

  int n = 4;
  int key = 5;
  head = addNodeAfterNthNodeFromEnd(head, n, key );
  printSLL(head);

  return 0;
}

