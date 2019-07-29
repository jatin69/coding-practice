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
    string preOrderFill(TreeNode* root, unordered_map<string, TreeNode*>& preOrderMap){
        if(!root){
            return "";
        }
        string preOrderTraversal;
        preOrderTraversal += to_string(root->val);
        preOrderTraversal += "#" + preOrderFill(root->left, preOrderMap);
        preOrderTraversal += "#" + preOrderFill(root->right, preOrderMap);

        if(preOrderMap.count(preOrderTraversal) == 0){
            // if first time insertion, this entry is useless
            preOrderMap[preOrderTraversal] = nullptr;
        }
        else{
            // second time, yes, root needs to be out
            preOrderMap[preOrderTraversal] = root;
        }
        return preOrderTraversal;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, TreeNode*> preOrderMap;
        preOrderFill(root, preOrderMap);
        vector<TreeNode*> res;
        for(auto it : preOrderMap){
            if(it.second!=nullptr){
                res.push_back(it.second);
            }
        }
        return res;
    }
};


