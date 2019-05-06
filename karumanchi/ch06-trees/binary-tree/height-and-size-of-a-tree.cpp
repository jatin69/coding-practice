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

int sizeOfTree(Node*);
int heightNode(Node*);
int heightNodeIterative(Node*);
int heightEdge(Node*);

int countFullNodes(Node*);
int countHalfNodes(Node*);
int countLeafNodes(Node*);

int main(){

	Node *root = makeTree({"{1, {2, {4}, {}}, {3, {6}, {7}}}"});
	printBinaryTree(root);
	cout << "\n\nTree Properties - ( Recursive )\n";
	cout << "\nSize of Tree                   : " << sizeOfTree(root);
	cout << "\nHeight of Tree ( Node height ) : " << heightNode(root);
	cout << "\nHeight of Tree ( Node height ) : " << heightNodeIterative(root);
	cout << "  (Iterative)";
	cout << "\nHeight of Tree ( Edge height ) : " << heightEdge(root);
	cout << "\n";
	cout << "\nTotal Number of Nodes          : " << sizeOfTree(root);
	cout << "\nNumber of Full Nodes           : " << countFullNodes(root);
	cout << "\nNumber of Half filled Nodes    : " << countHalfNodes(root);
	cout << "\nNumber of Leaf Nodes           : " << countLeafNodes(root);
    return 0;
}

// Functions

// size of tree : total no of nodes in tree
int sizeOfTree(Node* root) {
	if(root==nullptr){
		return 0;
	}
	return 1+sizeOfTree(root->left)+sizeOfTree(root->right);
}

// height of Tree - Node height
int heightNode(Node* root){

	if(!root) return 0;
	return 1 + max(heightNode(root->left), heightNode(root->right));
}

// height of Tree - Edge height
int heightEdge(Node* root){

	if(!root) return 0;
	if(root->left==nullptr && root->right==nullptr) return 0;
	return 1 + max(heightEdge(root->left), heightEdge(root->right));
}

// count full nodes
int countFullNodes(Node* root) {
	if(root==nullptr) return 0;

	int contribution = 0;
	if(root->left && root->right){
		contribution = 1;
	}
	return contribution + countFullNodes(root->left) + countFullNodes(root->right);
}

// count half nodes
int countHalfNodes(Node* root) {
	if(root==nullptr) return 0;

	int contribution = 0;
	if((root->left && !root->right) || (!root->left && root->right)){
		contribution = 1;
	}
	return contribution + countHalfNodes(root->left) + countHalfNodes(root->right);
}

// count leaf nodes
int countLeafNodes(Node* root) {
	if(root==nullptr) return 0;

	int contribution = 0;
	if(!root->left && !root->right){
		contribution = 1;
	}
	return contribution + countLeafNodes(root->left) + countLeafNodes(root->right);
}

// height of Tree - Node height - Iterative Version : finding No of levels
int heightNodeIterative(Node* root){
	if(!root) return 0;
	
	queue<Node*> Q;
	Node* nullNode = nullptr;
	Node* it;
	int level = 0;
	
	Q.push(root);
	Q.push(nullNode);   // end of first level
	
	while(!Q.empty()){
		it = Q.front();
		Q.pop();
		if(it==nullptr){
			++level;
			
			// put another marker for next level
			if(!Q.empty()){
				Q.push(nullNode);
			}
		}
		else{
			if(it->left){
				Q.push(it->left);
			}
			if(it->right){
				Q.push(it->right);
			}
		}
	}
	return level;
}

