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
    enum state{VALID, INVALID};
    int robber(TreeNode* root, state nodeState, map<pair<TreeNode*, state>, int>& cache){
        if(root==nullptr){ return 0; }
        if(cache.find({root, nodeState})!=cache.end()){
            return cache[{root, nodeState}];
        }

        int currProfit = 0;
        if(nodeState == VALID){
            currProfit = root->val + robber(root->left, INVALID, cache) + robber(root->right, INVALID, cache);
        }
        currProfit = std::max(currProfit, robber(root->left, VALID, cache) + robber(root->right, VALID, cache));
        cache[{root, nodeState}] = currProfit;
        return currProfit;
    }

    int rob(TreeNode* root) {
        map< pair<TreeNode*, state>, int> cache;
        return robber(root, VALID, cache);
    }
};

