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
    bool validateRange(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){

        // base case
        if(!root) return true;

        // root should be within range
        if(minNode && root->val <= minNode->val){ return false; }
        if(maxNode && root->val >= maxNode->val){ return false; }

        // left and right subtree must also validate
        if(!validateRange(root->left, minNode, root)) { return false; }
        if(!validateRange(root->right, root, maxNode)){ return false; }

        // if everything good, it is a valid BST
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return validateRange(root, nullptr, nullptr);
    }
};


