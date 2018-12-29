/*
 * Author : Jatin Rohilla
 * Date   : 20-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

question -
https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/
https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

question has 3 objectives -
1. Detect if there is a cycle
2. Find the length of the cycle
3. Find the starting Node of the cycle

*/


#include<bits/stdc++.h>
using namespace std;

#include "SLL.h"

Node* makeSLLCycle(Node* head, int targetNodeValue){

	Node *targetNode;
	Node *t = head;
	while(t->next!=nullptr){
  		if(t->data==targetNodeValue){
  			targetNode = t;
		}
		t=t->next;
	}
	t->next = targetNode;

	return head;
}


/*
If cycle exists, return cycle lenght
else, returns zero
*/
void detectCycleViaFloyd(Node* head){
	
	// ********************* find if cycle exists **********************
	bool isCycle = false;
	Node* slow = head;
	Node* fast = head;
	while(slow && fast && fast->next ) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			isCycle = true;
			break;
		}
	}

	if(!isCycle){
		cout<< "\nNo Cycle exists.\n";
		return;
	}
	else{
		cout << "\nCycle exists.\n";
		


		// ********************* find cycle length *********************

		Node* temp = slow;
		int len = 1;

		while(temp->next!=slow){
			len++;
			temp = temp->next;
		}
		
		cout << "Cycle is of Length : " << len << "\n" ;

		
		// ***************** find starting node of cycle ******************
		/*
		This method specifically works for floyd's algo
		there's also a proof of this. read later.
		*/
		Node* p1 = slow;    // any node in cycle
		Node* p2 = head;   // head node

		while( p1 != p2){
			p1 = p1->next;
			p2 = p2 -> next;
		}
		
		cout << "Cycle start found at Node : " << p1->data << "\n";
		
	}
	
}

int main() {


  Node *head = makeSLL({1,2,3,4,5});
  cout << "Original List : ";
  printSLL(head);
  
  	// infinite display after cycle
  int cNode = 2;
  head = makeSLLCycle(head, cNode);
  cout << "Made a cycle at " << cNode << "\n";
	//  printSLL(head);
  detectCycleViaFloyd(head);
	

  return 0;
}

