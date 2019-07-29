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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());

        ListNode* trav = head;
        int count = 0;
        int currCount = 0;

        while(trav){
            if(s.find(trav->val)!=s.end()){
                currCount++;
            }
            else if(currCount){
                count++;
                currCount = 0;
            }
            trav = trav->next;
        }
        if(currCount){
            count++;
            currCount = 0;
        }
        return count;
    }
};

