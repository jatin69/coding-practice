/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A.size()==0 || A[0].size()==0) return 0;
    if(A[0][0]==1) return 0;

    int m = A.size();
    int n = A[0].size();
    vector<int> cache(n, 0);
    cache[0] = 1;

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(A[i][j] == 1){ cache[j] = 0; }
            else{
                if(j-1 >= 0){
                    cache[j] += cache[j-1];
                }
            }
        }
    }
    return cache[n-1];
}


