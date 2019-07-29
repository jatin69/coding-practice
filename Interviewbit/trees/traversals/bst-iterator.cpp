/*
 * Author : Jatin Rohilla
 * Date   : 01-06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/bst-iterator/
 */


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode*> s;
TreeNode* root;

BSTIterator::BSTIterator(TreeNode *_root) {
    root = _root;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !s.empty() || root;
}

/** @return the next smallest number */
int BSTIterator::next() {
    while(root){
        s.push(root);
        root = root->left;
    }

    TreeNode* curr = s.top();
    s.pop();

    root = curr->right;
    return curr->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


int main(){

	cout<<"Hello World";

    return 0;
}

