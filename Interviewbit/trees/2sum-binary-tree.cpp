/*
 * Author : Jatin Rohilla
 * Date   : 01-06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/2sum-binary-tree/
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
int Solution::t2Sum(TreeNode* A, int B) {

    // edge case
    if(A==nullptr){
        return 0;
    }

    // reducing search space
    while(A->val > B){
        A = A->left;
        if(A==nullptr){
            return 0;
        }
    }

    // inorder traversal
    // 2-way -> (left, root, right) and (right, root, left)

    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    TreeNode* s1root = A;
    TreeNode* s2root = A;

    while(1){

        // inorder
        while(s1root){
            s1.push(s1root);
            s1root = s1root->left;
        }

        // opposite of inorder
        while(s2root){
            s2.push(s2root);
            s2root = s2root->right;
        }

        if(s1.empty() || s2.empty()){
            break;
        }

        TreeNode* n1 = s1.top();
        TreeNode* n2 = s2.top();

        if(n2->val <= n1->val){
            break;
        }

        if(n1->val + n2->val == B){
            return 1;
        }
        if(n1->val + n2->val < B){
            s1.pop();
            s1root = n1->right;
        }
        else{
            s2.pop();
            s2root = n2->left;
        }
    }
    return 0;
}

int main(){

	cout<<"Hello World";

    return 0;
}

