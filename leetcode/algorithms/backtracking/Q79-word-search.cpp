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
    bool backtrack(vector<vector<char>>& board, int i, int j, string& word, int start){
        if(start == word.length()){
            return true;
        }

        if(i < 0 || j < 0 || i == board.size() || j == board[0].size()){
            return false;
        }

        if(board[i][j]!=word[start]){
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '.';

        bool found =    backtrack(board, i-1, j, word, start+1)
                     || backtrack(board, i+1, j, word, start+1)
                     || backtrack(board, i, j-1, word, start+1)
                     || backtrack(board, i, j+1, word, start+1);

        board[i][j] = ch;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(backtrack(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

