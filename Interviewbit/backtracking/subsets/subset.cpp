/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& A, int start, vector<int>& curr, vector<vector<int>>& res){
    res.push_back(curr);
    for(int i=start; i<A.size(); ++i){
        curr.push_back(A[i]);
        backtrack(A, i+1, curr, res);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(A, 0, curr, res);
    return res;
}


