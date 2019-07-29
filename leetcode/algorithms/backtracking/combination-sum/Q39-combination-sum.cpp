/*
 * Author : Jatin Rohilla
 * Date   : 06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

/***************************** 8ms *************************/

class Solution {
public:
    void backtrack(vector<int>& nums, int start, int target, vector<int>& currList, vector<vector<int>>& res){
        if(target==0){
            res.push_back(currList);
            return;
        }
        for(int i=start; i<nums.size(); ++i){
            currList.push_back(nums[i]);
            // pruning useless calls
            if(target >= nums[i]){
                backtrack(nums, i, target-nums[i], currList, res);
            }
            currList.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0){
            return res;
        }
        vector<int> currList;
        backtrack(candidates, 0, target, currList, res);
        return res;
    }
};

// another variant

class Solution {
public:
    void backtrack(vector<int>& nums, int start, int target, vector<int>& currList, vector<vector<int>>& res){
        if(target==0){
            res.push_back(currList);
            return;
        }
        for(int i=start; i<nums.size(); ++i){
            currList.push_back(nums[i]);
            if(target >= nums[i]){
                backtrack(nums, i, target-nums[i], currList, res);
                currList.pop_back();
            }
            else{
                currList.pop_back();
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0){
            return res;
        }
        vector<int> currList;
        // sorted to be able to do more pruning
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, currList, res);
        return res;
    }
};

/************************************* 12 ms *********************************/

class Solution {
public:
    void backtrack(vector<int>& nums, int start, int target, vector<int>& currList, vector<vector<int>>& res){
        if(target < 0){
            return;
        }
        if(target==0){
            res.push_back(currList);
            return;
        }
        for(int i=start; i<nums.size(); ++i){
            currList.push_back(nums[i]);
            backtrack(nums, i, target-nums[i], currList, res);
            currList.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0){
            return res;
        }
        vector<int> currList;
        backtrack(candidates, 0, target, currList, res);
        return res;
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

