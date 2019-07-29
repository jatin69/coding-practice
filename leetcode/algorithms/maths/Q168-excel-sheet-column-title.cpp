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
    string convertToTitle(int n) {
        string res;
        while(n){
            n--;
            res.push_back((n%26)+'A');
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

