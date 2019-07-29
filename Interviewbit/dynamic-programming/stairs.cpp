/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::climbStairs(int A) {
    if(A==0) return 0;
    if(A==1) return 1;
    if(A==2) return 2;

    int first = 1;
    int second = 2;
    int third;
    for(int i=3; i<=A; ++i){
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}


