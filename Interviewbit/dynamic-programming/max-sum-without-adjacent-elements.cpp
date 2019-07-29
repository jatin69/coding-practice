/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::adjacent(vector<vector<int> > &A) {

    if(A[0].size()==0) return 0;

    int first = max(A[0][0], A[1][0]);
    if(A[0].size()==1) return first;

    int second = max(first, max(A[0][1], A[1][1]));
    if(A[0].size()==2) return second;

    int third ;
    for(int j=2; j<A[0].size(); ++j){
        third = max(second, first + max(A[0][j], A[1][j]));
        first = second;
        second = third;
    }
    return third;
}


