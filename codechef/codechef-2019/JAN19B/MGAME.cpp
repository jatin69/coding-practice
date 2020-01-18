/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * AC
 */


#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
	lli t, N, P, i, j, k;
	cin >> t;
	while (t--) {
		cin >> N >> P;

		if (N <= 2) {
			cout << P * P * P << "\n";
			continue;
		}

		lli sum = 0;
		lli mod = N % (N / 2 + 1);

		// fix i
		i = mod;
		j = P - mod;
		k = P - mod;
		sum += (j * k);

		// fix j
		j = mod;
		i = P - N;
		k = P - mod;
		sum += (i * k);

		// fix k
		k = mod;
		i = P - N;
		j = P - N;
		sum += (i * j);

		cout << sum << "\n";
	}

	return 0;
}
