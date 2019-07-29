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
    void backtrack(string digits, int start, string curr, vector<string>& res){
        if(curr.length()==digits.length()){
            res.push_back(curr);
            return;
        }
        for(auto ch : m[digits[start]]){
            backtrack(digits, start+1, curr + ch, res);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0){
            return res;
        }
        backtrack(digits, 0, "", res);
        return res;
    }
private:
    unordered_map<char, string> m= {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
};

int main(){

	cout<<"Hello World";

    return 0;
}

