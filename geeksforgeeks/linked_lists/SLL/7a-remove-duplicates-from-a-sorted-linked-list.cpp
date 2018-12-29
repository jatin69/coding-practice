/*
 * Author : Jatin Rohilla
 * Date   : 26-6-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
link - https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
practice - https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

approach -
Although, we can skip to last duplicate in a sequence of dups,
it will result in memory leak.
We have to delete them one by one.

*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node* removeDupSorted(Node* head){

	if(head == nullptr || head->next == nullptr){
		return head;
	}
	
	Node* trav = head;
	Node* target;
	
	while(trav->next){
//		cout << "trav : " << trav->data << " and trav->next : " << trav->next->data << "\n";
		if(trav->data == trav->next->data){
			// gotta delete trav->next
			target = trav->next;
			trav->next = trav->next->next;
			delete target;
		}
		else{
			trav = trav->next;
		}
	}
	
	return head;
}

int main(){

	Node* head = makeSLL({
		11,11,11,21,43,43,60
//		2,2,2,2,2
	});
	printSLL(head);

	head = removeDupSorted(head);
	printSLL(head);
    return 0;
}

