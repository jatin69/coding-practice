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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head){
            return {};
        }
        if(!head->next){
            return {0};
        }
        vector<int> nums;
        for(ListNode* trav = head; trav!=nullptr; trav=trav->next){
            nums.push_back(trav->val);
        }
        stack<int> s;
        for(int i=0; i<nums.size(); ++i){
            while(!s.empty() && nums[i] > nums[s.top()]){
                nums[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            nums[s.top()] = 0;
            s.pop();
        }
        return nums;
    }
};

