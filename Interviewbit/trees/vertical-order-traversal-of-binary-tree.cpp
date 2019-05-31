/*
 * Author : Jatin Rohilla
 * Date   : 29-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
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
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(A==nullptr){
        return vector<vector<int>>();
    }

    map<int, vector<int>> m;

    TreeNode* root = A;
    int level = 0 ;

    queue<pair<TreeNode*, int>> bfsQueue;
    bfsQueue.push({root, level});

    while(!bfsQueue.empty()){
        std::tie(root, level) = bfsQueue.front(); bfsQueue.pop();
        if(m.find(level)!=m.end()){
            m[level].push_back(root->val);
        }
        else{
            m[level]  = {root->val};
        }
        if(root->left){
            bfsQueue.push({root->left, level-1});
        }
        if(root->right){
            bfsQueue.push({root->right, level+1});
        }
    }

    vector<vector<int>> res;
    for(auto it : m){
        res.push_back(it.second);
    }
    return res;
}


int main(){

	cout<<"Hello World";

    return 0;
}

