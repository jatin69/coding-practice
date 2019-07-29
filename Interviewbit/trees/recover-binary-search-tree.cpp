/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
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

void inOrder(TreeNode* root, vector<int>& res){
    if(!root){
        return;
    }
    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
}
vector<int> Solution::recoverTree(TreeNode* root) {
    if(root==nullptr){
        return {};
    }
    vector<int> A;
    inOrder(root, A);

    bool flag = true;
    int first = -1, second = -1;

    for(int i=1; i<A.size(); ++i){
        // cout << A[i] << " ";
        if(A[i-1] > A[i]){
            if(flag){
                first = A[i-1];
                second = A[i];
                flag = false;
            }
            else{
                second = A[i];
            }
        }
    }
    return {second, first};
}


