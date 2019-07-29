/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

void backtrack(string& s, int start, string& curr, vector<string>& res, unordered_map<char, string>& charMap){
    if(start == s.length()){
        res.push_back(curr);
        return;
    }
    for(char ch : charMap[s[start]]){
         curr.push_back(ch);
         backtrack(s, start+1, curr, res, charMap);
         curr.pop_back();
    }
}

vector<string> Solution::letterCombinations(string s) {
    vector<string> res;
    if(s.length()==0){
        return res;
    }
    unordered_map<char, string> charMap = {
        { '0', "0" },
        { '1', "1" },
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };
    string curr = "";
    backtrack(s, 0, curr, res, charMap);
    return res;
}


