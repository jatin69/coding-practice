/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 0;

        vector<vector<int>> cache(m, vector<int>(n));
        cache[0][0] = 1;
        for(int i=1; i<m; ++i){ cache[i][0] = cache[i-1][0]; }
        for(int j=1; j<n; ++j){ cache[0][j] = cache[0][j-1]; }

        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                cache[i][j] = cache[i-1][j] + cache[i][j-1];
            }
        }

        return cache[m-1][n-1];
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

