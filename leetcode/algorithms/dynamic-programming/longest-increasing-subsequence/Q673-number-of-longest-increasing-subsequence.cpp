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
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;

        vector<int> LIS(nums.size(), 1);
        vector<int> countLIS(nums.size(), 1);

        for(int i=1; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j]){
                    if(LIS[i] < LIS[j]+1){
                        LIS[i] = LIS[j] + 1;
                        countLIS[i] = countLIS[j];
                    }
                    else if(LIS[i]==LIS[j]+1){
                        countLIS[i] += countLIS[j];
                    }
                }
            }
        }

        int longestLIS = *max_element(begin(LIS), end(LIS));
        int res = 0;
        for(int i=0; i<LIS.size(); ++i){
            if(LIS[i]==longestLIS){
                res += countLIS[i];
            }
        }
        return res;
    }
};


