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
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0){
            return {};
        }
        vector<vector<int>> A(numRows);
        for(int i=0; i<numRows; ++i){
            A[i] = vector<int>(i+1);
        }

        for(int i=0; i<numRows; ++i){
            A[i][0] = 1;
            A[i][i] = 1;
            for(int j=1; j<i; ++j){
                A[i][j] = A[i-1][j-1] + A[i-1][j];
            }
        }
        return A;
    }
};
