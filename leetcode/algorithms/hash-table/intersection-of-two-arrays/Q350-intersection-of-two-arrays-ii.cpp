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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(auto& ele : nums1){
            m[ele]++;
        }

        vector<int> res;
        for(auto& ele : nums2){
            if(m[ele] > 0){
                res.push_back(ele);
                m[ele]--;
            }
        }

        return res;
    }
};

