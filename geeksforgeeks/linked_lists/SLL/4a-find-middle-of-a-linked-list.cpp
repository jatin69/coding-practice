/*
 * Author : Jatin Rohilla
 * Date   : 20-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * question - find mipoint of SLL
 * https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
 */


#include<bits/stdc++.h>
using namespace std;

#include "SLL.h"

Node* findMid(Node* head){

	if(head==nullptr || head->next==nullptr){
		return head;
	}

	Node* slow = head;

	/*
	When fast = head, 			middle will be (n/2)th node
	When fast = head->next, 	middle will be (n-1)th node
	*/
	Node* fast = head;

	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
	
}

int main(){


  Node *head = makeSLL({1,2,3,4,5});
  cout << "Original List : ";
  printSLL(head);
  
  Node* mid = findMid(head);
  if(mid){
  	cout << "\nMiddle Node is : "<<mid->data;
  }
  
    return 0;
}

