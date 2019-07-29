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
    void modifiedInOrder(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second){
        if(!root){
            return;
        }

        // note that : prev will be modified by this line
        modifiedInOrder(root->left, prev, first, second);

        if(prev && prev->val > root->val){
            if(first==nullptr){
                first = prev;
                second = root;
            }
            else{
                second = root;
                return;
            }
        }

        prev = root;
        modifiedInOrder(root->right, prev, first, second);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *first=nullptr, *second = nullptr, *prev = nullptr;
        modifiedInOrder(root, prev, first, second);
        swap(first->val, second->val);
    }
};


