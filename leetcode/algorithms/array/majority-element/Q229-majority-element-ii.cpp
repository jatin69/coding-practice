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
    vector<int> majorityElement(vector<int>& nums) {

        // implementing majority element problem for n/k elements
        int k = 3;

        // pair of element and count
        vector<pair<int, int>> candidates(k-1);

        /* First step : process array
           priority order -
           1. if a match found, do count++
           2. if space empty ( someone's count 0) allocate space and count
           3. else decrement everyone's count
        */
        for(auto& ele : nums){
            bool processed = false;

            // step 1
            for(auto& candidate : candidates){
                if(candidate.second > 0){
                    if(candidate.first == ele){
                        candidate.second++;
                        processed = true;
                        break;
                    }
                }
            }

            // step 2
            if(!processed){
                for(auto& candidate : candidates){
                    if(candidate.second == 0){
                        candidate.first = ele;
                        candidate.second = 1;
                        processed = true;
                        break;
                    }
                }
            }

            // step 3
            if(!processed){
                for(auto& candidate : candidates){
                    candidate.second--;
                }
            }
        }

        /* Second step : verification
        */
        vector<int> res;
        for(auto& candidate : candidates){

            // if candidate is initialised
            if(candidate.second > 0){

                // count its occurence in array
                int count = 0;
                for(auto& ele : nums){
                    if(ele == candidate.first){
                        count++;
                    }
                }

                if(count > (nums.size()/k)){
                    res.push_back(candidate.first);
                }
            }
        }
        return res;
    }
};

