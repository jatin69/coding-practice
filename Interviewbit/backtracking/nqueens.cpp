/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

void placeQueen(
    vector<string>& board,
    int r,
    int c,
    vector<bool>& rowTracker,
    vector<bool>& colTracker,
    vector<bool>& hillTracker,
    vector<bool>& daleTracker
){
    board[r][c] = 'Q';
    rowTracker[r] = colTracker[c] = true;
    hillTracker[r+c] = daleTracker[r-c+board.size()-1] = true;
}

void removeQueen(
    vector<string>& board,
    int r,
    int c,
    vector<bool>& rowTracker,
    vector<bool>& colTracker,
    vector<bool>& hillTracker,
    vector<bool>& daleTracker
){
    board[r][c] = '.';
    rowTracker[r] = colTracker[c] = false;
    hillTracker[r+c] = daleTracker[r-c+board.size()-1] = false;
}

bool isSafe(
    vector<string>& board,
    int r,
    int c,
    vector<bool>& rowTracker,
    vector<bool>& colTracker,
    vector<bool>& hillTracker,
    vector<bool>& daleTracker
){
    return !(rowTracker[r] || colTracker[c] || hillTracker[r+c] || daleTracker[r-c+board.size()-1]);
}


void backtrack(
    vector<string>& board,
    int row,
    int& n,
    vector<vector<string>>& res,
    vector<bool>& rowTracker,
    vector<bool>& colTracker,
    vector<bool>& hillTracker,
    vector<bool>& daleTracker
){
    if(row == n){
        res.push_back(board);
        return;
    }
    for(int col = 0; col<n; ++col){
        if(isSafe(board, row, col, rowTracker, colTracker, hillTracker, daleTracker)){
            placeQueen(board, row, col, rowTracker, colTracker, hillTracker, daleTracker);
            backtrack(board, row+1, n, res, rowTracker, colTracker, hillTracker, daleTracker);
            removeQueen(board, row, col, rowTracker, colTracker, hillTracker, daleTracker);
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    if(n<=0){
        return {};
    }
    if(n==1){
        return {{"Q"}};
    }

    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    vector<bool> rowTracker(n, false);
    vector<bool> colTracker(n, false);
    vector<bool> hillTracker(2*n-1, false);
    vector<bool> daleTracker(2*n-1, false);

    backtrack(board, 0, n, res, rowTracker, colTracker, hillTracker, daleTracker);
    return res;
}


