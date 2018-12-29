/*
 * Author : Jatin Rohilla
 * Date   : 23-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

ques - https://www.geeksforgeeks.org/add-1-number-represented-linked-list/

Statement - add 1 to a number given by a linked list ( head is MSB )

approach - ( code a recursive solution || do it without reversing the list)


 */

#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

int addOneRecursive(Node* head){

	if(head==nullptr){
		return 1;       // because 1 is to be added
	}

	int sum = head->data + addOneRecursive(head->next);

	head->data = sum%10;
	int carry = sum/10;

	return carry;
}

Node*  addOneToList(Node* head){

	int carry = addOneRecursive(head);

	// add 1 to front
	if(carry){
		Node* temp = new Node(1, head);
		head = temp;
	}

	return head;
}


int main(){

	Node* head = makeSLL({
		1,9,9
	});

	Node* res = addOneToList(head);
	printSLL(res);

    return 0;
}

