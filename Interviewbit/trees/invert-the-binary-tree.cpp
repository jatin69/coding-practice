/*
 * Author : Jatin Rohilla
 * Date   : 30-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/invert-the-binary-tree/
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
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==nullptr){
        return nullptr;
    }

    TreeNode* temp = invertTree(A->left);
    A->left = invertTree(A->right);
    A->right = temp;
    return A;
}


int main(){

	cout<<"Hello World";

    return 0;
}

