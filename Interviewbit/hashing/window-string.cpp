/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

string Solution::minWindow(string s, string t) {
    unordered_map<char, int> m;
    for(auto it : t){
        m[it]++;
    }

    int left = 0;
    int right = 0;
    int remaining = t.length();
    int minLen = INT_MAX;
    int minStart;

    while(right < s.length()){
        // expand window
        if( --m[s[right++]] >= 0){
            remaining--;
        }
        // shrink window
        while(remaining==0){
            if(right - left < minLen){
                minLen = right-left;
                minStart = left;
            }
            if(++m[s[left++]] > 0){
                remaining++;
            }
        }
    }
    if(minLen == INT_MAX){
        return "";
    }

    return s.substr(minStart, minLen);
}


