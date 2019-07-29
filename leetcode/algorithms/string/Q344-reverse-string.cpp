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
    void rev(vector<char>& s, int l, int r){
        if(l>r){
            return;
        }
        swap(s[l], s[r]);
        rev(s, l+1, r-1);
    }
    void reverseString(vector<char>& s) {
        return rev(s, 0, s.size()-1);
    }
};

