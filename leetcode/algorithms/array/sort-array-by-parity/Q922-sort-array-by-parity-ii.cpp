/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int evenTracker = 0;
        for(int i=0; i<A.size(); i=i+2){
            if(A[i]%2!=0){
                while(!(A[evenTracker]%2==0 && evenTracker%2!=0)){
                    evenTracker++;
                }
                swap(A[i], A[evenTracker]);
            }
        }
        return A;
    }
};

