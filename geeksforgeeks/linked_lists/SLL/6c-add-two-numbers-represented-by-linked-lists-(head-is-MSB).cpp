/*
 * Author : Jatin Rohilla
 * Date   : 23-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

question link - https://www.geeksforgeeks.org/sum-of-two-linked-lists/
practice link - https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-represented-as-arrays/0

Question : add two numbers represented by linkedlists ( head is MSB )
approach :
Reverse the number lists
Now head is LSB, we can simply add.
Reverse the result.


O(n) time in reversal. O(n) in adding.
Time Complexity: O(m + n) where m and n are number of nodes in first and second lists respectively.
with factor 3

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

	Node* l1 = makeSLL({5,6,3});
	Node* l2 = makeSLL({8,4,2});

	Node* res = reverse(addTwoLists(reverse(l1),reverse(l2)));
	printSLL(res);

    return 0;
}

