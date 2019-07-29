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
    void nextPermutation(vector<int>& nums) {

        int i = nums.size()-2;
        while(i>=0 && nums[i+1] <= nums[i]){    i--;    }

        if(i>=0){
            int j = nums.size() - 1;
            while(j>=0 && nums[j] <= nums[i]) { j--;    }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

