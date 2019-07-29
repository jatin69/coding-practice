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
private:
    vector<vector<vector<int>>> winningCases = {
        // rows
        { {0,0}, {0,1}, {0,2} },
        { {1,0}, {1,1}, {1,2} },
        { {2,0}, {2,1}, {2,2} },

        // columns
        { {0,0}, {1,0}, {2,0} },
        { {0,1}, {1,1}, {2,1} },
        { {0,2}, {1,2}, {2,2} },

        // diagonals
        { {0,0}, {1,1}, {2,2} },
        { {0,2}, {1,1}, {2,0} },

    };
public:
    bool isWinner(vector<string>& board, char ch){
        for(auto c : winningCases){
            if( (board[c[0][0]][c[0][1]] == board[c[1][0]][c[1][1]]) &&
                (board[c[1][0]][c[1][1]]== board[c[2][0]][c[2][1]])  &&
                (board[c[0][0]][c[0][1]] == ch) ) { return true; }
        }
        return false;
    }

    bool validTicTacToe(vector<string>& board) {

        int xCount = 0, oCount = 0;
        for(auto row : board){
            for(auto ch : row){
                if(ch=='X'){
                    xCount++;
                }
                else if(ch=='O'){
                    oCount++;
                }
            }
        }
        if(!(xCount == oCount || xCount == 1+oCount)){
            return false;
        }

        if(xCount == oCount){
            return !isWinner(board, 'X');
        }
        else{
            return !isWinner(board, 'O');
        }
        return true;
    }
};

