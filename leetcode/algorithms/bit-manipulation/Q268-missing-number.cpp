/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// naive

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        typedef unsigned long long int ulli;
        ulli n = nums.size();
        ulli expectedSum = (n%2==0 ? (n/2)*(n+1) : (n)*((n+1)/2));
        ulli actualSum = std::accumulate(nums.begin(), nums.end(), 0);
        return (expectedSum - actualSum);
    }
};


// better

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i) {
            ret ^= i;
            ret ^= nums[i];
        }
        return ret^=nums.size();
    }
};
