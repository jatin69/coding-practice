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
    int singleNumber(vector<int>& nums) {
        int n = 8*sizeof(int);
        int result = 0;
        for(int i=0; i<n; ++i){
            int sum = 0;
            int mask = (1 << i);
            for(int ele : nums){
                if(ele & mask){
                    sum++;
                }
            }
            if(sum%3 != 0){
                result |= mask;
            }
        }
        return result;
    }
};

