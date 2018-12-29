/*
 * Author : Jatin Rohilla
 * Date   : 26-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.geeksforgeeks.org/rotate-a-linked-list/
practice - https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

approach -
collective rotation.

Used **head_ref

*/


{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
}*head;
void rotate(struct node **head_ref, int k);
  void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,n,value;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     rotate(&head,k);
     printList(head);
     }
     return(0);
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Rotate a linked list after node k
  The input list will have at least one element
  Return pointer to head of rotated linked list
  Node is defined as
  struct node
  {
     int data;
     struct node *next;
  }
*/
void rotate(struct node **head_ref, int k)
{
    node* head = *head_ref;

  	if(head==nullptr || head->next==nullptr || k<=0){
		return;
	}


	k = k-1; 		// because we need to capture prev node

	node* trav = head;
	while(k--){
		trav = trav->next;
		if(trav==nullptr){
			trav=head;
		}
	}

	node* tail = trav;
	while(tail->next){
		tail = tail->next;
	}

	tail->next = head;
	head = trav->next;
	trav->next = nullptr;

	*head_ref = head;
}

