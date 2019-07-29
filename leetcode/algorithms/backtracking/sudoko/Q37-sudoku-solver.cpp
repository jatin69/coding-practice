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
private:
    void initialConfiguration(vector<vector<char>>& board){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j]!='.'){
                    placeNumber(board, i, j, board[i][j]);
                }
            }
        }
    }

    void placeNumber(vector<vector<char>>& board, int r, int c, char d){
        board[r][c] = d;
        rowTracker[r][d-'1'] = true;
        colTracker[c][d-'1'] = true;
        boxTracker[((r/3)*3)+(c/3)][d-'1'] = true;
    }
    void removeNumber(vector<vector<char>>& board, int r, int c, char d){
        board[r][c] = '.';
        rowTracker[r][d-'1'] = false;
        colTracker[c][d-'1'] = false;
        boxTracker[((r/3)*3)+(c/3)][d-'1'] = false;
    }
    bool isSafe(vector<vector<char>>& board, int r, int c, char d){
        return !(   rowTracker[r][d-'1']
                 || colTracker[c][d-'1']
                 || boxTracker[((r/3)*3)+(c/3)][d-'1']);
    }
public:
    bool backtrack(vector<vector<char>>& board, int i, int j){
        if(i==9){
            return true;
        }
        if(j==9){
            return backtrack(board, i+1, 0);
        }
        if(board[i][j]!='.'){
            return backtrack(board, i, j+1);
        }
        for(int d='1'; d<='9'; ++d){
            if(isSafe(board, i, j, d)){
                placeNumber(board, i, j, d);
                if(backtrack(board, i, j+1)==true){
                    return true;
                }
                removeNumber(board, i, j, d);
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        rowTracker = vector<vector<bool>>(9, vector<bool>(9, false));
        colTracker = vector<vector<bool>>(9, vector<bool>(9, false));
        boxTracker = vector<vector<bool>>(9, vector<bool>(9, false));

        initialConfiguration(board);
        bool isSolvable = backtrack(board, 0, 0);
        // cout << "Can this config be solved ? " << boolalpha << isSolvable;

        return;
    }
private :
    vector<vector<bool>> rowTracker;
    vector<vector<bool>> colTracker;
    vector<vector<bool>> boxTracker;
};


int main(){

	cout<<"Hello World";

    return 0;
}

