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
    vector<int> getRow(int rowIndex) {
        vector<int> A(rowIndex+1, 1);
        if(rowIndex==0 || rowIndex ==1){
            return A;
        }

        int currLeft, nextLeft;
        for(int rowNo = 2; rowNo <= rowIndex; ++rowNo){
            currLeft = A[0];
            for(int i=1; i<rowNo; ++i){
                nextLeft = A[i];
                A[i] = currLeft + A[i];
                currLeft = nextLeft;
            }
        }
        return A;
    }
};

