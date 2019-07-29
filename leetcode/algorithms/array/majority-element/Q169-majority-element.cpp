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
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
                if(count==0){
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        return candidate;
    }
};

