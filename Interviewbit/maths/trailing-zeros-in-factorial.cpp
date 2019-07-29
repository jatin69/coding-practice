/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


int Solution::trailingZeroes(int A) {

    int powerOfFive = 0;
    int currPower = A/5;

    while(currPower){
        powerOfFive += currPower;
        currPower = currPower/5;
    }
    return powerOfFive;
}

