/*
 * Author : Jatin Rohilla
 * Date   : 14-01-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * AC
 */

/*
CRUX

group of 3 handled. Now handle, group of 1, 2 => 4, 5

group of 3 - 	abA, bcB, caC
group of 4 -    abA, bcB, cdC, daD
group of 5 -    abA, bcB, cdC, deD, eaE

use first 5 primes for 'abcde' - 2, 3, 5, 7, 11
next 50,000 primes for input satisfaction

*/


#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int lli;

vector<lli> SieveOfEratosthenes(int n) {
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	vector<lli> primeNumbers;

	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p) {
				prime[i] = false;
			}
		}
	}

	for (lli p = 2; p <= n; p++) {
		if (prime[p]) {
			primeNumbers.push_back(p);
		}
	}

	return primeNumbers;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// produces 50,000 primes
	lli LIMIT = 612000;
	vector<lli> primeNumbers = SieveOfEratosthenes(LIMIT);

	//  only allowed upto 10^9
	//	cout << primeNumbers.size() << "\n";
	//	cout <<  (11*primeNumbers[primeNumbers.size()-1]) << "\n";

	lli t;
	cin >> t;
	while (t--) {
		lli n;
		cin >> n;

		int cyclesof3 = 0, cyclesof4 = 0, cyclesof5 = 0;

		if (n % 3 == 0) {
			cyclesof3 = n / 3;
		} else if (n % 3 == 1) {
			cyclesof3 = n / 3 - 1;
			cyclesof4 = 1;
		} else if (n % 3 == 2) {
			cyclesof3 = n / 3 - 1;
			cyclesof5 = 1;
		}


		int i = 4;
		while (cyclesof3--) {
			cout << primeNumbers[0] * primeNumbers[1] * primeNumbers[++i] << " ";
			cout << primeNumbers[1] * primeNumbers[2] * primeNumbers[++i] << " ";
			cout << primeNumbers[2] * primeNumbers[0] * primeNumbers[++i] << " ";
		}

		while (cyclesof4--) {
			cout << primeNumbers[0] * primeNumbers[1] * primeNumbers[++i] << " ";
			cout << primeNumbers[1] * primeNumbers[2] * primeNumbers[++i] << " ";
			cout << primeNumbers[2] * primeNumbers[3] * primeNumbers[++i] << " ";
			cout << primeNumbers[3] * primeNumbers[0] * primeNumbers[++i] << " ";
		}

		while (cyclesof5--) {
			cout << primeNumbers[0] * primeNumbers[1] * primeNumbers[++i] << " ";
			cout << primeNumbers[1] * primeNumbers[2] * primeNumbers[++i] << " ";
			cout << primeNumbers[2] * primeNumbers[3] * primeNumbers[++i] << " ";
			cout << primeNumbers[3] * primeNumbers[4] * primeNumbers[++i] << " ";
			cout << primeNumbers[4] * primeNumbers[0] * primeNumbers[++i] << " ";
		}

		cout << "\n";
	}

	return 0;
}
