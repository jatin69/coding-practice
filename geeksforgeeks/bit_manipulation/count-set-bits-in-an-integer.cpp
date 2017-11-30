/*
 * Author : Jatin Rohilla
 * Date   : 29/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Objective : Count number of set bits in a number.
 * approach :
 
 * Naive  : Traverse linearly and count - theta(logN)
 * Basic.
 
 * Brian Kernighan’s Algorithm - Time Complexity :  O(logn)
 * Easy and efficient.
 
 * Inbuilt pop count - Easy to use - unknown complexity - Slow for big numbers.
 * A modified version of this known as popcount64 is about 3.5x faster.
 
 * Lookup Tables - pretty fast O(logN/k)
 * Good. But takes time to code tables.
 */

/*
pref order, Brian Kernighan’s Algorithm, then lookup table if faster needed.
*/

#include<iostream>
using namespace std;

/* Naivee approach
Function to get no of set bits in binary representation of positive integer n */
unsigned int naiveeCount(unsigned int n)
{
  unsigned int count = 0;
  while (n){
    count += n & 1;
    n >>= 1;
  }
  return count;
}

/* Brian Kernighan’s Algorithm
   Can Also be used to check if a number is powe of 2, as it has only 1 set bit.
*/
unsigned int brianCount(int n)
{
    unsigned int count = 0;
    while (n){
    	count++;
		n=(n&n-1);   // clear the least significant bit set
	}
    return count;
}

// out of league
unsigned int popcount64(unsigned long long x){
    x = (x & 0x5555555555555555ULL) + ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FULL);
    return (x * 0x0101010101010101ULL) >> 56;
}


unsigned int lookupCount(int n){
	
	// numbers = 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
	int table[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

	int count=0;
	
	while(n){
		// extract lowemost nibble & add to count.
		count += table[n & 0x0f];
		n= n>>4;
	}
	
	return count;
}

int main(){

	/* Naive One */
	cout << naiveeCount(7)  << "\n";
	
	
	/* Brian Kernighan’s Algorithm */
	cout << brianCount(7)  << "\n";
	
	
	/* Inbuilt pop count */
	/* For bigger numbers,
	__builtin_popcount = int
	__builtin_popcountl = long int
	__builtin_popcountll = long long
	*/
	cout << __builtin_popcount (7) << "\n";
	
	
	/* Modified pop count - pretty fast */
	cout << popcount64(7)  << "\n";
	
	
	/* Look up table
	The above effect can be replicated using custom lookup tables as well.
	Time complexity comes down to O(logN / K), where K : No of bits stored in lookup table.
	Space complexity increases by (2^K) to hold all combinations of K bits.
	*/

	cout << lookupCount(7) << "\n";
    return 0;
}

