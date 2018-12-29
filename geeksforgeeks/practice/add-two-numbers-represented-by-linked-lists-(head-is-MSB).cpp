/*
 * Author : Jatin Rohilla
 * Date   : 23-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

practice link - https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-represented-as-arrays/0
question link - https://www.geeksforgeeks.org/sum-of-two-linked-lists/

Question : add two numbers represented by linkedlists ( head is MSB )
approach :
Reverse the number lists
Now head is LSB, we can simply add.
Reverse the result.


O(n) time in reversal. O(n) in adding.
Time Complexity: O(m + n) where m and n are number of nodes in first and second lists respectively.
with factor 3

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


Node*  addTwoLists(Node* first, Node* second){

	Node *resH = new Node(-1);  // dummy head
	Node *resT = resH;

	int sum   = 0;
	int carry = 0;

	while(first!=nullptr || second!=nullptr || carry!=0){

		sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;

		if(sum>9){
			sum -= 10;
			carry = 1;
		}
		else{
			carry = 0;
		}

		resT->next = new Node(sum);
		resT = resT->next;

		first = (first ? first->next : nullptr);
		second = (second ? second->next : nullptr);

	}

	Node* delTarget = resH;
	resH = resH->next;
	delete delTarget;

	return resH;

}


Node* reverse(Node* head){

	if(head==nullptr || head->next==nullptr){
		return head;
	}

	Node* prev = nullptr;
	Node* curr = head;
	Node* nextNode = curr->next;

	while(curr!=nullptr){

		nextNode = curr->next;
		curr->next = prev;

		prev = curr;
		curr = nextNode;

	}

	head = prev;
	return head;

}

int main(){

	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		int ele;

		vector<int> A;
		for(int i=0;i<m;++i){
			cin>>ele;
			A.push_back(ele);
		}
		
		vector<int> B;
		for(int i=0;i<n;++i){
			cin>>ele;
			B.push_back(ele);
		}

		Node* l1 = makeSLL(A);
		Node* l2 = makeSLL(B);

		Node* res = reverse(addTwoLists(reverse(l1),reverse(l2)));
		print(res);
	}
	
    return 0;
}

