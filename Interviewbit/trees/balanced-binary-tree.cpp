/*
 * Author : Jatin Rohilla
 * Date   : 29-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/balanced-binary-tree/
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

int isBalancedTree(TreeNode* root){
    if(root == nullptr){
        return 1;
    }

    int h1 = isBalancedTree(root->left);
    if(h1==0){
        return 0;
    }
    int h2 = isBalancedTree(root->right);
    if(h2==0){
        return 0;
    }

    if(abs(h1-h2) > 1){
        return 0;
    }
    return 1+max(h1, h2);
}

int Solution::isBalanced(TreeNode* A) {
    int status = isBalancedTree(A);
    if(status == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){

	cout<<"Hello World";

    return 0;
}

