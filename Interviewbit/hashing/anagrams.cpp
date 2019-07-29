/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> res;
    if(A.size()==0){
        return res;
    }
    unordered_map<string, vector<int>> m;
    for(int i=0; i<A.size(); ++i){
        string s = A[i];
        sort(s.begin(), s.end());
        m[s].push_back(i+1);
    }
    for(auto it : m){
        res.push_back(it.second);
    }
    return res;
}


