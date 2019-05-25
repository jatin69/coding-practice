/*
 * Author : Jatin Rohilla
 * Date   : 09-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/minimize-the-absolute-difference/
 */


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C) {

    int minDiff = INT_MAX;
    int currDiff;

    int i = A.size()-1;
    int j = B.size()-1;
    int k = C.size()-1;

    while(i>=0 && j>=0 && k>=0){

        currDiff = abs(max(A[i], max(B[j], C[k]))-min(A[i], min(B[j], C[k])));
        if(currDiff < minDiff){
            minDiff = currDiff;
        }

        int maxEle = max(A[i], max(B[j], C[k]));
        if(maxEle==A[i]){   i--;    }
        if(maxEle==B[j]){   j--;    }
        if(maxEle==C[k]){   k--;    }

    }
    return minDiff;
}

int main(){

	cout<<"Hello World";

    return 0;
}

