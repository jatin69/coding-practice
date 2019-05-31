/*
 * Author : Jatin Rohilla
 * Date   : 27-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
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

TreeNode* arrayToBST(const vector<int> &A, int l, int r){
    if(l==r)              { return new TreeNode(A[l]); }

    int mid = l + (r-l)/2;
    if(mid < l || r < mid){ return nullptr;            }

    TreeNode* root = new TreeNode(A[mid]);
    root->left = arrayToBST(A, l, mid-1);
    root->right = arrayToBST(A, mid+1, r);

    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if(A.size()==0){
        return nullptr;
    }
    return arrayToBST(A, 0, A.size()-1);
}


int main(){

	cout<<"Hello World";

    return 0;
}

