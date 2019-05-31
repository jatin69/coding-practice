/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    // left, root, right

    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* root = A;
    TreeNode* curr;

    while(1){
        while(root){
            s.push(root);
            root = root->left;
        }
        if(s.empty()){
            break;
        }
        curr = s.top();
        s.pop();
        res.push_back(curr->val);
        root = curr->right;
    }
    return res;
}


int main(){

	cout<<"Hello World";

    return 0;
}

