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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }

        int rows = matrix.size();
        int columns = matrix[0].size();

        int i = 0;
        int j = columns-1;

        while(i < rows && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            if(matrix[i][j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};

