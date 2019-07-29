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
    long long int inOrder(TreeNode* root, int& k){
        if(!root){
            return LLONG_MIN;
        }

        // visit left side
        long long int res = inOrder(root->left, k);
        if(res != LLONG_MIN){
            return res;
        }

        // visit root
        k--;
        if(k==0){ return root->val; }

        // visit right side
        return inOrder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return inOrder(root, k);
    }
};

