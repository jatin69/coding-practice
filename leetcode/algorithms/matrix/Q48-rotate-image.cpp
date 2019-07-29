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
    void rotate(vector<vector<int>>& A) {
    for(int i=0;i<A.size();++i){
        for(int j=i+1; j<A[i].size();++j){
            swap(A[i][j], A[j][i]);
        }
    }

    for(int i=0;i<A.size();++i){
        int j= 0;
        int k = A[i].size()-1;
        while(j<k){
            swap(A[i][j], A[i][k]);
            j++;
            k--;
        }
    }
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

