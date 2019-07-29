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
    vector<int> singleNumber(vector<int>& nums) {

        // get xor : (a ^ b) effectively
        int xorVal = 0;
        for(auto& ele : nums){ xorVal ^= ele; }

        // extract rightmost bit
        int lastBitMask = xorVal & ~(xorVal - 1);

        // divide in two sets
        int x = 0, y = 0;
        for(auto& ele : nums){
            if(ele & lastBitMask){
                x ^= ele;
            }
            else{
                y ^= ele;
            }
        }
        return {x, y};
    }
};

