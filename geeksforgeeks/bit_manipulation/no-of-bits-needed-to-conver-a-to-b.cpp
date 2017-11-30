/*
 * Author : Jatin Rohilla
 * Date   : 30/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<iostream>
using namespace std;

int main(){

	int a,b;
	
	a=4;    // 100
	b=7;    // 111
	
	// more test cases
	a=5;    // 00101
	b=16;   // 10000
	
	
	// find xor
	int diff= a^b;
	
	// count bits in xor
	int count=0;
	while(diff){
		count++;
		diff &=(diff-1);
	}
	
	cout << count << "\n";

    return 0;
}

