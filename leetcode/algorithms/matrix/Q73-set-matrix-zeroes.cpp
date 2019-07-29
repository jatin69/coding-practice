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
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return;
        }

        // approach : reusing first row and first column for space recycling

        int m = matrix.size();
        int n = matrix[0].size();

        // keep record of 0th row and 0th column

        bool shouldFirstRowBeZero = false;
        bool shouldFirstColumnBeZero = false;

        if(matrix[0][0]==0){
            shouldFirstRowBeZero = true;
            shouldFirstColumnBeZero = true;
        }

        for(int i=0;i<m;++i){
            if(matrix[i][0]==0){
                shouldFirstColumnBeZero = true;
                break;
            }
        }

        for(int j=0;j<n;++j){
            if(matrix[0][j]==0){
                shouldFirstRowBeZero = true;
                break;
            }
        }

        // keep record of matrix m-1 x n-1
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(matrix[i][j]==0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }

        // process matrix m-1 x n-1
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }

        // processing 0th row and 0th column
        if(shouldFirstRowBeZero){
            for(int j=0;j<n;++j){ matrix[0][j]=0; }
        }

        if(shouldFirstColumnBeZero){
            for(int i=0;i<m;++i){ matrix[i][0]=0; }
        }

    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

