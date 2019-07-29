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
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;    // calculate the index of the last element of the merged array

        // go from the back by A and B and compare and put to the A element which is larger
        while(i>=0 && j>=0){
            if(A[i]>B[j])   A[k--]=A[i--];
            else            A[k--]=B[j--];
        }

        // not needed they are both same
        // while(i>=0)         A[k--]=A[i--];

        // if B is longer than A just copy the rest of B to A location
        while(j>=0)         A[k--]=B[j--];
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

