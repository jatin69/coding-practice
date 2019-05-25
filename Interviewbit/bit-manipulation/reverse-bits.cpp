/*
 * Author : Jatin Rohilla
 * Date   : 3-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
* https://www.interviewbit.com/problems/reverse-bits/
 * Nice
 */


#include<bits/stdc++.h>
using namespace std;

unsigned int reverse_editorial(unsigned int A) {

	// first bit needs to be shifted 31 times
	unsigned int count = sizeof(A)*8-1;
	
	unsigned int reverse_num = A;
    
    while(A){
    	
    	reverse_num <<= 1;      // go left
		A >>=1;                 // go right
		reverse_num |= A & 1;   // join
		
        count--;
    }
    reverse_num <<= count;
    return reverse_num;
}

// merge sort method
unsigned int reverse(unsigned int A) {
    if(A==0) return 0;

    unsigned int x = A;

    // swap adjacent bits
    x = ( (x & 0x55555555) << 1  ) | ( (x & 0xAAAAAAAA) >> 1 );

    // swap pairs
    x = ( (x & 0x33333333) << 2  ) | ( (x & 0xCCCCCCCC) >> 2 );

    // swap half byte
    x = ( (x & 0x0F0F0F0F) << 4  ) | ( (x & 0xF0F0F0F0) >> 4 );

    // swap byte
    x = ( (x & 0x00FF00FF) << 8  ) | ( (x & 0xFF00FF00) >> 8 );

    // swap 2 bytes
    x = ( (x & 0x0000FFFF) << 16  ) | ( (x & 0xFFFF0000) >> 16 );

    return x;
}

int main(){

	unsigned int A;
	
	A=3;	//  3221225472
	cout <<reverse_editorial(A) << "\n";

	A=273;	//  2290089984
	cout <<reverse_editorial(A) << "\n";

    return 0;
}

