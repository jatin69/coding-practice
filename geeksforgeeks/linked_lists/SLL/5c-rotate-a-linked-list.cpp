/*
 * Author : Jatin Rohilla
 * Date   : 26-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

Question : rotate a SLL counter-clockwise  / clockwise

*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"


/*
Left Rotation (counter clockwise rotation)
link - https://www.geeksforgeeks.org/rotate-a-linked-list/
practice - https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

approach :
Single pass.
because we are doing it all in single pass,
when encountered with k >>> len, it does a lot of extra movement.
Can be prevented with one more pass & modulo operation.
*/
Node* LeftRotateSLL(Node* head, int k){
	
	if(head==nullptr || head->next==nullptr || k<=0){
		return head;
	}

	k = k-1; 		// because we need to capture prev node
	
	Node* trav = head;
	while(k--){
		trav = trav->next;
		if(trav==nullptr){
			trav=head;
		}
	}
	
	Node* tail = trav;
	while(tail->next){
		tail = tail->next;
	}
	
	tail->next = head;
	head = trav->next;
	trav->next = nullptr;

	return head;
}


/*
Right Rotation (Clockwise rotation)
link - https://www.interviewbit.com/problems/rotate-list/

approach :
takes 2 pass. One for length. One for processing.
Because we take a pass for length, we can handle when k >>> len by using modulo
*/
Node* RightRotateSLL(Node* head, int k) {

	// find length
    Node* t = head;
    int len = 0;
    while(t){
        ++len;
        t = t->next;
    }

	// when k>>>len
    k = k%len;

	// no rotation required
    if(k==0){
        return head;
    }

	// pointer manipulation
    Node* oldHead = head;
    t = head;
    k = len - k - 1;
    while(k--){
        t = t->next;
    }

    Node* prev = t;
    while(t->next){
        t = t->next;
    }

    t->next = oldHead;

    head = prev->next;
    prev->next = nullptr;

    return head;
}


int main(){

	Node* head ;
	
	head = makeSLL({ 1,2,3,4,5 });
	cout << "Original list  :  ";
	printSLL(head);

	int k=1;
	
	head = makeSLL({ 1,2,3,4,5 });
	head = LeftRotateSLL(head, k);
	cout << "Left  Rotation :  ";
	printSLL(head);

	head = makeSLL({ 1,2,3,4,5 });
	head = RightRotateSLL(head, k);
	cout << "Right Rotation :  ";
	printSLL(head);
    return 0;
}

