/*
 * Author : Jatin Rohilla
 * Date   : 20-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * swap1 is standard swap.
 * swap2 and swap3 fails when we need to replace the contents of two pointers,
 * becaause they have addresses, and arithmetic & XOR distorts addresses
 */


#include<bits/stdc++.h>
using namespace std;

// standard swap using third variable
void swap1(int& a, int&b){
	cout << "\n\nBefore swap =>  a : " << a << " and b : " << b ;
	int t = a;
	a = b;
	b = t;
	cout << "\nAfter  swap =>  a : " << a << " and b : " << b ;
}

/* without using third variable -> arithmetics
problem -> overflow at large points
*/
void swap2(int& a, int&b){
	cout << "\n\nBefore swap =>  a : " << a << " and b : " << b ;
	a = a+b;
	b = a-b;
	a = a-b;
	cout << "\nAfter  swap =>  a : " << a << " and b : " << b ;
}

/* without using third variable -> XOR
*/
void swap3(int& a, int&b){
	cout << "\n\nBefore swap =>  a : " << a << " and b : " << b ;
	a = a^b;
	b = a^b;
	a = a^b;
	cout << "\nAfter  swap =>  a : " << a << " and b : " << b ;
}

int main(){

	int a = 5;
	int b = 10;
	
	swap1(a,b);
	swap2(a,b);
	swap3(a,b);
	
    return 0;
}

