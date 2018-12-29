/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
question - https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
Similar to - pair wise reversal of linked list

*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node* pairSwapSLLNodes(Node* head){
	if(head == nullptr || head->next == nullptr){
		return head;
	}
	
	Node* prev = nullptr;
	Node* p1 = head;
	Node* p2 = head->next;
	
	while(1){
		p1->next = p2->next;
		p2->next = p1;
		if(prev){
			prev->next=p2;
		}
		else{
			head = p2;
		}
		
		prev = p1;
		p1 = prev->next;
		if(p1==nullptr){
			break;
		}
		p2 = p1->next;
		if(p2==nullptr){
			break;
		}
	}
	
	return head;
	
}

int main(){

	Node* head = makeSLL({ 1,2,3,4,5,6,7});
	printSLL(head);

	head = pairSwapSLLNodes(head);
	printSLL(head);


    return 0;
}

