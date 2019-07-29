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
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }

        vector<int> sums;
        sums.push_back(nums[0]);

        for(int i=1;i<nums.size();++i){
            sums.push_back(sums[i-1] + nums[i]);
        }

        int curr = 0;
        for(int i=0;i<nums.size();++i){
            if(curr == sums.back()-sums[i]){
                return i;
            }
            curr = sums[i];
        }
        return -1;
    }
};

