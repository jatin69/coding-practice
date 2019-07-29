/*
 * Author : Jatin Rohilla
 * Date   : 10-06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        backtrack(nums, 0, {}, res);
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

