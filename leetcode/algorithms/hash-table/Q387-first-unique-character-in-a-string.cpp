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
    int firstUniqChar(string s) {

        unordered_map<char, pair<int, int>> m;
        for(int i=0; i<s.length(); ++i){
            m[s[i]].first++;        // frequency
            m[s[i]].second = i;     // index
        }

        int minIndex = s.length();
        for(auto it : m){
            if(it.second.first==1){
                minIndex = min(minIndex, it.second.second);
            }
        }

        return minIndex < s.length() ? minIndex : -1;
    }
};


