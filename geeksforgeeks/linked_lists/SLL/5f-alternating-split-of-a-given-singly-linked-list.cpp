/*
 * Author : Jatin Rohilla
 * Date   : 01-07-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/alternating-split-of-a-given-singly-linked-list/
practice -  https://practice.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1

 */


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"


void alternatingSplitList(Node* head, Node** _l1, Node** _l2){
	
	// 2D to 1D
	Node* l1 = *_l1;
	Node* l2 = *_l2;

	// dummy nodes
 	Node d1(INT_MIN);
	l1 = &d1;
	Node* l1tail = l1;

	Node d2(INT_MIN);
	l2 = &d2;
	Node* l2tail = l2;

	while(1){
		
		// remove from front & add to l1
		if(head==nullptr){
			break;
		}
		l1tail->next = head;
		head = head->next;
		l1tail = l1tail->next;
		
		// remove from front & add to l2
		if(head==nullptr){
			break;
		}
		l2tail->next = head;
		head = head->next;
		l2tail = l2tail->next;

	}
	
	l1tail->next = nullptr;
	*_l1 = l1->next;
	
	l2tail->next = nullptr;
	*_l2 = l2->next;
}

int main(){

	Node* head = makeSLL({
		1,0,1,0,1,0
	});
	
	Node* l1 = nullptr;
	Node* l2 = nullptr;
	
	alternatingSplitList(head, &l1, &l2);
	printSLL(l1);
	printSLL(l2);
	
    return 0;
}

