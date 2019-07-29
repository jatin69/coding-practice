/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


int Solution::hammingDistance(const vector<int> &A) {
    typedef long long int lli;
    lli res = 0;
    for(int i=0; i<31; ++i){
        lli count = 0;
        for(auto it : A){
            if( it & (1<<i) ) count++;
        }
        res += (2*(count * (A.size()-count))%1000000007);
        res %= 1000000007;
    }
    return res;
}
