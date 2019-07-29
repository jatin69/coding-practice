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
    bool isValid(string& curr){
        if(curr.length()==0){
            return false;
        }
        int i = 0;
        int j = curr.length()-1;
        while(i<j){
            if(curr[i]!=curr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string& s, int i, string& curr, int& count){
        if(i == s.length()){
            return;
        }
        curr.push_back(s[i]);
        if(isValid(curr)){
            count++;
        }
        backtrack(s, i+1, curr, count);
        curr.pop_back();
    }
    int countSubstrings(string s) {
        int count = 0;
        string curr = "";
        for(int i=0; i<s.length(); ++i){
            backtrack(s, i, curr, count);
        }
        return count;
    }
};

