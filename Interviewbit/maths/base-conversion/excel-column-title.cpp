/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// more elegant solution exists in leetcode folder

string Solution::convertToTitle(int A) {
    int n = A;
    int rem;
    string res = "";
    while(n){
        // cout << n << " ";
        rem = n%26;
        if(rem!=0){
            res += rem-1 + 'A';
        }
        else{
            // take carry
            n -= 1;
            rem = 26;
            res += rem-1 + 'A';
        }
        n = n/26;
    }
    reverse(res.begin(), res.end());
    return res;
}


