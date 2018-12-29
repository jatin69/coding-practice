/*
 * Author : Jatin Rohilla
 * Date   : 1-07-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link -
https://www.geeksforgeeks.org/given-linked-list-line-segments-remove-middle-points/
https://www.geeksforgeeks.org/iterative-approach-for-removing-middle-points-in-a-linked-list-of-line-segements/

approach -
Note that : every adjacent pair forms a line segment.
leverage the fact that -
if `x - y - z` lies on the same line, deleting y is safe
so we store `x` in `t` & check if `t->next->next` is in the same line,
if yes, we delete `t->next`


Algo -
a. Traverse in the linked list, keep track of current node, next node and next-next node.
b. If x or y value of current, next and next-next are equal then delete next.
c. Do this until any of current, next and next-next is not null.
d. If adjacent points doesn`t have either same x or same y,then print invalid input

*/


#include<bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
  int x, y;
  Node *next;

  Node(int _x, int _y, Node *_next = nullptr) {
    x = _x;
    y = _y;
    next = _next;
  }

};

// pretty print linkedlist
void printSLL(Node *trav) {
  while (trav != nullptr) {
    cout << "(" << trav->x << ", " << trav->y << ") -> ";
    trav = trav->next;
  }
  cout << "NULL\n";
}


Node* deleteMiddlePoints(Node* head){
	
	if(head==nullptr){
		return head;
	}
	
	Node* t = head;
	Node* target = nullptr;
	
	while(t->next->next){
		if( !((t->x == t->next->x) || (t->y == t->next->y ))){
		   	cout << "\nInvalid Input !\n";
		   	return nullptr;
		}
		if((t->x == t->next->x && t->next->x == t->next->next->x) ||
		   (t->y == t->next->y && t->next->y == t->next->next->y)){
			target = t->next;
			t->next = t->next->next;
			delete target;
		}
		else{
			t = t->next;
		}
	}
	return head;
}


int main(){

	Node* head =
//  one horizontal line
//	new Node(2,3, new Node(4,3, new Node(6,3, new Node(10,3, new Node(12,3)))));

//  one vertical line
//	new Node(9,1, new Node(9,3, new Node(9,7, new Node(9,15, new Node(9,21)))));

//  one horizontal & one vertical line
//  new Node(13,1, new Node(13,3, new Node(13,7, new Node(15,7, new Node(15,9, new Node(15,11))))));

//  invalid input cases
//	new Node(13,1, new Node(4,13, new Node(13,7, new Node(15,7, new Node(15,9, new Node(15,11))))));
//	new Node(13,1, new Node(13,3, new Node(13,7, new Node(15,7, new Node(15,9, new Node(15,11, new Node(11,13, new Node(13,9, new Node(9,7)))))))));

//  horizontal - vertical - horizontal cases
	new Node(0,10, new Node(1,10, new Node(5,10, new Node(7,10, new Node(7,5, new Node(20,5, new Node(40,5)))))));
//	new Node(0,10, new Node(1,10, new Node(3,10, new Node(10,10, new Node(10,8, new Node(10,5, new Node(20,5, new Node(40,5))))))));
	
	printSLL(head);
	
	head = deleteMiddlePoints(head);
	printSLL(head);
    return 0;
}

