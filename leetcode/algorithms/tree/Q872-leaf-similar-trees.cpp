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
    void getLeaves(TreeNode* root, string& leaves){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            leaves += to_string(root->val) + "#";
        }
        else{
            getLeaves(root->left, leaves);
            getLeaves(root->right, leaves);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leaves1;
        getLeaves(root1, leaves1);

        string leaves2;
        getLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }
};

