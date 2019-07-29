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

/********************************** 24ms *****************************/

class Solution {
public:
    void backtrack(vector<int>& nums, int start, set<vector<int>>& s){
        if(start == nums.size()){
            s.insert(nums);
            return;
        }
        for(int i=start; i<nums.size(); ++i){
            if(i>start && nums[i]==nums[i-1]) continue;
            if(i>start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            backtrack(nums, start+1, s);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        backtrack(nums, 0, s);
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};

/********************************** 28ms *****************************/

class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res){
        if(start == nums.size()){
            res.push_back(nums);
        }
        unordered_set<int> s;
        for(int i = start ; i<nums.size(); ++i){
            if(s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtrack(nums, start+1, res);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0){
            return res;
        }
        backtrack(nums, 0, res);
        return res;
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

