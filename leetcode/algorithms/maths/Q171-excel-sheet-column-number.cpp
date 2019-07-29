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
    int titleToNumber(string s) {
        int val = 0;
        for(int i=s.length()-1; i>=0; --i){
            val += pow(26, s.length()-1-i) * (s[i]-'A'+1);
        }
        return val;
    }
};

