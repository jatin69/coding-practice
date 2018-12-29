/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
question - https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/

approach -
Using single pass, find p1 and p2 ( based on values of x and y )
In this pass, keep track of prev because swapping of p1 will need prev

cases :
1. if p1==p2, simply return
2. if p1 or p2 is not present, simply return
3. p1 is head
4. p1 and p2 is adjacent
5. p1 and p2 has gap of 1 or >1

Also, consider cases
case 1 : p1 & p2 are same Node   => simply return
case 2 : p1 occurs before p2     => whole algo is based on this assumption
case 3 : p2 occurs before p1     => swap p1 & p2 & use case 2

Then simple pointer manipulation
*/


#include<bits/stdc++.h>
using namespace std;
#include "SLL.h"

Node* swapSLLNodes(Node* head, int x, int y){

	// base case
	if(x==y){
		return head;
	}
	
	// initialise to prevent dangling pointers
	Node *p1prev = nullptr;
	Node *p1 = nullptr;
	Node *p2prev = nullptr;
	Node *p2 = nullptr;

	int nD = 0;     // Node distance from head is incremented
	int p1D = 0;     // distance of p1 from head
	int p2D = 0;     // distance of p2 from head

	// find Nodes
	bool headFirst = false;

	// check at head : special case
	if(head->data == x){
		p1prev = nullptr;
		p1 = head;
		p1D = 0;
		headFirst = true;
	}
	else if(head->data == y){
		p2prev = nullptr;
		p2 = head;
		p2D = 0;
		headFirst = true;
	}

	
	Node* trav = head;
	// trav        goes from `head`       to `tail-1`
	// comparisons go   from `head->next` to `tail`
	while(trav->next!=nullptr){
		
		// Node distance from head is incremented
		nD++;

		if( trav->next->data == x){
			p1prev = trav;
			p1   = trav ->next;
			p1D = nD;
		}
		else if( trav->next->data == y){
			p2prev = trav;
			p2 = trav->next;
			p2D = nD;
		}
		if(p1&&p2){
			break;
		}
		trav = trav->next;
	}
	
	// if not found in list, simply return
	if(!(p1 && p2)){
		return head;
	}
	
	cout << "p1 is "<<p1->data << " and p2 is "<<p2->data << "\n";

	// if both are found, ensure than p1 occurs before p2 => p1 < p2
	// if p2 is before p1, swap is needed
	if(p2D < p1D){
		Node* t ;
		
		// swap nodes
		t = p1;
		p1 = p2;
		p2 = t;

		// swap prev
		t = p1prev;
		p1prev = p2prev;
		p2prev = t;

	}
	
	cout << "p1 is "<<p1->data << " and p2 is "<<p2->data << "\n";
	
	// head : special case
	if(!headFirst){
		p1prev->next = p2;
	}
	else{
		head = p2;
	}
	
	Node *temp = p1->next;
	p1->next = p2->next;
	p2->next = temp;
	
	// temp == p2 when nodes are adjacent
	if(temp!=p2){
		// when gap = 1, this will not execute
		// when gap > 1, this will execute
		while(temp->next!=p2){
			temp = temp->next;
		}
	}
	temp->next = p1;
	
	return head;

}

int main(){

	Node* head = makeSLL({ 1,2,3,4,5,6,7,8 });
	printSLL(head);

	int x = 8;
	int y = 1;
	
	head = swapSLLNodes(head, x, y);
	printSLL(head);

    return 0;
}

