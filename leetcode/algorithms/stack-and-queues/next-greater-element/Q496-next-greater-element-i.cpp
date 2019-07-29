/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for(int i=0; i<nums2.size(); ++i){
            while(!s.empty() && nums2[i] > s.top() ){
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        vector<int> res(nums1.size());
        for(int i=0; i<nums1.size(); ++i){
            if(m.count(nums1[i]) > 0){
                res[i] = m[nums1[i]];
            }
            else{
                res[i] = -1;
            }
        }
        return res;
    }
};


