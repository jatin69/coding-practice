/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * inorder - https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
 * postorder - https://stackoverflow.com/questions/36384599/can-we-use-morris-traversal-for-postorder
 */


#include<bits/stdc++.h>
using namespace std;

// kind of preorder

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Solution::flatten(TreeNode* A) {
    if(A==nullptr){
        return A;
    }

    TreeNode* root = A;
    TreeNode* trav;

    while(root){
        if(root->left){
            trav = root->left;
            while(trav->right){
                trav = trav->right;
            }
            trav->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
    return A;
}


int main(){

	cout<<"Hello World";

    return 0;
}

