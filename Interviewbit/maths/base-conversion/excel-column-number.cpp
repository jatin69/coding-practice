/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


int Solution::titleToNumber(string A) {
    int j = 0;
    int res = 0;
    for(int i=A.length()-1; i>=0; --i){
        res += (A[i]-'A' + 1) * pow(26, j++);
    }
    return res;
}

