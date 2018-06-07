/*
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 ref - https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-172-performance-engineering-of-software-systems-fall-2010/video-lectures/lecture-2-bit-hacks/
 
 * still to understand
 */

#include <stdio.h>

/* The function below gives the population count (No. of  1s in a 32 bit word)*/
unsigned int pop(unsigned x)
{
	x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	// from the following summation onwards a single mask can be used
	// on the summation, as the summation won't produce a carry.
	
	// pair of 4 bits
	x = (x + (x >> 4))  & 0x0F0F0F0F;
	
	// pair of 8 bits
	x = (x + (x >> 8))  & 0x00FF00FF;
	
	// pair of 16 bits
	x = (x + (x >> 16)) & 0x0000FFFF;
	return x;
}


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


int main()
{
    unsigned int i;
    unsigned int p,c;
    for (i = 0; i <= 31; i++)
	{
	    c = pop(i);
		p = parity(i);
		printf("num = 0x%.2X    No. of ones = %d    p = %d\n", i, c, p);
	}
	return 0;
}


/* Backgorund Knowledge

// count set bits for 64 bit integers.

unsigned int popcount64(unsigned long long x){

	// counting with 0101 0101
    x = (x & 0x5555555555555555ULL) + ((x >> 1) & 0x5555555555555555ULL);

	// counting with 0011 0011
	x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);

	// counting with 0000 1111
	x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FULL);

	// 0000 0001
    return (x * 0x0101010101010101ULL) >> 56;
}



/* The following function returns 0 if even paity or 1 if odd parity  *-/
unsigned int parity(unsigned x)
{
	// Method 1: 20 instructions
	/*
	x = (x & 0x0000FFFF) ^ ((x >> 16) & 0x0000FFFF);
	x = (x & 0x000000FF) ^ ((x >> 8) & 0x000000FF);
	x = (x & 0x0000000F) ^ ((x >> 4) & 0x0000000F);
	x = (x & 0x00000003) ^ ((x >> 2) & 0x00000003);
	x = (x & 0x00000001) ^ ((x >> 1) & 0x00000001);
	return x;
	*-/

	// More optimized given below:
	// Method 2: 15 instructions
	/*
	x = (x ^ (x >> 16)) & 0x0000FFFF;
	x = (x ^ (x >> 8))  & 0x000000FF;
	x = (x ^ (x >> 4))  & 0x0000000F;
	x = (x ^ (x >> 2))  & 0x00000003;
	x = (x ^ (x >> 1))  & 0x00000001;
	return x;
	*-/

	// More optimized given below:
	// Method 3: 11 instructions

	x = x ^ (x >> 1);  // Can be written as x ^= (x>>1);
	x = x ^ (x >> 2);  // Can be written as x ^= (x>>2);
	x = x ^ (x >> 4);  // Can be written as x ^= (x>>4);
	x = x ^ (x >> 8);  // Can be written as x ^= (x>>8);
	x = x ^ (x >> 16); // Can be written as x ^= (x>>16);

	// the following instruction can be written as x &= 1;
	x = x & 0x1; // The LSB is the parity bit
	return x;

	/*
	// Same as Method 3, just shifting order reversed:
	// Method 4: 11 instructions
	x = x ^ (x >> 16);
	x = x ^ (x >> 8);
	x = x ^ (x >> 4);
	x = x ^ (x >> 2);
	x = x ^ (x >> 1);
	x = x & 0x1; // The LSB is the parity bit
	return x;
	*-/
}

*/
