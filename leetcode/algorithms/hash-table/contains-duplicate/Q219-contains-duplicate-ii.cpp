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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); ++i){
            if(m.find(nums[i]) != m.end()){
                if(abs(m[nums[i]]-i) <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

