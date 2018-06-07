/*
 * Author : Jatin Rohilla
 * Date   : 04/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * output -

Integer     : 12
bin is      : 00000000000000000000000000001100
Reversed is : 805306368
bin is      : 00110000000000000000000000000000

appraoch : A lot of approaches are available. 2 most interesting ones are -

A. Merge sort appraoch
reversal in Bundles of 1, 2, 4, 8, 16 bits

B. Awesome one
simply extract LSB, OR with LSB of revNum
move originalNum to one bit right, so as to access next bit as LSB
move revNum to one bit left, so as the first LSB will eventually become MSB
repeat.
When exact bit reversal required -> this is enough.
When 32 bit reversal -> simply shift the revNum remaining times to left

 */

#include <stdio.h>
#include <stdlib.h>

#define INT_BITS  32


//print data in binary
void printBin(unsigned n)
{
 short int iPos;

 for (iPos = (INT_BITS -1) ; iPos >= 0 ; iPos--)
 {
   (n & (1 << iPos))? printf("1"): printf("0");
 }
 printf("\n");

}

// simple method - order logN
/*
Loop through all the bits of an integer.
If a bit at ith position is set in the i/p no. then set the bit at (NO_OF_BITS � 1) � i in o/p.
Where NO_OF_BITS is number of bits present in the given number.
*/
unsigned int simpleReverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = INT_BITS;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
   }
    return reverse_num;
}

// standard method
// order logN
// is subset of perfect solution below
unsigned int standardReverseBits(unsigned int num)
{
    unsigned int count = INT_BITS - 1;
    unsigned int reverse_num = num;

    num >>= 1;
    while(num)
    {
       reverse_num <<= 1;
       reverse_num |= num & 1;
       num >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
}

/* Perfect Method - order logN
where n is the number and logN is the no of bits needed to represent N
can be generically applied to reversal of exact bits
*/
unsigned int nBitReverseBits(unsigned int n)
{
    unsigned int rev = 0;

	// track how many bits processed
	int count = 0;
	
	// until number becomes zero
	while(n){

		// bitwise left shift 'rev' by 1
        rev <<= 1;

        // add LSB of 'n' to rev
        rev |= n & 1;

        // bitwise right shift 'n' by 1
        n >>= 1;

		// bits encountered
        count++ ;
    }

	int totalbits = INT_BITS;
	rev <<= ( totalbits - count);
    // required number
    return rev;
}


/*
merge sort variant for 32 bit number
needs to write separate constants for different bit numbers
can't be generically applied to reversal of exact bits
*/
unsigned int MergeSortReverseBits(register unsigned int x)
{
 // pair swap
 x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));

 // 2 bit group swaps
 x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));

 // 4 bit group swaps
 x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));

 // 8 bit group swaps
 x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));

 // 16 bit group swaps
 x = (((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16));

 return x;

}


// lookup table method
// need to make a look up table to simply map values


int main()
{
    unsigned int x = 12;
    printf("Integer     : %u \nbin is      : ", x);printBin(x);

	// reverse
	unsigned int y = nBitReverseBits(x);

	printf("Reversed is : %u \nbin is      : ", y);printBin(y);
}
