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
    string toLowerCase(string str) {
        for(auto& it : str){
            if(it >= 'A' && it <= 'Z'){
                it = it-'A'+'a';
            }
        }
        return str;
    }
};

