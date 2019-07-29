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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1){
            if(t2){
                TreeNode* root = new TreeNode(t1->val + t2->val);
                root->left = mergeTrees(t1->left, t2->left);
                root->right = mergeTrees(t1->right, t2->right);
                return root;
            }
            else{
                TreeNode* root = new TreeNode(t1->val);
                root->left = mergeTrees(t1->left, nullptr);
                root->right = mergeTrees(t1->right, nullptr);
                return root;
            }
        }
        else{
            if(t2){
                TreeNode* root = new TreeNode(t2->val);
                root->left = mergeTrees(nullptr, t2->left);
                root->right = mergeTrees(nullptr, t2->right);
                return root;
            }
            else{
                return nullptr;
            }
        }
    }
};

