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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){ return 0; }
        if(nums.size()==1){ return 1; }

        vector<int> LIS(nums.size());
        LIS[0] = 1;
        int res = 0;
        for(int i=1; i<nums.size(); ++i){
            int maxVal = 0;
            for(int j = 0; j<i; ++j){
                if(nums[i] > nums[j]){
                    maxVal = std::max(maxVal, LIS[j]);
                }
            }
            LIS[i] = maxVal + 1;
            res = max(res, LIS[i]);
        }
        return res;
    }
};

