/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> res(n);

    stack<int> s;
    for(int i=n-1; i>=0; --i){
        while(!s.empty() && A[i] < A[s.top()]){
            res[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        res[s.top()] = -1;
        s.pop();
    }
    return res;
}


