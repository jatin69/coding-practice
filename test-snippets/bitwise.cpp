#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int in_use = 0;
	int num = 1;
	cout << ~in_use;
	cout << (in_use & 1 << num);
	cout << (in_use ^ 1 << num);
	cout << pow(2, num) << "\n";
	cout << ~in_use;

	/*
	output -
	-1
	0
	2
	2
	-1
	*/
	return 0;
}