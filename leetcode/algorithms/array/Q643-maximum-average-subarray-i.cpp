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
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = std::accumulate(nums.begin(), nums.begin()+k, 0);
        double maxAvg = sum / (double)k;

        for(int i=0; i+k < nums.size(); ++i){
            sum += (-nums[i] + nums[i+k]);
            maxAvg = max(maxAvg, sum/(double)k );
        }

        return maxAvg;
    }
};

