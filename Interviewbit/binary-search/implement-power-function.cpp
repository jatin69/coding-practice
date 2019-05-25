/*
 * Author : Jatin Rohilla
 * Date   : 08-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * note : ans should not be negative
 * link - https://www.interviewbit.com/problems/implement-power-function/
 */


#include<bits/stdc++.h>
using namespace std;

int pow(int x, int n, int d) {

    if(x==0)    return 0;
    if(n==0)    return 1;

    long long int half = pow(x, n/2, d);
    long long int res = (half*half)%d;

    if(n&1){ res = (res*x)%d; }
    return (res+d)%d;
}

int main(){

	cout << pow(2, 3, 3) << "\n";                       // 2
	cout << pow(-1, 1, 20) << "\n";                     // 19
	cout << pow(-1, 2, 20) << "\n";                     // 1
	cout << pow(71045970, 41535484, 64735492) << "\n";  // 20805472

    return 0;
}

