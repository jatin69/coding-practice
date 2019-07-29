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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if(n==0){ return 0; }
        if(n==1){ return nums[0]; }

        int maxPosTillNow = nums[0];
        int minNegTillNow = nums[0];
        int currPos, currNeg, maxProductTillNow = nums[0];

        for(int i=1; i<n; ++i){
            currPos = nums[i]*maxPosTillNow;
            currNeg = nums[i]*minNegTillNow;
            maxPosTillNow = max(nums[i], max(currPos, currNeg));
            minNegTillNow = min(nums[i], min(currPos, currNeg));
            maxProductTillNow = max(maxProductTillNow, maxPosTillNow);
        }

        return maxProductTillNow;
    }
};

