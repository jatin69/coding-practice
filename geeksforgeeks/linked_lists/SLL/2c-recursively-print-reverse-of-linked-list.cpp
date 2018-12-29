/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

void printList(Node* head){
	
	if(head==nullptr){
		return ;
	}
	
	printList(head->next);
	cout << head->data << " ";
	
}

int main(){

	Node* head = makeSLL({1,2,3,4});
	printSLL(head);
	
	printList(head);

    return 0;
}

