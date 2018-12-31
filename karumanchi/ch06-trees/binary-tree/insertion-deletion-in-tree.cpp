/*
 * Author : Jatin Rohilla
 * Date   : 31-12-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

#include "tree.h"

// Prototypes

Node* insertElementByDFS(Node*, int);
Node* insertElementByBFS(Node*, int);

Node* findElement(Node*, int);

bool deleteElementByBFS(Node*&, int);
bool deleteTree(Node*&);

int main(){

	Node *root = makeTree({
	"{1, {2, {4}, {}}, {3, {6}, {7}}}"
//	"{1, {}, {}}"
	});
	printBinaryTree(root);
	int ele;

	ele = 8;
	cout << "\n\n\nInserting Element " << ele << " by DFS -\n\n";
	Node* DFSinsertion = insertElementByDFS(root, ele);
	printBinaryTree(DFSinsertion);
	

	ele = 8;
	cout << "\n\n\nInserting Element " << ele << " by BFS -\n\n";
	Node *root2 = makeTree({"{1, {2, {4}, {5}}, {3, {}, {7}}}"});
	Node* BFSinsertion = insertElementByBFS(root2, ele);
	printBinaryTree(BFSinsertion);


	ele = 5;
	cout << "\n\n\nFinding Element " << ele << " in tree : ";
	Node* res = findElement(root, ele);
	res == nullptr ? cout << "Not Found" : cout << "Found " << res->data;
	cout << "\n\n";


	ele = 1;
	cout << "\n\n\nDeleting Element " << ele << " in tree : ";
	cout << "\n\n";
	bool status = deleteElementByBFS(root, ele);
	printBinaryTree(root);
	cout << "\n\n";
	status == false ? cout << "Not Found" : cout << "Deleted " << ele;


	cout << "\n\nDeleting Tree  - ";
	deleteTree(root);

	return 0;
}

// Functions

// recursive solution possible as all DFS uses stack
// shortcoming : skewed tree
Node* insertElementByDFS(Node* root, int ele){
	
	if(root==nullptr){
		return new Node(ele);
	}

	if(!root->left){
		root->left = new Node(ele);
		return root;
	}
	
	if(!root->right){
		root->right = new Node(ele);
		return root;
	}
	
	root->left = insertElementByDFS(root->left, ele);
	return root;
}

// for BFS, only iterative version is possible because queue needed
// no problem of skewness. We'll use Level-order-traversal.
Node* insertElementByBFS(Node* root, int ele){
	if(root==nullptr){
		return new Node(ele);
	}
	
	queue<Node*> bfsQueue;
	bfsQueue.push(root);
	Node* it;
	while(!bfsQueue.empty()){
		it = bfsQueue.front();
		bfsQueue.pop();
		
		if(it->left){
			bfsQueue.push(it->left);
		}
		else{
			it->left = new Node(ele);
			break;
		}
		
		if(it->right){
			bfsQueue.push(it->right);
		}
		else{
			it->right = new Node(ele);
			break;
		}
	}
	return root;
}

Node* findElement(Node* root, int ele){
	if(root==nullptr){
		return nullptr;
	}
	
	if(root->data==ele){
		return root;
	}
	
	Node* lfind = findElement(root->left, ele);
	if(lfind != nullptr){
		return lfind;
	}
	else{
		return findElement(root->right, ele);
	}
}

// find last leaf of tree & copy data to deleting node
bool deleteElementByBFS(Node*& root, int ele){

	Node* nodeToBeDeleted = findElement(root, ele);
	if(nodeToBeDeleted==nullptr){
		return false;
	}
	
	// edge case
	if( root->data==ele && root->left==nullptr && root->right==nullptr){
		Node* deleteMe = root;
		root = nullptr;
		delete deleteMe;
		return true;
	}
	
	// find a space by level order
	queue<Node*> bfsQueue;
	bfsQueue.push(root);

	Node* it;
	Node* lastNodeWithSpace;
	while(!bfsQueue.empty()){
		it = bfsQueue.front();
		bfsQueue.pop();
		if(it->left || it->right){
			lastNodeWithSpace = it;
		}
		if(it->left){
			bfsQueue.push(it->left);
		}
		if(it->right){
			bfsQueue.push(it->right);
		}
	}
	
	if(lastNodeWithSpace->right){
		// use right child'
		nodeToBeDeleted->data = lastNodeWithSpace->right->data;
		Node* deleteMe = lastNodeWithSpace->right;
		lastNodeWithSpace->right = nullptr;
		delete deleteMe;
	}
	else{
		// use left child
		nodeToBeDeleted->data = lastNodeWithSpace->left->data;
		Node* deleteMe = lastNodeWithSpace->left;
		lastNodeWithSpace->left = nullptr;
		delete deleteMe;
	}
	return true;
}

// deleting tree : delete the children before parent
bool deleteTree(Node*& root){
	if(!root) return true;
	deleteTree(root->left);
	deleteTree(root->right);
	cout << "\nDeleting "<< root->data ;
	delete root;
	return true;
}

