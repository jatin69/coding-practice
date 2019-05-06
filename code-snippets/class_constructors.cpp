/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 */


#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "make A\n"; }
	~A() { cout << "destroy A\n"; }
};

class B : public A {
public:
	B() { cout << "make B\n"; }
	~B() { cout << "destroy B\n"; }
};

int main() {
	B b;

	return 0;
}
