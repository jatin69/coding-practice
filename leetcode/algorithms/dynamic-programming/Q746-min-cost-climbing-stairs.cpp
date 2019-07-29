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
    int minCostClimbingStairs(vector<int>& cost) {
        int first = 0, second = 0, third = 0;
        for(int i = 2; i<=cost.size(); ++i){
            third = min(second+cost[i-1], first+cost[i-2]);
            first = second;
            second = third;
        }
        return third;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

