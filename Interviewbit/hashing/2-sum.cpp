/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    std::unordered_map<int, int> m;
    vector<int> res = {};
    for(int i=0;i<A.size();++i){
        auto it = m.find(B - A[i]);
        if(it == m.end()){
            m.insert({A[i], i});
        }
        else{
            res.push_back(it.second+1);
            res.push_back(i+1);
        }
    }
    return res;
}


