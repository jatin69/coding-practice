/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==0){
            return (isBadVersion(n) ? 0 : -1);
        }

        int l = 0 ;
        int r = n ;
        int mid;
        int firstBad = -1;
        while(l<=r){
            mid = l + (r-l)/2;
            if(isBadVersion(mid)){
                firstBad = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return firstBad;
    }
};



