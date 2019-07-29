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
    double myPow(double x, int n) {
        if (x == 1) return 1;
        if (n < 0) x = 1.0/x;

        return myPowRecur(x, n);
    }

private:
    double myPowRecur(double x, int n) {
        if (n == 0) return 1.0;

        double this_pow = myPowRecur(x, n/2);
        this_pow *= this_pow;
        if (n & 1) this_pow *= x;

        return this_pow;
    }
};

/* // mine -
    double myPow(double x, int n) {
        if(x==1 || n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n < 0){
            double N = n;   //  let n be -2^31
            N = -N;
            double curr = myPow(x, N/2);
            if(n%2==0){
                return (1/curr)*(1/curr);
            }
            else{
                return (1/curr)*(1/curr)*(1/x);
            }

        }
        else{
            double curr = myPow(x, n/2);
            if(n%2==0){
                return curr*curr;
            }
            else{
                return curr*curr*x;
            }
        }
    }
    */


int main(){

	cout<<"Hello World";

    return 0;
}

