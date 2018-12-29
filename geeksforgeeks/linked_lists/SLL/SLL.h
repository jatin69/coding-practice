/*
 * Author : Jatin Rohilla
 * Date   : 20-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

Objective : header file for linked list
usage :
```
#include "SLL.h"
```

Possibilities : We can also make namespace for SLL.

=> syntax
```
namespace SLL{
	.. everything same as below ..
}
```

=> Then the usage will becomes.
```
#include "SLL.h"
using namespace SLL;
```
*/

// Node structure
struct Node {
  int data;
  Node *next;

  Node(int _data, Node *_next = nullptr) {
    data = _data;
    next = _next;
  }

};

// function to make linkedlist from vector
Node* makeSLL(vector<int> A){

	if(A.size()==0){
		return nullptr;
	}

	Node* head = new Node(*A.begin());
	Node* curr = head;
	for(vector<int>::iterator it=A.begin()+1; it!=A.end(); ++it) {
		curr->next = new Node(*it);
		curr = curr->next;
	}
	curr->next = nullptr;
	return head;
}

// pretty print linkedlist
void printSLL(Node *trav) {
  while (trav != nullptr) {
    cout << trav->data << " -> ";
    trav = trav->next;
  }
  cout << "NULL\n";
}


