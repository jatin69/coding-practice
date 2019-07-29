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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ms;
        unordered_map<char, char> mt;

        for(int i=0; i<s.length(); ++i){

            if(ms.count(s[i])==0 && mt.count(t[i])==0){
                    ms[s[i]] = t[i];
                    mt[t[i]] = s[i];
            }
            if(ms[s[i]]!=t[i] || mt[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};

