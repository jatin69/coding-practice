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
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowMap(9, vector<int>(9, 0));
        vector<vector<int>> columnMap(9, vector<int>(9, 0));
        vector<vector<int>> boxMap(9, vector<int>(9, 0));
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j]=='.') continue;
                if(++rowMap     [i]              [board[i][j]-'1']    > 1) return false;
                if(++columnMap  [j]              [board[i][j]-'1']    > 1) return false;
                if(++boxMap     [(i/3)*3 + (j/3)][board[i][j]-'1']    > 1) return false;
            }
        }
        return true;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

