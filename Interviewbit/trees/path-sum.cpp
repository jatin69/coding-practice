/*
 * Author : Jatin Rohilla
 * Date   : 29-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/path-sum/
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

int hasPathSumHelper(TreeNode* root, int sum){

    if(root==nullptr){
        return 0;
    }

    int remainingSum = sum - (root->val);
    if(remainingSum==0 && root->left==nullptr && root->right == nullptr){
        return 1;
    }
    return (hasPathSumHelper(root->left, remainingSum) || hasPathSumHelper(root->right, remainingSum));
}

int Solution::hasPathSum(TreeNode* A, int B) {
    return hasPathSumHelper(A, B);
}


int main(){

	cout<<"Hello World";

    return 0;
}

