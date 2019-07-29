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
    bool containsDuplicate(vector<int>& nums) {
        // using sort

        // using set
        unordered_set<int> hashSet;
        for(auto& ele : nums){
            if(hashSet.count(ele) > 0){
                return true;
            }
            hashSet.insert(ele);
        }
        return false;
    }
};


