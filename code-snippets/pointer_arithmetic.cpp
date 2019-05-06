/*
 * Author : Jatin Rohilla
 * Date   : 23/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 */


#include <iostream>
using namespace std;

int main() {
	int q = 100;
	int* p = &q;
	// decrement the value
	cout << --(*p);

	cout << "\n";
	// decrement the pointer
	cout << *(--p);  // garbage answer


	return 0;
}
