/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::getRow(int k) {
    vector<int> res(k+1, 1);
    int currLeft, nextLeft;
    for(int i=2; i<=k; ++i){
        currLeft = 1;
        for(int j=1; j<i; ++j){
            nextLeft = res[j];
            res[j] = currLeft + res[j];
            currLeft = nextLeft;
        }
    }
    return res;
}

