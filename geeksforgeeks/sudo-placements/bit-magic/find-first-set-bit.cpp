/*
 * Author : Jatin Rohilla
 * Date   : 10-07-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://practice.geeksforgeeks.org/problems/find-first-set-bit/0/?track=SP-Bit%20Magic

Input:
2
18
12

Output:
2
3

*/

#include <bits/stdc++.h>
using namespace std;
int main()
 {
	int t,n;
	unsigned int ONE = 1;
	cin>>t;

	while(t--){
	    cin>>n;

	    if(n){
	        int i=0;
    	    int res = 0;
    	    while(i<32){
    	        if((n & ONE<<i)){
    	            res = i+1;
    	            break;
    	        }
    	        else{
    	            i++;
    	        }
    	    }
    	    cout << res << "\n";
	    }
	    else{
	        cout << "0" << "\n";
	    }
	}
	return 0;
}
