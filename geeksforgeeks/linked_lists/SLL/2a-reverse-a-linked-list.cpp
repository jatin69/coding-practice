/*
 * Author : Jatin Rohilla
 * Date   : 20/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : reversal of a linked list
 */

#include<bits/stdc++.h>
using namespace std;

#include "SLL.h"

Node* reverse(Node* head) {

  if(head==nullptr || head->next==nullptr){
  	return head;
  }

  Node *prev = nullptr;
  Node *curr = head;
  Node *nextNode = curr->next;

  while (curr != NULL) {

	nextNode = curr->next;

	curr->next = prev;
    
    prev = curr;
    curr = nextNode;
  }
  
  head = prev;

  return head;
}

int main() {

  // original list
  Node *head = makeSLL({  1, 2, 3, 4, 5 });
  printSLL(head);

  // normal reversal
  head = reverse(head);
  printSLL(head);

  return 0;
}
