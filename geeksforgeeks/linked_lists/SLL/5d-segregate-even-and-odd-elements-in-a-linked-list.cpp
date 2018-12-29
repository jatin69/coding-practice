/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

question - https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
Statement -
segregate odd and even elements of linked list
order : EVEN FIRST, then ODD
Maintain respective orders of elements

example -
Input : 1->3->2->4->5->6->7->8
Output :  2->4->6->8->1->3->5->7

approach -
1. Initial appraoch -
remove odd nodes & append at end of list,
But this has lot of edge cases. Hard to code.

2. Efficient approach
Assume two lists, evenList and oddList
simply traverse the given list & add nodes to these lists
check if anyone is empty, return accordingly
else, append oddList at the end of evenList

Note: we are not actually using any additional memory for nodes,
we are just manipulating pointers.
So space complexity is constant.

Time complexity - O(n)

*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node* segregateOddEven(Node* head){
	
	if(head==nullptr || head->next==nullptr){
		return head;
	}
	
	Node* evenListStart = nullptr;
	Node* evenListEnd = nullptr;
	Node* oddListStart = nullptr;
	Node* oddListEnd = nullptr;
	Node* temp = nullptr;

	while(head){
		temp = head;
		head = head->next;
		
		if(temp->data%2==0){
			if(evenListStart==nullptr){
				evenListStart = temp;
				evenListEnd = evenListStart;
				evenListEnd->next = nullptr;
			}
			else{
				evenListEnd->next = temp;
				evenListEnd = evenListEnd->next;
				evenListEnd->next = nullptr;
			}
		}
		else{
			if(oddListStart==nullptr){
				oddListStart = temp;
				oddListEnd = oddListStart;
				oddListEnd->next = nullptr;
			}
			else{
				oddListEnd->next = temp;
				oddListEnd = oddListEnd->next;
				oddListEnd->next = nullptr;
			}
		}
	}
	
	// if either is empty
	if(evenListStart==nullptr){
		return oddListStart;
	}
	else if(oddListEnd==nullptr){
		return evenListStart;
	}
	
	evenListEnd->next = oddListStart;
	head = evenListStart;
	
	return head;
}

int main(){

	Node* head = makeSLL({
		1,3,5,2,4,6,8,7,9,11,10,12
//		1,2,4,3,5
//		2,4,1,3
//		2,4,6,8
//		1,3,5,7
//		8, 12, 10, 5, 4, 1, 6

	});
	printSLL(head);
	head = segregateOddEven(head);
	printSLL(head);
    return 0;
}

