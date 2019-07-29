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

class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int> currList, vector<vector<int>>& res){
        res.push_back(currList);
        for(int i=start; i<nums.size(); ++i){
            currList.push_back(nums[i]);
            backtrack(nums, i+1, currList, res);
            currList.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, {}, res);
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

