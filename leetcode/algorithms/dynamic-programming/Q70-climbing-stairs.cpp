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
    int climbStairs(int n) {
        if(n==1 || n==2){
            return n;
        }

        int first = 1;
        int second = 2;
        int res;
        for(int i=3; i<=n; ++i){
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

