/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::numDecodings(string s) {
    if(s.length()==0) return 0;
    if(s.length()==1) return s[0]=='0' ? 0 : 1 ;

    int n = s.length();
    int first = 1;
    int second = (s[n-1]=='0' ? 0 : 1) ;
    int third;
    for(int i = n-2; i>=0; --i){
        third = 0;
        if(s[i]>='1'){ third += second; }
        if((s[i]=='1') || (s[i]=='2' && s[i+1] <'7')){ third += first; }
        first = second;
        second = third;
    }
    return third;
}


