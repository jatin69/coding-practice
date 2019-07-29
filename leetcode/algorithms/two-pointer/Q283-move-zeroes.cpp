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
    void moveZeroes(vector<int>& nums) {
        for(int i=0, lastNonZeroPosition = 0; i<nums.size(); ++i){
            if(nums[i]!=0){
                swap(nums[lastNonZeroPosition++], nums[i]);
            }
        }
    }
};

