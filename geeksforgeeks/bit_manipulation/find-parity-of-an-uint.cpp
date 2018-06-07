/*
 * Author : Jatin Rohilla
 * Date   : 9/12/17
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * ref- using a modified version of Brian Kernighan's Algorithm
 * Worst case complexity is O(Log n).
 *
 * order 1 - http://www.geeksforgeeks.org/compute-parity-number-using-xor-table-look/
 */


#include<iostream>
using namespace std;

// takes logN which is infact less than equal log32
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


/*
Awesome method. log32 in all cases. Takes less instructions. hence faster.
*/
unsigned int parity(unsigned x)
{
	// Method 3: 11 instructions - fastest

	// alternate bundling formation : big to small & non sanitized
	x = x ^ ( x >> 16 );
	x = x ^ ( x >> 8 );
	x = x ^ ( x >> 4 );
	x = x ^  (x>>2);
	x = x ^  (x>>1);
	// The LSB is the parity bit needs to be extracted as it is not sanitized
	x = x & 0x1;

	// alternate bundling formation : big to small & sanitized
//	x = (x & 0x0000ffff) ^ ( (x & 0xffff0000) >> 16 );
//	x = (x & 0x00ff) ^ ( (x & 0xff00) >> 8 );
//	x = (x & 0x0f) ^ ( (x & 0xf0) >> 4 );
//	x = (x & 0x3) ^  ( (x & 0xc) >>2);
//	x = (x & 0x1) ^  ( (x & 0x2) >>1);
	// The LSB is the parity bit does not need to be extracted as it is already sanitized


	return x;

}



int main(){

	unsigned int n=7;
	cout<< (getParity(n) ? "odd":"even" );
	cout<<"\n";
	cout<< (parity(n) ? "odd":"even" );

    return 0;
}

