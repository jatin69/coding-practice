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
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;

        int maxVal = 1;
        int prev = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] > nums[i-1]){
                prev = prev+1;
                maxVal = max(maxVal, prev);
            }
            else{
                prev = 1;
            }
        }
        return maxVal;
    }
};



