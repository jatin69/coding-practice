/*
 * Author : Jatin Rohilla
 * Date   : 8-5-2019
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
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==nullptr && B==nullptr){
        return 1;
    }

    if((A && !B) || (!A && B)){
        return 0;
    }

    return (A->val == B->val) && isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}


int main(){

	cout<<"Hello World";

    return 0;
}

