/*
 * Author : Jatin Rohilla
 * Date   : 18-05-2019
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
 
 
////////////////////////// SOLUTION 1 ///////////////////////////////
// inorder

void inOrder(TreeNode* A, vector<int>& res){
    if(A==nullptr){
        return ;
    }
    if(A->left){
        inOrder(A->left, res);
    }
    res.push_back(A->val);
    if(A->right){
        inOrder(A->right, res);
    }
}

int Solution::isValidBST(TreeNode* A) {
    if(A==nullptr){
        return 1;
    }
    vector<int> res;
    inOrder(A, res);
    for(int i=0;i+1<res.size();++i){
        if(res[i] >= res[i+1]){
            return 0;
        }
    }
    return 1;
}

////////////////////////// SOLUTION 2 ///////////////////////////////
// optimsed inorder

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int isValidBSTCheck(TreeNode* root, TreeNode*& prev){
    if(root==nullptr){
        return 1;
    }
    if(!isValidBSTCheck(root->left, prev)){
        return 0;
    }

    if(prev!=nullptr && root->val <= prev->val){
        return 0;
    }
    prev = root;

    if(!isValidBSTCheck(root->right, prev)){
        return 0;
    }

    return 1;
}

int Solution::isValidBST(TreeNode* A) {
    TreeNode* prev = nullptr;
    return isValidBSTCheck(A, prev);
}


int main(){

	cout<<"Hello World";

    return 0;
}

