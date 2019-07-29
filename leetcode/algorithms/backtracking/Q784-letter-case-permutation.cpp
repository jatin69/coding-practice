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
    void backtrack(string& S, int i, vector<string>& res){
        if(i == S.length()){
            res.push_back(S);
            return;
        }

        backtrack(S, i+1, res);
        if(isalpha(S[i])){
             // toggle case
            S[i] ^= 32;
            backtrack(S, i+1, res);
            S[i] ^= 32;
        }
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if(S.length()==0){
            return res;
        }
        backtrack(S, 0, res);
        return res;
    }
};

