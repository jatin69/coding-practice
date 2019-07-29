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
    int findDuplicate(vector<int>& nums) {
        int res = nums[0];
        for(int i=1; i<nums.size(); ++i){
            res = res^nums[i]^(i);
        }
        return res;
    }
};

