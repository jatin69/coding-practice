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
    void preOrderSum(TreeNode*& root, int& L, int& R, int& sum){
        if(!root){
            return;
        }
        int val = root->val;
        if(val > R){
            preOrderSum(root->left, L, R, sum);
        }
        else if(val < L){
            preOrderSum(root->right, L, R, sum);
        }
        else{
            sum += val;
            preOrderSum(root->left, L, R, sum);
            preOrderSum(root->right, L, R, sum);
        }

    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        preOrderSum(root, L, R, sum);
        return sum;
    }
};
