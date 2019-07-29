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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(auto ele : nums){
            if(ele==1){
                count++;
            }
            else{
                maxCount = max(count, maxCount);
                count = 0;
            }
        }
        maxCount = max(count, maxCount);
        return maxCount;
    }
};

