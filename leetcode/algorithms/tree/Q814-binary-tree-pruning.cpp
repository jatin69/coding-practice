/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root){
            return root;
        }

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(root->left == nullptr && root->right == nullptr){
            if(root->val == 0){
                root = nullptr;
            }
        }
        return root;
    }
};

