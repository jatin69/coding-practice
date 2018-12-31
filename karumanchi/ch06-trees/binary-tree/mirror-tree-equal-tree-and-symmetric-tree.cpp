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

void mirrorTreeInPlace(Node*);
Node* mirrorTreeAndReturnModifiedTree(Node*);

Node* mirrorTreeAndReturnNewTree(Node*);

bool isMirror(Node*, Node*);
bool isEqual(Node*, Node*);

bool isTreeSymmetric(Node*);


int main(){

	// Initial Tree
	Node *root = makeTree({
	"{1, {2, {4}, {5}}, {3, {6}, {7}}}"
//	"{1, {2, {}, {5, {8}, {9} }}, {3, {}, {7}}}"
	});
	printBinaryTree(root);

	cout << "\nTree Mirror - ( Recursive )\n";
	
	Node* mTree = mirrorTreeAndReturnNewTree(root);
	printBinaryTree(mTree);
	cout << "\n\n";
	cout << "\nIs Mirror : " << isMirror(root, mTree);
	
//	Node* rootMirrorInPlace = mirrorTreeAndReturnModifiedTree(root);
//	printBinaryTree(rootMirrorInPlace);
//	cout << "\nIs Mirror Equal To Mirror : " << isEqual(mTree, rootMirrorInPlace);

//	mirrorTreeInPlace(root);
//	printBinaryTree(root);
//	cout << "IsMirrorEqualToMirror : " << isEqual(mTree, root);

	cout << "\n\n";
	// Initial Symmetric Tree
	Node *symmetricTree = makeTree({
	"{1, {2, {3}, {4}}, {2, {4},{3}} }"     // symmetric
//	"{1, {2, {}, {3}}, {2, {3}, {}}}"       // symmetric
//	"{1, {2, {}, {3}}, {2, {}, {3}}}"       // not symmetric
//	"{1, {2, {4}, {5}}, {3, {6}, {7}}}"		// not symmetric
	});
	printBinaryTree(symmetricTree);
	cout << "\nTree Symmetry - ( Recursive )\n";
	cout << "\nIs Tree Symmetric : " << isTreeSymmetric(symmetricTree);
    return 0;
}

// Functions

// mirror tree there itself and return nothing
void mirrorTreeInPlace(Node* root) {
	if(!root){
		return;
	}
	
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirrorTreeInPlace(root->left);
	mirrorTreeInPlace(root->right);
}

Node* mirrorTreeAndReturnModifiedTree(Node* root) {
	if(!root){
		return nullptr;
	}

	Node* temp = mirrorTreeAndReturnModifiedTree(root->left);
	root->left = mirrorTreeAndReturnModifiedTree(root->right);
	root->right = temp;
	return root;
}

// mirror tree and return pointer to new tree
Node* mirrorTreeAndReturnNewTree(Node* root) {
	if(!root){
		return nullptr;
	}

	Node* mTree = new Node(root->data);
	mTree->left = mirrorTreeAndReturnNewTree(root->right);
	mTree->right = mirrorTreeAndReturnNewTree(root->left);
	return mTree;
}

bool isMirror(Node* r1, Node* r2) {
	if(!r1 && !r2) return true;
	return (r1 && r2
			&& r1->data==r2->data
			&& isMirror(r1->left, r2->right)
			&& isMirror(r1->right, r2->left));
}

bool isEqual(Node* r1, Node* r2) {
	if(!r1 && !r2) return true;
	return (r1 && r2
			&& r1->data==r2->data
			&& isEqual(r1->left, r2->left)
			&& isEqual(r1->right, r2->right));
}

bool isTreeSymmetric(Node* root){
	return isMirror(root->left, root->right);
}

