/*
 * Author : Jatin Rohilla
 * Date   : 04/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 * output -

Integer     : 6
bin is      : 110
Reversed is : 3
bin is      : 11

 */

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#define INT_BITS  32

using namespace std;

//print data in binary
void printBin(unsigned n)
{
 short int iPos;
 
 int bits = (int)log2(n) + 1;

 for (iPos = (bits -1) ; iPos >= 0 ; iPos--)
 {
   (n & (1 << iPos))? printf("1"): printf("0");
 }
 printf("\n");

}

/*
Modified awesomeness
order logN
where n is the number and logN is the no of bits needed to represent N
works bothways - even on 32 bit integers
*/
unsigned int nBitReverseBits(unsigned int n)
{
    unsigned int rev = 0;

	// track how many bits processed
	//	int count = 0;

	// until number becomes zero
	while(n){

		// bitwise left shift 'rev' by 1
        rev <<= 1;

        // add LSB of 'n' to rev
        rev |= n & 1;

        // bitwise right shift 'n' by 1
        n >>= 1;

		// bits encountered
        // count++ ;
    }

	//	int totalbits = INT_BITS;
	//	rev <<= ( totalbits - count);
    // required number
    return rev;
}


int main()
{
    unsigned int x = 10;
    printf("Integer     : %u \nbin is      : ", x);printBin(x);

	// reverse
	unsigned int y = nBitReverseBits(x);

	printf("Reversed is : %u \nbin is      : ", y);printBin(y);
}
