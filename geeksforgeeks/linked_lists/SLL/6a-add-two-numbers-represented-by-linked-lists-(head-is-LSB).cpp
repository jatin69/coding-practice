/*
 * Author : Jatin Rohilla
 * Date   : 23-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

question link - https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
practice link - https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Question : add two numbers represented by linkedlists ( head is LSB )
approach : Because head is LSB, we can simply start adding
Time Complexity: O(m + n) where m and n are number of nodes in first and second lists respectively.

Accepted.
*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node*  addTwoLists(Node* first, Node* second){
	
	Node *resH = new Node(-1);  // dummy head
	Node *resT = resH;
	
	int sum   = 0;
	int carry = 0;

	while(first!=nullptr || second!=nullptr || carry!=0){
		
		sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
		
		if(sum>9){
			sum -= 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		
		resT->next = new Node(sum);
		resT = resT->next;
		
		first = (first ? first->next : nullptr);
		second = (second ? second->next : nullptr);
		
	}
	
	Node* delTarget = resH;
	resH = resH->next;
	delete delTarget;
	
	return resH;

}

int main(){

	Node* l1 = makeSLL({5,4});
	Node* l2 = makeSLL({5,4,3});
	
	Node* res = addTwoLists(l1,l2);
	printSLL(res);

    return 0;
}

