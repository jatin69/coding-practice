/*
 * Author : Jatin Rohilla
 * Date   : 29-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    if(A==nullptr){
        return {{}};
    }
    vector<vector<int>> res;
    vector<int> curr;

    queue<TreeNode*> q;
    TreeNode* root = A;
    int level = 0;

    q.push(root);
    q.push(nullptr);
    level++;

    while(!q.empty()){
        root = q.front();
        q.pop();
        if(root==nullptr){
            if(level%2==0){
                reverse(curr.begin(), curr.end());
            }
            res.push_back(curr);
            curr.clear();
            if(q.empty()){
                break;
            }
            q.push(nullptr);
            level++;
        }
        else{
            curr.push_back(root->val);
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }
    }
    return res;
}


int main(){

	cout<<"Hello World";

    return 0;
}

