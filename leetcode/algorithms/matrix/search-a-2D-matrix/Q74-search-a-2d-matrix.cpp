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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }

        int r = 0;
        int c = matrix[0].size()-1;

        while(r < matrix.size() && c>=0){
            if(matrix[r][c]==target){
                return true;
            }
            if(matrix[r][c] < target){
                r++;
            }
            else{
                c--;
            }
        }
        return false;
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

