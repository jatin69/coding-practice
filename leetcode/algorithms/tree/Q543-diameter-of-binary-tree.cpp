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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* root, int& diameter) {

        // base cases
        if (root == nullptr) { return 0; }

        // get left and right height
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        // case 1 : if root is part of diameter
        // total diameter will be => left height + right height
        // +1 is not used because output counts edges at path not vertices
        diameter = max(diameter, lh + rh);

        // this node's contribution to its parent
        // it's a height function, so its returning height
        return 1 + max(lh, rh);
    }
};

