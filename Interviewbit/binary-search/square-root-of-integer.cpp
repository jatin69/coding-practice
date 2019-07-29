/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::sqrt(int A) {

    long long int l = 1;
    long long int r = A;
    long long int mid ;
    bool found = false;

    while(l<=r){

        mid = l + (r-l)/2;

        if(mid*mid == A){
            found = true;
            break;
        }
        else if(mid*mid < A){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    if(found){
        return mid;
    }
    else{
        return min(l, r);
    }

}


