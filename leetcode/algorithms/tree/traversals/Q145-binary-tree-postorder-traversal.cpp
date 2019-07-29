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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> res;
        stack<TreeNode*> s;

        TreeNode *prev = nullptr;
        while(1){
            while(root){
                s.push(root);
                root = root->left;
            }

            if(s.empty()){
                break;
            }

            root = s.top();
            if(root->right==prev || root->right==nullptr){
                s.pop();
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            }
            else{
                root = root->right;
            }
        }
        return res;
    }
};

