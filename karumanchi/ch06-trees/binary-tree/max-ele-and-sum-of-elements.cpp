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
int maxElement(Node*);
int sumOfElements(Node*);


int main(){

	Node *root = makeTree({"{1, {2, {4}, {}}, {3, {6}, {7}}}"});
	printBinaryTree(root);
	cout << "\nMax element is  : " << maxElement(root);
	cout << "\nSum of Elements : " << sumOfElements(root);

    return 0;
}


int maxElement(Node* root){
	if(!root){
		return INT_MIN;
	}
	return max(root->data, max(maxElement(root->left), maxElement(root->right)));
}

int sumOfElements(Node* root){
	if(!root){
		return 0;
	}
	return root->data + sumOfElements(root->left) + sumOfElements(root->right);
}
