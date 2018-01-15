/*
* topic - classes
* ref - https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
*/


#include<iostream>
using namespace std;

class Test {
	const int t;
public:
	Test(int t):t(t) {} //Initializer list must be used
	int getT() { return t; }
};

int main() {
	Test t1(10);
	cout<<t1.getT();
	return 0;
}

/* OUTPUT:
10 
*/
