/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& A, int start, vector<vector<int>>& res){
    res.push_back(A);
    for(int i=start; i<A.size(); ++i){
        swap(A[start], A[i]);
        backtrack(A, start+1, res);
        swap(A[start], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> res;
    backtrack(A, 0, res);
    return res;
}


