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
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        for(auto& ch : s){
            m1[ch]++;
        }
        unordered_map<char, int> m2;
        for(auto& ch : t){
            m2[ch]++;
        }
        return m1==m2;
    }
};


