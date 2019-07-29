/*
 * Author : Jatin Rohilla
 * Date   : 30-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
 * ref links -
 * https://www.geeksforgeeks.org/cartesian-tree/
 * https://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/
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

int findMax(vector<int>& A, int start, int end){
    int maxIdx = start;
    for(int i=start+1 ; i<=end; ++i){
        if(A[i] > A[maxIdx]){
            maxIdx = i;
        }
    }
    return maxIdx;
}

TreeNode* buildCartesianTree(vector<int>& A, int start, int end){
    if(end < start){
        return nullptr;
    }

    int maxElementIndex = findMax(A, start, end);

    TreeNode* root = new TreeNode(A[maxElementIndex]);
    root->left = buildCartesianTree(A, start, maxElementIndex-1);
    root->right = buildCartesianTree(A, maxElementIndex+1, end);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    return buildCartesianTree(A, 0, A.size()-1);
}


int main(){

	cout<<"Hello World";

    return 0;
}

