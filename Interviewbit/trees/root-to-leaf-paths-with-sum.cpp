/*
 * Author : Jatin Rohilla
 * Date   : 29-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
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

void pathSumHelper(TreeNode* root, int sum, vector<int> path, vector<vector<int>>& allPaths){

    if(root==nullptr){
        return;
    }

    path.push_back(root->val);
    int remainingSum = sum - (root->val);
    if(remainingSum==0 && root->left==nullptr && root->right==nullptr){
        allPaths.push_back(path);
    }
    else{
        pathSumHelper(root->left, remainingSum, path, allPaths);
        pathSumHelper(root->right, remainingSum, path, allPaths);
    }
    return;
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> allPaths;
    vector<int> path;
    pathSumHelper(A, B, path, allPaths);
    return allPaths;
}


int main(){

	cout<<"Hello World";

    return 0;
}

