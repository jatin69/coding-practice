/*
 * Author : Jatin Rohilla
 * Date   : 5/12/17
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * resource - https://blog.regehr.org/archives/1063
 *
 * Objective : rotating bits in a number
 */
 
 
#include<iostream>
#include<cmath>
using namespace std;

uint32_t rotl32b (uint32_t x, uint32_t n)
{
  if (!n) return x;
  return (x<<n) | (x>>(32-n));
}

uint32_t rotr32b (uint32_t x, uint32_t n)
{
  if (!n) return x;
  return (x>>n) | (x<<(32-n));
}

int main(){

	int n=6;
	
	// rotate left by 1
	cout<< rotl32b(n,1) << "\n";
	
	// rotate left by 1
	cout<< rotr32b(n,1) << "\n";

	cout<<"\n";
	n=3;
	
	// rotate left by 1
	cout<< rotl32b(n,1) << "\n";

	// rotate left by 1
	cout<< rotr32b(n,1) << "\n";

	/*
	A separate type : move bits to extrema
	number   : 0000 0000 0000 0000 0000 0000 0010 0010
	becomes :  1000 1000 0000 0000 0000 0000 0000 0000
	
	bits = log2 (n) +1;
	cout<<rotl32b(n,32-bits);
	*/
	
    return 0;
}

