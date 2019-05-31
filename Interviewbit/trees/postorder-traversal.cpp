/*
 * Author : Jatin Rohilla
 * Date   : 28-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/postorder-traversal/
 */


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    // left, right, root

    vector<int> res;
    stack<TreeNode*> s;

    TreeNode* prev = nullptr;
    TreeNode* root = A;
    TreeNode* curr;

    while(1){

        while(root){
            s.push(root);
            prev = root;
            root = root->left;
        }
        if(s.empty()){
            break;
        }
        curr = s.top();

        // is right side already done
        if(curr->right == nullptr || curr->right == prev){

            res.push_back(curr->val);
            prev = curr;
            s.pop();

            // left side is already done
            root = nullptr;
        }
        else{
            // gotta do right side
            root = curr->right;
        }
    }
    return res;
}


int main(){

	cout<<"Hello World";

    return 0;
}

