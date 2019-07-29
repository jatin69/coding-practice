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
    TreeNode* makeBST(vector<int>& nums, int l, int r){
        if(l > r) { return nullptr;                }
        if(l == r){ return new TreeNode(nums[l]);  }
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeBST(nums, l, mid-1);
        root->right = makeBST(nums, mid+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return nullptr;
        }
        return makeBST(nums, 0, nums.size()-1);
    }
};
