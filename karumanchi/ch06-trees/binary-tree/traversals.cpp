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

void visit(Node* r){
	cout << r->data << "  ";
}

// DFS

void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);

void inOrderIterative(Node*);
void preOrderIterative(Node*);
void postOrderIterative(Node*);


// BFS

void levelOrderTraversal(Node*);
void levelOrderReverse(Node*);

int main(){

	Node *root = makeTree({"{1, {2, {4}, {5}}, {3, {6}, {7}}}"});
	printBinaryTree(root);
	
	cout << "\n\ninOrder (Recursive)    :  "; inOrder(root);
	cout << "\ninOrder (Iterative)    :  "; inOrder(root);

	cout << "\n\npreOrder (Recursive)   :  "; preOrder(root);
	cout << "\npreOrder (Iterative)   :  "; preOrder(root);

	cout << "\n\npostOrder (Recursive)  :  "; postOrder(root);
	cout << "\npostOrder (Iterative)  :  "; postOrder(root);

	cout << "\nLevelOrder (Iterative) :  "; levelOrderTraversal(root);

    return 0;
}


// Functions

void inOrder(Node* root){
	if(root){
		inOrder(root->left);
		visit(root);
		inOrder(root->right);
	}
}

void preOrder(Node* root){
	if(root){
		visit(root);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(Node* root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		visit(root);
	}
}

void inOrderIterative(Node* root){
	
}

void preOrderIterative(Node* root){

}

void postOrderIterative(Node* root){

}


// BFS
void levelOrderTraversal(Node* root){

	if(root==nullptr){
		return;
	}

	queue<Node*> bfsQueue;
	bfsQueue.push(root);
	Node* it;
	
	while(!bfsQueue.empty()) {
		it = bfsQueue.front();
		bfsQueue.pop();
		visit(it);
		
		if(it->left){
			bfsQueue.push(it->left);
		}
		if(it->right){
			bfsQueue.push(it->right);
		}
	}
}

// start from lower level upto top level
void levelOrderReverse(Node* root){
	
}
