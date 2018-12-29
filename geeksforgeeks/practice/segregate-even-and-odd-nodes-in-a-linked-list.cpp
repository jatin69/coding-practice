/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
question link : https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list/0

approach :
Assume two lists, evenList and oddList
simply traverse the given list & add nodes to these lists
check if anyone is empty, return accordingly
else, append oddList at the end of evenList

Note: we are not actually using any additional memory for nodes,
we are just manipulating pointers.
So space complexity is constant.

Time complexity - O(n)

Accepted.

*/


#include<bits/stdc++.h>
using namespace std;

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

// print linkedlist as per question
void print(Node *trav) {
  while (trav != nullptr) {
    cout << trav->data << " ";
    trav = trav->next;
  }
  cout<<"\n";
}

// pretty print linkedlist
void printSLL(Node *trav) {
  while (trav != nullptr) {
    cout << trav->data << " -> ";
    trav = trav->next;
  }
  cout << "NULL\n";
}

Node* segregateOddEven(Node* head){

	if(head==nullptr || head->next==nullptr){
		return head;
	}

	Node* evenListStart = nullptr;
	Node* evenListEnd = nullptr;
	Node* oddListStart = nullptr;
	Node* oddListEnd = nullptr;
	Node* temp = nullptr;

	while(head){
		temp = head;
		head = head->next;

		if(temp->data%2==0){
			if(evenListStart==nullptr){
				evenListStart = temp;
				evenListEnd = evenListStart;
				evenListEnd->next = nullptr;
			}
			else{
				evenListEnd->next = temp;
				evenListEnd = evenListEnd->next;
				evenListEnd->next = nullptr;
			}
		}
		else{
			if(oddListStart==nullptr){
				oddListStart = temp;
				oddListEnd = oddListStart;
				oddListEnd->next = nullptr;
			}
			else{
				oddListEnd->next = temp;
				oddListEnd = oddListEnd->next;
				oddListEnd->next = nullptr;
			}
		}
	}

	// if either is empty
	if(evenListStart==nullptr){
		return oddListStart;
	}
	else if(oddListEnd==nullptr){
		return evenListStart;
	}

	evenListEnd->next = oddListStart;
	head = evenListStart;

	return head;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		vector<int> A;
		int n;
		cin>>n;
		int ele;
		for(int i=0;i<n;++i){
			cin>>ele;
			A.push_back(ele);
		}
		
		Node* head = makeSLL(A);
		head = segregateOddEven(head);
		print(head);
	}

    return 0;
}

