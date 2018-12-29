/*
 * Author : Jatin Rohilla
 * Date   : 1-07-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

 */


#include<bits/stdc++.h>
using namespace std;

#include "SLL.h"


/* Length difference method */
Node* findIntersectionPoint(Node* l1, Node* l2){
	
	Node* t;
	int c1=0;
	int c2=0;
	
	t = l1;
	while(t){
		++c1;
		t = t->next;
	}

	t = l2;
	while(t){
		++c2;
		t = t->next;
	}

	Node* longer ;
	Node* shorter ;
	int diff = abs(c1-c2);

	if(c1 >= c2){
		longer = l1;
		shorter = l2;
	}
	else{
		longer = l2;
		shorter = l1;
	}
	
	while(diff--){
		longer = longer->next;
	}
	
	
	while(longer!=shorter){
		longer = longer->next;
		shorter = shorter->next;
	}
	
	return longer;
}


int main(){
	Node* l1 = makeSLL({
		3,6,9,15,30
	});
	
	Node* t = l1;
	while(t->data!=15){
		t = t->next;
	}
	
	Node* l2 = new Node(10);
	l2->next = t;
	
	printSLL(l1);
	printSLL(l2);

	Node* res;

	// length difference method
	res = findIntersectionPoint(l1,l2);

	if(res){
		cout << "Intersection Node is : " << res->data;
	}
	else{
		cout << "No intersection.";
	}
	
	return 0;
}

