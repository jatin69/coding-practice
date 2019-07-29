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
private:
    int robber(vector<int>& nums, int l, int r) {
        if(l==r){ return nums[l]; }
        int first = 0, second = 0, third = 0;
        for(int i=l; i<=r; ++i){
            third = max(nums[i]+first, second);
            first = second;
            second = third;
        }
        return third;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){ return 0; }
        if(n==1){ return nums[0]; }
        if(n==2){ return max(nums[0], nums[1]); }

        return std::max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }
};

