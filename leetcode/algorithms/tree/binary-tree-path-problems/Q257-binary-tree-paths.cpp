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
    void findPaths(TreeNode* root, string currPath, vector<string>& paths){
        if(!root){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            currPath += to_string(root->val);
            paths.push_back(currPath);
            return;
        }

        currPath += to_string(root->val) + "->";
        findPaths(root->left, currPath, paths);
        findPaths(root->right, currPath, paths);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string currPath;
        findPaths(root, currPath, paths);
        return paths;
    }
};

