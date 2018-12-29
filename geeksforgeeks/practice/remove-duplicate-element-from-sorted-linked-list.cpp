/*
 * Author : Jatin Rohilla
 * Date   : 26-6-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

practice - https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
problem link - https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/

Input -
2
4
2 2 4 5
5
2 2 2 2 2

Output -
2 4 5
2

*/

//Code by Shubham Joshi
#include <bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
                Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next;
};*/
Node *removeDuplicates(Node *head)
{

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
