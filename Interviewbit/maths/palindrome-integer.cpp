/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::isPalindrome(int A) {
    if(A<0)  return 0;

    string s = to_string(A);
    int p = 0, q = s.length()-1;
    while(p<q){
        if(s[p]!=s[q]){
            return 0;
        }
        p++;
        q--;
    }
    return 1;
}


