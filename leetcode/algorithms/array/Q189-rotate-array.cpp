/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// naive - TLE

class Solution {
public:
    void rotateOnce(vector<int>& nums){
        int n = nums.size();
        int temp = nums[n-1];

        for(int i = n-1; i>0; --i){
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        while(k--){
            rotateOnce(nums);
        }
    }
};


// reversal method

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int partition = nums.size() - k;
        reverse(nums.begin(), nums.begin() + partition);
        reverse(nums.begin() + partition, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


// a lot of other solutions possible
// https://leetcode.com/articles/rotate-array/

