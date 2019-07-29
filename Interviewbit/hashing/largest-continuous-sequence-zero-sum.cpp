/*
 * Author : Jatin Rohilla
 * Date   : 15-06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::lszero(vector<int> &A) {
    // 1 2 -2 4 -4
    // 1 3  1 5  1

    // map of sum and index
    unordered_map<int, int> m;
    int preSum = 0;

    int maxLen = 0, currLen = 0;
    int maxI = 0, maxJ = 0;

    m[0] = -1;  // for sequences which get presum 0

    for(int i=0; i<A.size(); ++i){
        preSum += A[i];
        if(m.find(preSum)==m.end()){
            m[preSum] = i;
            continue;
        }
        currLen = i-m[preSum];
        if(currLen > maxLen){
            maxLen = currLen;
            maxI = m[preSum]+1;
            maxJ = i+1;
        }
    }
    vector<int> res;
    for(int i=maxI; i<maxJ; ++i){
        res.push_back(A[i]);
    }
    return res;
}



int main(){

	cout<<"Hello World";

    return 0;
}

