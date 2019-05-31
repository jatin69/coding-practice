/*
 * Author : Jatin Rohilla
 * Date   : 30-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
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

TreeNode* countingInorder(TreeNode* root, int& k){
    if(root==nullptr){
        return nullptr;
    }

    TreeNode* left = countingInorder(root->left, k);
    if(left){
        return left;
    }

    k--;
    if(k==0){
        return root;
    }

    return countingInorder(root->right, k);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int count = 0;
    TreeNode* kthNode = countingInorder(A, B);
    if(kthNode == nullptr){
        return -1;
    }
    else{
        return kthNode->val;
    }
}


int main(){

	cout<<"Hello World";

    return 0;
}

