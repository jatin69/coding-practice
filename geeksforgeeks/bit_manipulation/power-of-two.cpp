/*
 * Author : Jatin Rohilla
 * Date   : 25/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Objective : Test whether a number is power of two or not
 * approach : we know the number of set bits in a power of two is one.
 * We want to leverage this fact, so we count the number of 1's.
 * To do this efficiently, we use Brian Kernighan’s Algorithm.
 * A little tweak to handle case n=0
 */


#include<iostream>
using namespace std;

bool isPowerOfTwo(long long int n){
    return n && (! (n&n-1));
}

int main(){
    cout << (isPowerOfTwo(0				)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(1				)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(16			)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(128			)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(4096			)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(32768			)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(1048576		)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(2147483648	)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(4294967296	)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(8589934592	)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(17179869184	)?"yes":"no") << "\n";
    return 0;
}

