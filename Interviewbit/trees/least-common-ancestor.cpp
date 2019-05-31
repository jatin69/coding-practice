/*
 * Author : Jatin Rohilla
 * Date   : 29-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/least-common-ancestor/
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

bool find(TreeNode* root, int ele){
    if(root==nullptr){
        return false;
    }
    if(root->val==ele){
        return true;
    }
    if(find(root->left, ele) || find(root->right, ele)){
        return true;
    }
    return false;
}

TreeNode* LCA(TreeNode* root, int n1, int n2){

    if(root==nullptr){
        return nullptr;
    }

    if(root->val == n1 || root->val == n2){
        return root;
    }

    TreeNode* left = LCA(root->left, n1, n2);
    TreeNode* right = LCA(root->right, n1, n2);

    if(left){
        if(right){
            return root;
        }
        else{
            return left;
        }
    }
    else{
        if(right){
            return right;
        }
        else{
            // will never come here
            // nodes definitely exist
        }
    }
}

int Solution::lca(TreeNode* A, int B, int C) {
    if(A==nullptr){
        return -1;
    }
    if(!find(A, B) || !find(A, C)){
        return -1;
    }

    TreeNode* lcaNode = LCA(A, B, C);
    if(lcaNode==nullptr){
        return -1;
    }
    return lcaNode->val;
}

int main(){

	cout<<"Hello World";

    return 0;
}

/*********************** Editorial *****************/

class Solution {
    public:
        TreeNode *LCA(TreeNode *root, int val1, int val2) {
            if (!root) return NULL;
            if (root->val == val1 || root->val == val2) return root;
            TreeNode *L = LCA(root->left, val1, val2);
            TreeNode *R = LCA(root->right, val1, val2);
            if (L && R) return root; // If val1, val2 are on both sides
            return L ? L : R; // either one of val1, val2 is on one side OR val1, val2 is not in L&R subtrees
        }

        bool find(TreeNode *root, int val1) {
            if (!root) return false;
            if (root->val == val1) return true;
            return (find(root->left, val1) || find(root->right, val1));
        }

        int lca(TreeNode *root, int val1, int val2) {
            if (!find(root, val1) || !find(root, val2)) return -1;
            TreeNode *ans = LCA(root, val1, val2);
            if (!ans) return -1;
            return ans->val;
        }
};
