/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::strStr(const string A, const string B) {
    string haystack = A;
    string needle = B;

    if(haystack.length()==0 || needle.length()==0 || haystack.length() < needle.length() ){
        return -1;
    }

    int i,j,k;
    for(i=0; i< haystack.length(); ++i){
        k = i;
        for(j=0; j<needle.length(); ++j){
            if(haystack[k]!=needle[j]){
                break;
            }
            k++;
        }
        if(j==needle.length()){
            return k-needle.length();
        }
    }

    return -1;
}


