/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());

    int diff = INT_MAX;
    for(int i=0;i<A.size();++i){

        int j = 0;
        int k = A.size()-1;
        while(j < k){
            if(j==i){ j++; continue;}
            if(k==i){ k--; continue; }

            int currdiff = B-(A[j]+A[k]+A[i]);
            if(currdiff == 0)    { return B;  }
            if(currdiff > 0)     { j++;       }
            else if(currdiff < 0){ k--;       }

            if( abs(currdiff) < abs(diff) ){
                diff = currdiff;
            }

        }
    }

    return B-diff;
}


