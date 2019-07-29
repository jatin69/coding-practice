/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

void backtrack(int n, int start, int k, vector<int> curr, vector<vector<int>>& res){
    if(curr.size()==k){
        res.push_back(curr);
        return;
    }
    for(int i=start; i<=n; ++i){
        curr.push_back(i);
        backtrack(n, i+1, k, curr, res);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(n, 1, k, curr, res);
    return res;
}

