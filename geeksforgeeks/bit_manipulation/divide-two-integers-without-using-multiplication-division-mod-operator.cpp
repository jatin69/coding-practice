/*
 * Author : Jatin Rohilla
 * Date   : 07/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question - Divide two integers without using multiplication, division and mod operator.
 * https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
 *
 * Modified Question - https://www.interviewbit.com/problems/divide-integers/
 *
 * approach -
 * simple - simply keep subtracting divisor from dividend. This count is quotient.
 * But this is time consuming where difference between a and b is very large.
 * eg- a = 999999999 , b = 1
 *
 * Modified approach to utilise bitwise operations & jumping in in powers of 2
 */


#include<bits/stdc++.h>
using namespace std;

//
#include <bits/stdc++.h>
using namespace std;

// Function to divide a by b and return floor value it
int divide(long long dividend, long long divisor) {

// Calculate sign of divisor i.e.,
// sign will be negative only iff either one of them is negative

int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

// remove sign of operands
dividend = abs(dividend);
divisor = abs(divisor);

// Initialize the quotient
long long quotient = 0, temp = 0;

/* move from highest to lowest bit
whenever a bit passes test, it signifies divisor * 4 (some power of 2) is less than dividend.
so this 4 (some power of 2) is worthy of being in quotient.
*/
for (int i = 31; i >= 0; --i) {
	if ((divisor << i) <= dividend) {
	dividend -= divisor << i;
	quotient |= 1LL << i;               // LL just because we doing Long operations here
	}
}


if(sign<0){
	quotient = -quotient;
}

/* below two lines are used in another variant - Leetcode Q29

if (dividend == INT_MIN && divisor == -1) {
 	return INT_MAX;
 }
*/

return quotient;
}

// Driver code
int main() {
int a = 10, b = 3;
cout << divide(a, b) << "\n";

a = 43, b = -8;
cout << divide(a, b);

return 0;
}

