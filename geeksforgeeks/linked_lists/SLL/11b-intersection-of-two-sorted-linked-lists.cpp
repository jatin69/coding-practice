/*
 * Author : Jatin Rohilla
 * Date   : 1-07-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
question - find the intersection list of two sorted link lists. ( Iteratively & Recursively )

approach : Both solutions follow same approach.

If nodes are equal, add to result.
If not move forward in the smaller list.

Time : O(n+m)

 */


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

// iterative implementation
Node* findIntersectionList(Node* l1, Node* l2){

	// use dummy pointer to handle empty list
	// SMART MOVE : occupy stack space
	Node dummy(INT_MIN);
	Node* resH = &dummy;
	resH->next = nullptr;
	Node* resT = resH;
	
	
	while(l1 && l2){
		if(l1->data == l2->data){
			resT->next = new Node(l1->data);
			resT = resT->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		else if(l1->data < l2->data){
			l1 = l1->next;
		}
		else{
			l2 = l2->next;
		}
	}
	
	return resH->next;
}

// recursive implementation
Node* findIntersectionListRecursively(Node* l1, Node* l2){

	if(l1==nullptr || l2==nullptr){
		return nullptr;
	}

	if(l1->data == l2->data){
		return new Node(l1->data, findIntersectionListRecursively(l1->next, l2->next));
	}
	else if(l1->data < l2->data){
		return findIntersectionListRecursively(l1->next, l2);
	}
	else{
		return findIntersectionListRecursively(l1, l2->next);
	}
}


int main(){

	Node* l1 = makeSLL({
		1,2,3,4,5,6
	});

	Node* l2 = makeSLL({
		2,4,6,8
	});

	printSLL(l1);
	printSLL(l2);

	Node* res;
	
	res = findIntersectionList(l1,l2);
	printSLL(res);

	res = findIntersectionListRecursively(l1,l2);
	printSLL(res);
	
    return 0;
}

