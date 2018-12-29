/*
 * Author : Jatin Rohilla
 * Date   : 27-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

practice - https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
link - https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

approach - reversal of latter half. O(n) time and O(1) space

Input -
2
3
1 2 1
4
1 2 3 4

Output
1
0


Input -
1
5

Output -
1

*/

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */

bool isIdenticalSLL(Node* f, Node* s){
	while(f && s){
		if(f->data!=s->data){
			return false;
		}
		f = f->next;
		s = s->next;
	}

	return f==nullptr && s==nullptr;
}

Node* reverseSLL(Node* head){

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


bool isPalindrome(Node *head)
{
    if( head==nullptr || head->next==nullptr){
		return true;
	}

	Node* prev = nullptr;
	Node* slow = head;
	Node* fast = head;

	while(fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	// slow is mid & prev is its previous node

	Node *first, *middle, *second;

	bool isOdd = fast!=nullptr;
	// odd number of nodes
	if(isOdd){
		first = head;
		prev->next = nullptr;
		middle = slow;
		second = slow->next;
	}
	else{
		first = head;
		prev->next = nullptr;
		middle = nullptr;
		second = slow;
	}

// 	printSLL(first);
// 	printSLL(second);
	Node* secondRev = reverseSLL(second);
// 	printSLL(secondRev);
	bool isIdentical = isIdenticalSLL(first, secondRev);
	second = reverseSLL(secondRev);

	// move to end of first list
	while(first->next!=nullptr){
		first = first->next;
	}

	if(isOdd){
		first->next = middle;
		middle->next = second;
	}
	else{
		first->next = second;
	}

// 	printSLL(head);
	if(isIdentical){
		return true;
	}
	else{
		return false;
	}
}
