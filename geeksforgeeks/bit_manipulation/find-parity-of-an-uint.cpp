/*
 * Author : Jatin Rohilla
 * Date   : 9/12/17
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * ref- using a modified version of Brian Kernighan’s Algorithm
 * Worst case complexity is O(Log n).
 *
 * order 1 - http://www.geeksforgeeks.org/compute-parity-number-using-xor-table-look/
 */


#include<iostream>
using namespace std;


bool getParity(unsigned int n){
	
	// 0 1's is even parity
	bool parity=false;
	
	while(n){
		parity = !parity;
		// symbolic of brian kernighan's
		n= n&(n-1);
	}
	return parity;
}

int main(){

	unsigned int n=7;
	cout<< (getParity(n) ? "odd":"even" );

    return 0;
}

