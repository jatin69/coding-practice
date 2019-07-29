/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::grayCode(int n) {
    vector<int> res = {0};
    for(int i=0; i<n; ++i){
        int currCount = res.size();
        int addOneToLeft = (1<<i);
        while(currCount--){
            res.push_back((res[currCount] | addOneToLeft));
        }
    }
    return res;
}


