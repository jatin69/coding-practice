/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    if(A.size() < 3){
        return res;
    }
    for(int i=0; i+2<A.size(); ++i){
        int target = -A[i];
        int p = i+1;
        int q = A.size()-1;
        while(p<q){
            if(A[p]+A[q] == target){
                res.push_back({A[i], A[p], A[q]});
                while(p<q && A[p]==A[p+1]){ p++; }
                while(p<q && A[q]==A[q-1]){ q--; }
                p++;
                q--;
            }
            else if(A[p]+A[q] < target){
                p++;
            }
            else{
                q--;
            }
        }
        while(i+2 < A.size() && A[i] == A[i+1]){ i++; }
    }
    return res;
}

