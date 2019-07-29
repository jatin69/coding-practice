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
    void backtrack(string curr, int leftBracketCount, int rightBracketCount, int bracketPairCount, vector<string>& res){
        if(leftBracketCount == bracketPairCount && rightBracketCount == bracketPairCount){
            res.push_back(curr);
            return;
        }
        if(leftBracketCount < bracketPairCount){
            backtrack(curr+"(", leftBracketCount+1, rightBracketCount, bracketPairCount, res);
        }
        if(rightBracketCount < leftBracketCount){
            backtrack(curr+")", leftBracketCount, rightBracketCount+1, bracketPairCount, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, n, res);
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

