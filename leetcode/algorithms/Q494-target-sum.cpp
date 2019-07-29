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
    int getSum(vector<int>& nums, int i, double target){
        if(i==nums.size() && target == 0){
            return 1;
        }
        if(i < nums.size()){
            return (getSum(nums, i+1, target - nums[i]) + getSum(nums, i+1, target + nums[i]));
        }
        return 0;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()==0){
            return 0;
        }
        return getSum(nums, 0, S);
    }
};

