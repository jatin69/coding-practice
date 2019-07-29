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
    void placeQueen(vector<string>& currBoard, int& row, int& column){
        currBoard[row][column] = 'Q';
        rowTracker[row] = colTracker[column] = hillTracker[row+column] = daleTracker[row-column+totalQueens-1] = true;
    }
    void removeQueen(vector<string>& currBoard, int& row, int& column){
        currBoard[row][column] = '.';
        rowTracker[row] = colTracker[column] = hillTracker[row+column] = daleTracker[row-column+totalQueens-1] = false;
    }

    bool isSafeToPlaceQueen(vector<string>& currBoard, int& row, int& column){
        return !( rowTracker[row] || colTracker[column] ||
                 hillTracker[row+column] || daleTracker[row-column+totalQueens-1] );
    }

    void backtrack(vector<string>& currBoard, int currColumn){
        if(currColumn == totalQueens){
            res.push_back(currBoard);
            return;
        }
        for(int currRow=0; currRow<totalQueens; ++currRow){
            if(!isSafeToPlaceQueen(currBoard, currRow, currColumn)){ continue; }
            placeQueen(currBoard, currRow, currColumn);
            backtrack(currBoard, currColumn+1);
            removeQueen(currBoard, currRow, currColumn);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n==0){ return {};        }
        if(n==1){ return {{"Q"}};   }

        vector<string> currBoard(n, string(n, '.'));
        totalQueens = n;
        rowTracker  = vector<bool>(n, false);
        colTracker  = vector<bool>(n, false);
        hillTracker = vector<bool>(n*2-1, false);
        daleTracker = vector<bool>(n*2-1, false);

        backtrack(currBoard, 0);
        return res;
    }
private:
        int totalQueens;
        vector<vector<string>> res;
        vector<bool> rowTracker;
        vector<bool> colTracker;
        vector<bool> hillTracker;
        vector<bool> daleTracker;
};

int main(){

	cout<<"Hello World";

    return 0;
}

