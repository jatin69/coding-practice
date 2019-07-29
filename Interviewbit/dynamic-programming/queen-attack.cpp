/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {
  {-1,-1}, {-1, 0}, {-1,1},
  {0,-1},           {0, 1},
  {1,-1},   {1, 0}, {1, 1}
};


int dp(vector<string> & A, int i, int j, int k, vector<vector<vector<int>>>& cache){
    int ni = i + directions[k][0];
    int nj = j + directions[k][1];

    if(ni < 0 || nj < 0 || ni >= A.size() || nj >= A[0].size()){
        return 0;
    }

    if(cache[i][j][k] != -1){
        return cache[i][j][k];
    }

    int sum = 0;
    if(A[ni][nj]=='1'){
        cache[i][j][k]++;
    }
    else{
        cache[i][j][k] += dp(A, ni, nj, k, cache);
    }

    return cache[i][j][k];
}


vector<vector<int> > Solution::queenAttack(vector<string> &A) {

    int m = A.size();
    int n = A[0].size();

    vector<vector<vector<int>>> cache(m, vector<vector<int>>(n, vector<int>(8, -1)));
    vector<vector<int>> res(m, vector<int>(n, 0));

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<directions.size(); ++k){
                res[i][j] += dp(A, i, j, k, cache);
            }
        }
    }
    return res;
}


