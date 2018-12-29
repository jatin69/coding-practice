/*
 * Author : Jatin Rohilla
 * Date   : 11/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
Question : pair wise reversal of a SLL
input  :  1->2->3->4->5
output :  2->1->4->3->5

approach : treat head differently as it needs to be stored, for others, simple pointer manipulation

 */

#include<bits/stdc++.h>
using namespace std;

#include "SLL.h"

Node* pair_wise_reversal(Node *head) {

  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  // swap p1 and p2 always

  Node *prev = nullptr;
  Node *p1 = head;
  Node *p2 = p1->next;
  head = p2;

  while (1) {

    p1->next = p2->next;
    p2->next = p1;
    
    if (prev != nullptr) {
      prev->next = p2;
    }
    
    // because p2 and p1 are now swapped
    prev = p1;

    p1 = prev->next;
    if (p1==nullptr) {
      break;
    }

    p2 = p1->next;
    if (p2==nullptr) {
      break;
    }
  }

  return head;
}


int main() {

    // original list
  Node *head = makeSLL({  1, 2, 3, 4, 5 });
  printSLL(head);

  // pair wise reversal
  head = pair_wise_reversal(head);
  printSLL(head);

  return 0;
}
