/*
 * Author : Jatin Rohilla
 * Date   : 20-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

ques-
https://www.geeksforgeeks.org/brents-cycle-detection-algorithm/

question has 3 objectives -
1. Detect if there is a cycle
2. Find the length of the cycle
3. Find the starting Node of the cycle


approach - jump in powers of 2 to reduce constant factor in Floyd's

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
void detectCycleViaBrent(Node* head){

	// find if cycle exists & its length
	
	Node* slow = head;
	Node* fast = head;

	int len = 0;
	int power = pow(2,0);

	bool isCycle = false;

	while(fast){

		if(len==power){
			power <<=1;
			len = 0;
			slow = fast;
		}

		fast = fast->next;
		len++;

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
		cout << "\nCycle exists, and its length is : "<<len << "\n";

		// find starting node of cycle
		
		// start `slow` at head & `fast` at len distance from head
		// meaning, they are `len` distance far apart. when in cycle of length `len`, they will surely meet.
		slow = head;
		fast = head;
		int trav = len;
		while(trav--){
			fast = fast->next;
		}

		while(slow!=fast){
//			cout << "\nslow is "<<slow->data << " and fast is " << fast->data ;
			slow = slow->next;
			fast = fast->next;
		}

		Node* p1 = slow;
 		cout << "\nCycle start found at Node : " << p1->data << "\n";
	}
}

int main() {

  Node *head = makeSLL({1,2,3,4,5,6,7,8,9,10});
  cout << "Original List : ";
  printSLL(head);

  	// infinite display after cycle
  int cNode = 6;
  head = makeSLLCycle(head, cNode);
  cout << "Made a cycle at " << cNode << "\n";
	//  printSLL(head);
  detectCycleViaBrent(head);


  return 0;
}

