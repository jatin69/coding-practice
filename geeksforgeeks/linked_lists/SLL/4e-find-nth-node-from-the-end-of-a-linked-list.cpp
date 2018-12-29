/*
 * Author : Jatin Rohilla
 * Date   : 20-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

question - Nth node from end of LL
https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
 
approach - setup two nodes `n` nodes apart from each other.
`one` starts at head. `Other` at head+n
Simply move forward. When `other` hits the list end, they will still be n nodes apart.
so `one` simply points to the Nth end form last.

 */


#include<bits/stdc++.h>
using namespace std;

#include "SLL.h"

Node* findNthFromEnd(Node* head, int n){

	if(head==nullptr){
		return head;
	}

	int trav = n;
	
	// setup two node at `n` distance from each other
	Node* p1 = head;
	Node* p2 = head;
	while(trav--){
		p2 = p2->next;
		if(p2==nullptr && trav!=0){
			return nullptr;
		}
	}
	
	// Now simply trav until p2 is null
	while(p2){
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}

int main(){

  Node *head = makeSLL({1,2,3,4,5,6,7,8});
  cout << "Original List : ";
  printSLL(head);

  int target = 4;
  Node* nth = findNthFromEnd(head, target );
  if(nth){
  	cout << "\n"<< target << "th Node from End is : "<<nth->data;
  }

  return 0;
}

