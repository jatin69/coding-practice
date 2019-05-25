/*
 * Author : Jatin Rohilla
 * Date   : 18-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/symmetric-binary-tree/
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


int isMirror(TreeNode* A, TreeNode* B){
    if(A==nullptr){
        if(B==nullptr){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(B==nullptr){
            return 0;
        }
        else{
            if(A->val == B->val){
                return isMirror(A->left, B->right) && isMirror(A->right, B->left);
            }
            else{
                return 0;
            }
        }
    }
}


int Solution::isSymmetric(TreeNode* A) {
    if(A==nullptr){
        return 1;
    }
    return isMirror(A->left, A->right);
}

int main(){

	cout<<"Hello World";

    return 0;
}

