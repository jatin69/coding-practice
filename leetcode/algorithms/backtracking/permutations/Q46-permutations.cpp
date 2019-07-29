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

/****************************** 8ms *********************************/

class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start; i<nums.size(); ++i){
            swap(nums[i], nums[start]);
            backtrack(nums, start+1, res);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0){
            return res;
        }
        backtrack(nums, 0, res);
        return res;
    }
};`

/****************************** 16ms *********************************/

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int> currList, unordered_set<int> s, vector<vector<int>>& res){
        if(currList.size() == nums.size()){
            res.push_back(currList);
            return;
        }
        for(int i=0; i<nums.size(); ++i){
            if(s.find(nums[i]) != s.end()) continue;
            currList.push_back(nums[i]);
            s.insert(nums[i]);
            backtrack(nums, currList, s, res);
            currList.pop_back();
            s.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> s;
        backtrack(nums, {}, s, res);
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

