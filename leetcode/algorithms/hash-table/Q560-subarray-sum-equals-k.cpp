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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;     // telling that 0 has occured ????
        int count = 0;
        int preSum = 0;
        for(int i=0; i<nums.size(); ++i){
            preSum += nums[i];
            if(m.find(preSum-k)!=m.end()){
                count += m[preSum-k];
            }
            m[preSum]++;
        }
        return count;
    }
};



