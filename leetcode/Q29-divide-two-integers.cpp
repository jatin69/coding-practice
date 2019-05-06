/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Leetcode Q29 : https://leetcode.com/problems/divide-two-integers/
 * submission : https://leetcode.com/submissions/detail/157832561/
 *
 Points to note for this question :

 1. to be able to solve this with bitwise operators,
numbers have to be converted to long long,
because 31 shifts will throw numbers out of bound very often

2. constants often to be used are better if assigned to variables,
so compiler can optimise them.

3. Consideration of edge cases is very important.
If possible try to return early by checking edge cases.

if  (divisor == 0 ||
	(dividend == INT_MAX && divisor == 1) ||
	(dividend == INT_MIN && divisor == -1))
	return INT_MAX;

if(!dividend)
	return 0;

 */


#include <bits/stdc++.h>
using namespace std;

int divide(int _dividend, int _divisor) {
	long long dividend = _dividend;
	long long divisor = _divisor;

	bool signa = false, signb = false, sign = false;

	if (dividend < 0) {
		signa = true;
		dividend = -dividend;
	}
	if (divisor < 0) {
		signb = true;
		divisor = -divisor;
	}

	sign = signa ^ signb;

	long long quotient = 0;
	long long ONE = 1;

	for (int i = 31; i >= 0; --i) {
		if ((divisor << i) <= dividend) {
			dividend -= (divisor << i);
			quotient |= (ONE << i);
		}
	}

	if (sign) {
		quotient = -quotient;
	}

	return (quotient < INT_MIN || quotient > INT_MAX) ? INT_MAX : quotient;
}


// Driver code
int main() {
	// special case
	int a = -2147483648, b = -1;
	cout << "answer is : " << divide(a, b) << "\n";

	a = -2147483648, b = 1;
	cout << "answer is : " << divide(a, b) << "\n";

	a = 10, b = 3;
	cout << "answer is : " << divide(a, b) << "\n";

	a = 7, b = -3;
	cout << "answer is : " << divide(a, b) << "\n";

	return 0;
}
