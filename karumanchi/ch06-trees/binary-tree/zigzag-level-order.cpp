/*
 * Author : Jatin Rohilla
 * Date   : 29-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return vector<vector<int>>();
        }

        queue<TreeNode*> q;
        TreeNode* levelMarker = nullptr;
        stack<int> s;
        int level = 0;

        // first level is root node
        q.push(root);
        q.push(levelMarker);
        level++;

        TreeNode* curr;
        vector<vector<int>> allLevels;
        vector<int> currLevel;

        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr==levelMarker){
                if(level%2==0){
                    while(!s.empty()){
                        currLevel.push_back(s.top());
                        s.pop();
                    }
                }

                allLevels.push_back(currLevel);
                currLevel = vector<int>();
                if(q.empty()){
                    break;
                }
                q.push(levelMarker);
                level++;
            }
            else{
                if(level%2==0){
                    s.push(curr->val);
                }
                else{
                    currLevel.push_back(curr->val);
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return allLevels;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

/*********************** 4ms sol *************************** */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> cache;
        cache.push(root);
        int level = 1;
        while(cache.empty() == false) {
            int size = cache.size();
            vector<int> curr;
            for(int i = 0; i < size; i++) {
                TreeNode* cn = cache.front();
                curr.push_back(cn->val);
                if(cn->left != nullptr) cache.push(cn->left);
                if(cn->right != nullptr) cache.push(cn->right);
                cache.pop();
            }
            if(level % 2 == 0) reverse(curr.begin(), curr.end());
            res.push_back(curr);
            level++;
        }
        return res;
    }
};

/************************************* 0ms - 2 stacks *************************************/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>result;
        vector<int>ans;
        if(root==NULL)return result;
        stack<TreeNode*>current;
        stack<TreeNode*>next;
        bool lefttoright=true;
        current.push(root);
        while(!current.empty())
        {
            TreeNode* temp=current.top();
            current.pop();
            if(temp)
            {
                ans.push_back(temp->val);
                if(lefttoright)
                {
                    if(temp->left)
                        next.push(temp->left);
                    if(temp->right)
                        next.push(temp->right);
                }
                else
                {
                    if(temp->right)
                        next.push(temp->right);
                    if(temp->left)
                        next.push(temp->left);
                }

            }
            if(current.empty())
                {
                    lefttoright=!lefttoright;
                    result.push_back(ans);
                    ans.clear();
                    swap(current,next);
                }
        }
        return result;


    }
};
