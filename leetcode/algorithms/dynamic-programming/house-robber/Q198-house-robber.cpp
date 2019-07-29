/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// naive dp

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        sums[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); ++i){
            sums[i] = max(nums[i]+sums[i-2], sums[i-1]);
        }
        return *max_element(sums.begin(), sums.end());
    }
};

// better

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> profit(nums.size());
        profit[0] = nums[0];
        profit[1] = max(nums[1], profit[0]);
        for(int i=2; i<nums.size(); ++i){
            profit[i] = max(nums[i]+profit[i-2], profit[i-1]);
        }
        return profit.back();
    }
};

// most efficient

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int first = 0, second = 0, third = 0;
        for(const auto& num : nums){
            third = max(num+first, second);
            first = second;
            second = third;
        }
        return third;
    }
};

