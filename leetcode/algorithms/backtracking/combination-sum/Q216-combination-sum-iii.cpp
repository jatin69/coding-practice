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
    void backtrack(vector<int> curr, int start, int k, int target, vector<vector<int>>& res){
        if(k==0){
            if(target == 0){
                res.push_back(curr);
            }
            return;
        }
        for(int i=start; i<=9; ++i){
            if(target < i){ break;}
            curr.push_back(i);
            backtrack(curr, i+1, k-1, target-i, res);
            curr.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k==0){
            return res;
        }
        vector<int> curr;
        backtrack(curr, 1, k, n, res);
        return res;
    }
};

