/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        if(nums.size()==0){
            return;
        }
        sums.push_back(nums[0]);
        for(int i=1; i<nums.size(); ++i){
            sums.push_back(nums[i] + sums[i-1]);
        }
    }

    int sumRange(int i, int j) {
        if(i==0){
            return sums[j];
        }
        else{
            return sums[j]-sums[i-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

