/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here

class Solution {
public:
    void backtrack(vector<int>& nums, int start, int target, vector<int>& currList, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(currList);
        }
        for(int i = start; i<nums.size(); ++i){
            if(i > start && (nums[i] == nums[i-1])) continue;
            currList.push_back(nums[i]);
            if(target >= nums[i]){
                backtrack(nums, i+1, target-nums[i], currList, res);
                currList.pop_back();
            }
            else{
                currList.pop_back();
                break;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0){
            return res;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> currList;
        backtrack(candidates, 0, target, currList, res);
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

