/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here

class Solution {
public:
    int numTrees(int n) {
        // catalan number
        // C(k) = C(k-1) * C(n-k)

        vector<int> cache(n+1, 0);
        cache[0] = 1;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=i; ++j){
                cache[i] += cache[j-1] * cache[i-j];
            }
        }
        return cache[n];
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

