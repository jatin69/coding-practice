/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > Solution::solve(int n) {
    vector<vector<int>> res(n);
    for(int i=0; i<n; ++i){
        res[i] = vector<int>(i+1);
    }
    for(int i=0; i<n; ++i){
        res[i][0] = 1;
        res[i][i] = 1;
        for(int j=1; j<i; ++j){
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }
    return res;
}

