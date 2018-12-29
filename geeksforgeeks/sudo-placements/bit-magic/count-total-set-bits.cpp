/*
 * Author : Jatin Rohilla
 * Date   : 10-07-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
link - https://practice.geeksforgeeks.org/problems/count-total-set-bits/0/?ref=self

Input:
2
4
17

Output:
5
35

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int A[1001];
    A[0] = 0;
    A[1] = 1;
    int val = 0;
    int lastPowOfTwo = 0;
    for(int i=2;i<=1000;++i){
        if(i == pow(2,lastPowOfTwo+1)){
            A[i] = 1;
            lastPowOfTwo = lastPowOfTwo + 1;
        }
        else{
            int x = i - pow(2, lastPowOfTwo);
            A[i] = 1 + A[x];
        }
        // cout << A[i] << "  ";
    }
    // cout << "\n\n";
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int sum = 0 ;
	    for(int i=0; i<=n; ++i){
	        sum += A[i];
	    }
	    cout << sum << "\n";
	}
	return 0;
}
