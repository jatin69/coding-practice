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
    bool isPalindrome(string& s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){ return false; }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string& s, int start, vector<string>& curr, vector<vector<string>>& res){
        if(start == s.length()){
            res.push_back(curr);
            return;
        }

        string test;
        for(int i = start; i < s.length(); ++i){
            test = s.substr(start, i-start+1);
            if(isPalindrome(test)){
                curr.push_back(test);
                backtrack(s, i+1, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);
        return res;
    }
};

