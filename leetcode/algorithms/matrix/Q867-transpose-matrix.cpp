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
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int columns = A[0].size();

        vector<vector<int>> res(columns, vector<int>(rows));
        for(int i=0;i<rows;++i){
            for(int j=0; j<columns; ++j){
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};

