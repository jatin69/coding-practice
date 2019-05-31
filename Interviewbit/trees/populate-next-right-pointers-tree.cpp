/*
 * Author : Jatin Rohilla
 * Date   : 29-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
 * geeks ref - https://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/
 */


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

TreeLinkNode* getNextRight(TreeLinkNode* root){
    TreeLinkNode* trav = root->next;
    while(trav){
        if(trav->left){
            return trav->left;
        }
        if(trav->right){
            return trav->right;
        }
        trav = trav->next;
    }

    return nullptr;
}

void Solution::connect(TreeLinkNode* root) {
    if(root==nullptr){
        return;
    }

    root->next = nullptr;
    TreeLinkNode* levelFirstNode = root;

    while(levelFirstNode){

        TreeLinkNode* trav = levelFirstNode;

        // process one level
        while(trav){
            if(trav->left){
                if(trav->right){
                    trav->left->next = trav->right;
                    trav->right->next = getNextRight(trav);
                }
                else{
                    trav->left->next = getNextRight(trav);
                }
            }
            else{
                if(trav->right){
                    trav->right->next = getNextRight(trav);
                }
                else{
                    // nothing to process
                }
            }
            trav = trav->next;
        }

        // move to first node of next level
        if(levelFirstNode->left){
            levelFirstNode = levelFirstNode->left;
        }
        else if(levelFirstNode->right){
            levelFirstNode = levelFirstNode->right;
        }
        else{
            levelFirstNode = getNextRight(levelFirstNode);
        }
    }

}


int main(){

	cout<<"Hello World";

    return 0;
}

