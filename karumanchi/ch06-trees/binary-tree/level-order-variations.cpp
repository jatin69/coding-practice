/*
 * Author : Jatin Rohilla
 * Date   : 02-01-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */

#include<bits/stdc++.h>
using namespace std;

#include "tree.h"

void levelOrderTraversal(Node*);
void levelOrderReverse(Node*);

void spiralBFS(Node*);

int countLevelRecursive(Node*);
int countLevelsIterative(Node*);

void printLevel_Recursive(Node*, int);
void printLevel_Iterative(Node*, int);
void printAllLevelsSeparately(Node*);
int findLevelWithMaxiumumSum(Node*);

void printVerticalLevelsOfTree(Node*);
int countVerticalLevels(Node*);
void printVerticalSumofAllLevels(Node*);

int main(){

	Node *root = makeTree({
	"{1, {2, {4}, {5}}, {3, {6}, {7}}}"
//	"{1, {2, {4, {}, {9, {16}, {} } }, {5}}, {3, {6, {12}, {}}, {7, {}, {15, {}, {17} } }}}"
	});
	printBinaryTree(root);
	cout << "\n\nLevel Order Variations - ";
	cout << "\n\nLevel Order traversal    : " ; levelOrderTraversal(root);
	cout << "\nLevel Order (Reverse)    : " ; levelOrderReverse(root);
	cout << "\nSpiral Level order (BFS) : " ; spiralBFS(root);
	
	cout << "\n\nCount Levels (Recursive) : " << countLevelRecursive(root);
	cout << "\nCount Levels (Iterative) : " << countLevelsIterative(root);

	int level;
	level = 3;
	cout << "\n\nPrinting Level "<< level << "    (Recursive)  : " ; printLevel_Recursive(root, level);
	cout << "\nPrinting Level "<< level << "    (Iterative)  : " ; printLevel_Iterative(root, level);
	cout << "\nPrinting all Levels (Iterative)  : " ; printAllLevelsSeparately(root);
	cout << "\n\nLevel With Max Sum  (Iterative)  : " << findLevelWithMaxiumumSum(root);
    return 0;
}

// normal level order traversal - top to bottom
void levelOrderTraversal(Node* root){
	if(!root) return;
	queue<Node*> Q;
	Q.push(root);
	Node* it;
	while(!Q.empty()){
		it = Q.front();
		Q.pop();
		visit(it);
		if(it->left){
			Q.push(it->left);
		}
		if(it->right){
			Q.push(it->right);
		}
	}
	return;
}

// reversed level order traversal - bottom to top
void levelOrderReverse(Node* root){
	if(!root) return;
	stack<Node*> S;
	queue<Node*> Q;
	Q.push(root);
	Node* it;
	while(!Q.empty()){
		it = Q.front();
		Q.pop();
		S.push(it);
		if(it->right){
			Q.push(it->right);
		}
		if(it->left){
			Q.push(it->left);
		}
	}
	while(!S.empty()){
		it = S.top();
		S.pop();
		visit(it);
	}
	return;
}

// same as height
int countLevelRecursive(Node* root){
	if(!root) return 0;
	return 1+max(countLevelRecursive(root->left), countLevelRecursive(root->right));
}

// counting number of levels ( same as height / depth )
int countLevelsIterative(Node* root){
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

// switching direction of BFS on every level
// my version - uses the standard bfsQueue + one stack
void spiralBFS(Node* root){
	if(!root) return;
	
	queue<Node*> Q;
	stack<Node*> printStack;
	Q.push(root);
	Q.push(nullptr);
	Node* it;
	int level = 1;
	
	while(!Q.empty()){
		it = Q.front();
		Q.pop();
		if(it==nullptr){
			while(!printStack.empty()){
				it = printStack.top();
				printStack.pop();
				visit(it);
			}
			++level;
			if(!Q.empty()){
				Q.push(nullptr);
			}
		}
		else{
			if(level%2==1){
				printStack.push(it);
			}
			else{
				visit(it);
			}
			if(it->left){
				Q.push(it->left);
			}
			if(it->right){
				Q.push(it->right);
			}
		}
	}
	return;
}

// display level 'n' - recursive
void printLevel_Recursive(Node* root, int level){
	if(!root) return;
	if(level==1){
		visit(root);
		return;
	}
	printLevel_Recursive(root->left, level-1);
	printLevel_Recursive(root->right, level-1);
}

// display level 'n' - Iterative
void printLevel_Iterative(Node* root, int level){
	if(!root) return;

	queue<Node*> Q;
	Q.push(root);
	int levelCount = 1 ;
	Node* nullNode = nullptr;
	Q.push(nullNode);
	Node* it;
	
	while(!Q.empty()){
		it = Q.front();
		Q.pop();
		if(it==nullptr){
			++levelCount;
			if(!Q.empty()){
				Q.push(nullNode);
			}
		}
		else{
			if(levelCount == level){
				visit(it);
			}
			if(it->left)    Q.push(it->left);
			if(it->right)   Q.push(it->right);
		}
	}
	return;
}

// display all levels with level number
void printAllLevelsSeparately(Node* root){
	if(!root) return;

	queue<Node*> Q;
	Q.push(root);
	int level = 1 ;
	Node* nullNode = nullptr;
	Q.push(nullNode);
	Node* it;
	int sum{0};

	cout << "\n\t\t\t Level " << level << " : ";
	

	while(!Q.empty()){
		it = Q.front();
		Q.pop();
		if(it==nullptr){
			cout << "\t\t sum => " << sum;
			sum = 0;
			++level;
			if(!Q.empty()){
				Q.push(nullNode);
			}
			else{
				break;
			}
			cout << "\n\t\t\t Level " << level << " : ";
		}
		else{
			visit(it);
			sum += it->data;
			if(it->left)    Q.push(it->left);
			if(it->right)   Q.push(it->right);
		}
	}
	return;
}

int findLevelWithMaxiumumSum(Node* root){
	if(!root) return 0;
	
	queue<Node*> Q;
	Q.push(root);
	Q.push(nullptr);
	int level = 1;
	Node* it;
	
	int maxSum{0}, currSum{0}, maxSumLevel{0};
	
	while(!Q.empty()){
		it = Q.front();
		Q.pop();
		if(it==nullptr){
			if(currSum > maxSum){
				maxSum = currSum;
				maxSumLevel = level;
			}
			currSum = 0;
			++level;
			if(!Q.empty()){
				Q.push(nullptr);
			}
		}
		else{
			currSum += it->data;
			if(it->left)    Q.push(it->left);
			if(it->right)   Q.push(it->right);
		}
	}
	
	return maxSumLevel;
}


