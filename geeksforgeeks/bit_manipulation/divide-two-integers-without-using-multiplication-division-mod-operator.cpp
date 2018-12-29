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
 * Modified Question with special considerations for edge cases
 * https://www.interviewbit.com/problems/divide-integers/
 *
 * approach -
 * simple - simply keep subtracting divisor from dividend. This count is quotient.
 * But this is time consuming where difference between a and b is very large.
 * eg- a = 999999999 , b = 1
 *
 * Modified approach -
 * utilise bitwise operations & jumping in in powers of 2.
 *
 * Similar type of question - leetcode Q29
 * Leetcode Q29 : https://leetcode.com/problems/divide-two-integers/
 * submission : https://leetcode.com/submissions/detail/157832561/
 *
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
long long quotient = 0;
long long ONE = 1;

/* move from highest to lowest bit
whenever a bit passes test, it signifies divisor * 4 (some power of 2) is less than dividend.
so this 4 (some power of 2) is worthy of being in quotient.
*/
for (int i = 31; i >= 0; --i) {
	
	if ((divisor << i) <= dividend) {
	dividend -= divisor << i;
	quotient |= ONE << i;               // LL just because we doing Long operations here
	}
}


if(sign<0){
	quotient = -quotient;
}

return quotient;

}

// Driver code
int main() {
int a = 10, b = 3;
cout << divide(a, b) << "\n";

a = 43, b = -2;
//cout << divide(a, b);

return 0;
}

