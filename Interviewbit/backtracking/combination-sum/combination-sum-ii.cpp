/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, int start, int target, vector<int>& curr, vector<vector<int>>& res){
    if(target == 0){
        res.push_back(curr);
    }
    for(int i=start; i<nums.size(); ++i){
        curr.push_back(nums[i]);
        if(target >= nums[i]){
            backtrack(nums, i+1, target - nums[i], curr, res);
        }
        curr.pop_back();
        while(i+1 < nums.size() && nums[i]==nums[i+1]){ i++; }
    }
}

vector<vector<int> > Solution::combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if(nums.size()==0){
        return res;
    }
    sort(nums.begin(), nums.end());
    vector<int> curr;
    backtrack(nums, 0, target, curr, res);
    return res;
}


