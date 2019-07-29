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
    vector<int> sortedSquares(vector<int>& A) {
        if(A.size()==0){
            return A;
        }
        int positivePointer = 0;
        while(positivePointer < A.size() && A[positivePointer] < 0){
            positivePointer++;
        }
        int negativePointer = positivePointer - 1;

        vector<int> res;
        while(positivePointer < A.size() && negativePointer >=0 ){

            if(abs(A[positivePointer]) < abs(A[negativePointer])){
                res.push_back(A[positivePointer] * A[positivePointer]);
                positivePointer++;
            }
            else{
                res.push_back(A[negativePointer] * A[negativePointer]);
                negativePointer--;
            }
        }

        while(positivePointer < A.size()){
            res.push_back(A[positivePointer] * A[positivePointer]);
            positivePointer++;
        }

        while(negativePointer >=0){
            res.push_back(A[negativePointer] * A[negativePointer]);
            negativePointer--;
        }

        return res;
    }
};
