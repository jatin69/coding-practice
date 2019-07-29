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
    void rootToLeafPaths(TreeNode* root, int currSum, int& sum){
        if(!root){
            return;
        }
        currSum = currSum*2 + root->val;

        if(root->left==nullptr && root->right==nullptr){
            sum += currSum;
            return;
        }
        rootToLeafPaths(root->left, currSum, sum);
        rootToLeafPaths(root->right, currSum, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        rootToLeafPaths(root, 0, sum);
        return sum;
    }
};
