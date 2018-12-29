/*
 * Author : Jatin Rohilla
 * Date   : 23-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question : Add one to number represented by linkedlist ( head is LSB )
 * approach : Similar to adding two lists.
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


int main(){

	Node* head = makeSLL({
		9,8
	});

	Node* res = addOneToList(head);
	printSLL(res);

    return 0;
}

