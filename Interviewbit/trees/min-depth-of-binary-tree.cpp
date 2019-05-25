/*
 * Author : Jatin Rohilla
 * Date   : 21-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/min-depth-of-binary-tree/
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
int Solution::minDepth(TreeNode* A) {
    if(A==nullptr){
        return 0;
    }

    if(A->left){
        if(A->right){
            return 1 + min(minDepth(A->left), minDepth(A->right));
        }
        else{
            return 1+minDepth(A->left);
        }
    }
    else{
        if(A->right){
            return 1+minDepth(A->right);
        }
        else{
            return 1;
        }
    }
}


int main(){

	cout<<"Hello World";

    return 0;
}

