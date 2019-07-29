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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        int remainingSum = sum - root->val;
        if(root->left==nullptr && root->right==nullptr && remainingSum==0){
            return true;
        }
        return (hasPathSum(root->left, remainingSum)) || (hasPathSum(root->right, remainingSum));
    }
};
