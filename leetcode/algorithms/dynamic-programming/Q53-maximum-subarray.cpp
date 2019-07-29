/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int prev = nums[0];
        int maxSum = prev;
        for(int i=1; i<nums.size(); ++i){
            prev = std::max(nums[i], nums[i]+prev);
            if(prev > maxSum){ maxSum = prev; }
        }
        return maxSum;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

