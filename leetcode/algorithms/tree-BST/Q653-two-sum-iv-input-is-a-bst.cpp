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
    bool findTarget(TreeNode* root, int target) {
        if(!root){
            return false;
        }

        // two inorders : (left, root, right) and (right, root, left)

        stack<TreeNode*> s1;
        TreeNode* root1 = root;

        stack<TreeNode*> s2;
        TreeNode* root2 = root;

        while(1){
            while(root1){
                s1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                s2.push(root2);
                root2 = root2->right;
            }

            if(s1.empty() || s2.empty()){
                break;
            }

            root1 = s1.top();
            root2 = s2.top();

            if(root1->val >= root2->val){
                break;
            }

            if(root1->val + root2->val == target){
                return true;
            }
            else if(root1->val + root2->val < target){
                s1.pop();
                root1 = root1->right;
                root2 = nullptr;
            }
            else{
                s2.pop();
                root2 = root2->left;
                root1 = nullptr;
            }
        }
        return false;
    }
};

