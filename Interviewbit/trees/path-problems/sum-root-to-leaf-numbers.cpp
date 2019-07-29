/*
 * Author : Jatin Rohilla
 * Date   : 8-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
 */


#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x, TreeNode* _left=NULL, TreeNode* _right = NULL){
     	val = x;
     	left = _left;
     	right = _right;
	 }
};

void preOrder(TreeNode* root){
	if(root){

		cout << root->val << "  ";
		preOrder(root->left);
		preOrder(root->right);

	}
}

void printBinaryTree(TreeNode *root, int COUNT = 1, int space = 0) {

  // increase distance between levels
  space += COUNT * 10;

  // Process right child first - to show it on top line
  if (root) {
    printBinaryTree(root->right, COUNT, space);
  }

  // Process current Node
  int gapLines, gapSpaces;

  // Gap lines before Node
  for (int i = 0; i < COUNT; ++i) {
    cout << "\n";
  }

  // spaces before node
  for (int i = 0; i < space - (COUNT * 10); ++i) {
    cout << " ";
  }
  // current node
  root == nullptr ? cout << "NULL" : cout << root->val;

  // Gap lines after Node
  for (int i = 0; i < COUNT; ++i) {
    cout << "\n";
  }

  // Process left child
  if (root) {
    printBinaryTree(root->left, COUNT, space);
  }
}

int rootToLeafSum(TreeNode* A, int currSum){

    if(A==nullptr){
        return 0;
    }

    currSum = (currSum*10 + A->val)%1003;

    if(A->left == nullptr && A->right == nullptr){
        return currSum;
    }

    return (rootToLeafSum(A->left, currSum) + rootToLeafSum(A->right, currSum))%1003;
}

int sumNumbers(TreeNode* A) {
    return rootToLeafSum(A, 0);
}


int main(){

	TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)) , new  TreeNode(5, NULL, new TreeNode(6)));
	cout << "Preorder traversal of the tree  :  " ; preOrder(root);
	cout<<"\n\n";
	printBinaryTree(root);
	cout<<"\n\n";

	cout << "Sum of numbers on all paths  : " << sumNumbers(root);
    return 0;
}

