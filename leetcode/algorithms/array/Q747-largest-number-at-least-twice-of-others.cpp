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
    int dominantIndex(vector<int>& nums) {

        if(nums.size()==1){
            return 0;
        }

        int largest = -1;
        int secondLargest = -1;
        int largestIdx = -1;
        int secondLargestIdx = -1;

        for(int i=0; i<nums.size(); ++i){
            if(nums[i] > largest){
                secondLargest = largest;
                secondLargestIdx = largestIdx;
                largest = nums[i];
                largestIdx = i;
            }
            else if(nums[i] > secondLargest){
                secondLargest = nums[i];
                secondLargestIdx = i;
            }
        }

        if(largest >= 2*secondLargest){
            return largestIdx;
        }
        else{
            return -1;
        }
    }
};

