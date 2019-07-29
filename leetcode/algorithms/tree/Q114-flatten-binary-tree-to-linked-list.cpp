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
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }

        TreeNode* it;
        while(root){
            if(root->left && root->right){
                it = root->left;
                while(it->right){
                    it = it->right;
                }
                it->right = root->right;
            }
            if(root->left){
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }

    }
};



