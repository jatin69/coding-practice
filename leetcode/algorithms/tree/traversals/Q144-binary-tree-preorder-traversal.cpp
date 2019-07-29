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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int> res;
        stack<TreeNode*> s;
        while(1){
            while(root){
                res.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            if(s.empty()){
                break;
            }
            root = s.top();s.pop();
            root = root->right;
        }
        return res;
    }
};
