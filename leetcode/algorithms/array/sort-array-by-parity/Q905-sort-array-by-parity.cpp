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
    vector<int> sortArrayByParity(vector<int>& A) {
        int j=0;
        int i=0;
        while(i<A.size()){
            if(A[i]%2==0){
                swap(A[i], A[j]);
                j++;
            }
            i++;
        }
        return A;
    }
};

