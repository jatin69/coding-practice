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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s1;
        for(auto& ele : nums1){
            s1.insert(ele);
        }
        unordered_set<int> s2;
        for(auto& ele : nums2){
            s2.insert(ele);
        }
        for(auto it : s1){
            if(s2.count(it) > 0){
                res.push_back(it);
            }
        }
        return res;
    }
};
