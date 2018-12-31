/*
 * Author : Jatin Rohilla
 * Date   : 08/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
concept -

1. which log to use ? log2 / log10 / loge ?
Does not matter, Really.
Any value : log base b (a)
can be represented as : (loga)/ (logb)
that being said, there is only a difference of constant factors between all logs,
which is in fact immaterial in time complexities.
Although, log base 2 looks convenient to use,
Natural log ( loge ) gives a much clearer picture when comparing complexities.

 */


#include<bits/stdc++.h>
using namespace std;

long long factorial(long long n)
{
  return (n == 1LL || n == 0LL) ? 1LL : factorial(n - 1) * n;
}
int main(){

	long long n ;
	long long r = 0;
	
	std::cout.precision(10);
	
	cout << "\n\t\t**** Time complexities chart ****\t\n";
	
	n=10;
	cout << "\n*** For n :" << n << " **** \n";

	// double exponential time
	cout << "2^(2^n)   :" << pow(2,pow(2,n)) << "\n";

	// factorial time
	cout << "     n!   :" << factorial(n) << "\n";

	// exponential time
	cout << "  (4^n)   :" << pow(4,n) << "\n";
	cout << "  (3^n)   :" << pow(3,n) << "\n";
	cout << "  (2^n)   :" << pow(2,n) << "\n";  

	// polynomial time : cubic, quadratic
	cout << "   n^3    :" << n*n*n << "\n";
    cout << "   n^2    :" << n*n << "\n";       // = 4^(logN)

	// quasilinear time
	cout << "n*logn    :" << (n*log(n)) << "\n";
	cout << "log(n!)   :" << (long long) log(factorial(n)) << "\n";

	// linear time
	cout << "     n    :" << n << "\n";
	
	cout << "log(2^n)  :" << log(pow(2,n)) << "\n";    

	// below two are equal
	cout << "2^log(n)  :" << pow(2,log(n)) << "\n"; // smaller than n as per karumanchi
	cout << " n^log2   :" << pow(n,log(2)) << "\n"; // = n^0.6
	
	cout << " root n   :" << pow(n,0.5) << "\n";    // = n^0.5

	// higher powers of n are needed to observe difference in logs
	n=pow(2,25);
	cout << "\n*** For n :" << n << " **** \n";

	// poly-logarithmic time
	cout << "(logn)^2  :" << log(n)*log(n) << "\n";  

	// logarithmic time
	cout << "     logn :" << log(n) << "\n";
	cout << "root logn :" << pow(log(n),0.5)<< "\n";
	
	// log-logarithmic time
	cout << "log(logn) :" << log(log(n)) << "\n";
	
	// constant time
    cout << "      1   :" << "1" << "\n";

	return 0;
}

