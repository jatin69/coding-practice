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
    void backtrack(unordered_map<char, int>& m, int& count){
        for(auto& it : m){
            if(it.second > 0){
                it.second--;
                count++;
                backtrack(m, count);
                it.second++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> m;
        for(auto ch : tiles){
            m[ch]++;
        }
        int count = 0;
        backtrack(m, count);
        return count;
    }
};



