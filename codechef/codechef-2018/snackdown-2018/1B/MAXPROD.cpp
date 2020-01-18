/*
 * Author : Jatin Rohilla
 * Date   : 29-10-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include <bits/stdc++.h>
using namespace std;

#define MODVALUE 1000000007
typedef long long int lli;

int main() {
	int t;
	cin >> t;

	while (t--) {
		lli n, k;
		cin >> n >> k;

		lli midsum = k * (k + 1) / 2;
		if (n < midsum) {
			cout << "-1";
		} else if (n == midsum) {
			cout << "0";
		} else {
			lli initialSum = 1;
			lli tempSum = n - midsum;

			initialSum += (tempSum / k);
			if (initialSum != 1) {
				lli extraSum = tempSum % k;
				lli res = 1;

				lli arr[k];

				int i = k - 1;
				while (extraSum) {
					arr[i] = initialSum + i + 1;
					extraSum--;

					i--;
				}

				while (i >= 0) {
					arr[i] = initialSum + i;
					i--;
				}

				for (int i = 0; i < k; i++) {
					res *= (arr[i] * (arr[i] - 1)) % MODVALUE;
					res %= MODVALUE;
				}

				cout << res;
			} else {
				cout << "0";
			}
		}
		cout << "\n";
	}
	return 0;
}
