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

bool isIdentical(Node* l1, Node* l2){
	while(l1 && l2){
		if(l1->data != l2->data){
			return false;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	
	// both should have ended
	return l1==nullptr && l2==nullptr;
}

int main(){

	Node* l1 = makeSLL({1,2,3});
	Node* l2 = makeSLL({1,2,3});

	isIdentical(l1,l2) ? cout << "yes" : cout << "no"   ;
    return 0;
}

