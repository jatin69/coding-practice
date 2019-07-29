/*
 * Author : Jatin Rohilla
 * Date   : May-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/preorder-traversal/
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
vector<int> Solution::preorderTraversal(TreeNode* A) {
	// root, left, right
	
    stack<TreeNode*> s;
    s.push(A);
    vector<int> res;
    TreeNode* curr;
    while(!s.empty()){
        curr = s.top();
        s.pop();
        res.push_back(curr->val);
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
    return res;
}


int main(){

	cout<<"Hello World";

    return 0;
}

