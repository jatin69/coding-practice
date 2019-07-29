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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* makeBST(ListNode* head, ListNode* tail){
        // 0 Nodes
        if(!head){
            return nullptr;
        }
        // 1 Node
        if(head==tail){
            return new TreeNode(head->val);
        }
        // 2 Nodes
        if(head->next==tail){
            TreeNode* root = new TreeNode(head->val);
            root->left = nullptr;
            root->right = makeBST(head->next, tail);
            return root;
        }

        // 3 or More Nodes
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=tail && fast->next!=tail){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        root->left = makeBST(head, prev);
        root->right = makeBST(slow->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){ return nullptr; }
        return makeBST(head, nullptr);
    }
};

