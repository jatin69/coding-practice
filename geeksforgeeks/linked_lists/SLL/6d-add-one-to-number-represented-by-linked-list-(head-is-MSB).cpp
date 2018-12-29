/*
 * Author : Jatin Rohilla
 * Date   : 23-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question : Add one to number represented by linkedlist ( head is LSB )
 * approach : Similar to adding two lists (head is MSB)
 * reverse list. add 1. reverse result.
 */


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node*  addOneToList(Node* l1){

	Node* resH = new Node(-1);   // dummy head
	Node* resT = resH;

	int sum = 0;
	int carry = 1;  // because we wanna add one

	while(l1 || carry){
		sum = (l1 ? l1->data : 0 ) + carry;
		if(sum>9){
			sum -= 10;
			carry = 1;
		}
		else{
			carry = 0;
		}

		resT->next = new Node(sum);
		resT = resT->next;

		l1 = l1 ? l1->next : nullptr;
	}

	Node* temp = resH;
	resH = resH->next;
	delete temp;

	return resH;

}


Node* reverse(Node* head){

	if(head==nullptr || head->next==nullptr){
		return head;
	}

	Node* prev = nullptr;
	Node* curr = head;
	Node* nextNode = curr->next;

	while(curr!=nullptr){

		nextNode = curr->next;
		curr->next = prev;

		prev = curr;
		curr = nextNode;

	}

	head = prev;
	return head;

}


int main(){

	Node* head = makeSLL({
		1,9,9,9
	});


	Node* res = reverse(addOneToList(reverse(head)));
	printSLL(res);

    return 0;
}

