/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::minDistance(string word1, string word2) {

    // initialise table
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> cache(m+1, vector<int>(n+1));

    // fill up first row and first column
    for(int i=0; i<=m; ++i){
        cache[i][0] = i;
    }
    for(int j=0; j<=n; ++j){
        cache[0][j] = j;
    }

    // all other cells
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(word1[i]==word2[j]){
                cache[i][j] = cache[i-1][j-1];
            }
            else{
                cache[i][j] = 1 + min(cache[i-1][j-1], min(cache[i-1][j], cache[i][j-1]));
            }
        }
    }
    for(auto row : cache){
        cout << "{ ";
        for(auto cell : row){
            cout << cell << ", ";
        }
        cout << "}";
    }
    return cache[m][n];
}


