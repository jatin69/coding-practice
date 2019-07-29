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
    void backtrack(string& s, int start, int num, vector<string>& res){

        // clock specific checks
        int hours = std::bitset<4>(s.substr(6, 4)).to_ulong();
        if(hours > 11){
            return;
        }
        int minutes = std::bitset<6>(s.substr(0, 6)).to_ulong();
        if(minutes > 59){
            return;
        }

        // if num no of bulbs are now lit
        if(num==0){
            res.push_back(to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes));
            return;
        }

        // if reached string end
        if(start == s.length()){
            return;
        }

        for(int i=start; i<s.length(); ++i){
            // num-1 because we just lit one bulb
            // i+1 because, next bulb will be lit after index i
            // it can lit before i, but that'll just be a duplicate case,
            // already handled in previous backtracks
            s[i] = '1';
            backtrack(s, i+1, num-1, res);
            s[i] = '0';
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        string s = "0000000000";
        backtrack(s, 0, num, res);
        return res;
    }
};


