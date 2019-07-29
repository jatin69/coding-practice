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
    void getAllUniqueNodes(TreeNode* root, set<int>& s){
        if(!root){
            return;
        }
        s.insert(root->val);
        getAllUniqueNodes(root->left, s);
        getAllUniqueNodes(root->right, s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        getAllUniqueNodes(root, s);
        if(s.size()==1){
            return -1;
        }
        return *(++s.begin());
    }
};

