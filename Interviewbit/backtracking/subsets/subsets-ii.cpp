	/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, int start, vector<int> currList, vector<vector<int>>& res){
    res.push_back(currList);
    for(int i=start; i<nums.size(); ++i){
        // handle duplicates
        if(i>start && nums[i]==nums[i-1]) continue;
        currList.push_back(nums[i]);
        backtrack(nums, i+1, currList, res);
        currList.pop_back();
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    std::sort(nums.begin(), nums.end());
    backtrack(nums, 0, {}, res);
    return res;
}

