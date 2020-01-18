/*
 * Author : Jatin Rohilla
 * Date   : 16-12-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * AC - https://www.codechef.com/viewsolution/21968800
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, c, v;
	cin >> N >> c;

	vector<int> A(N);

	int guess;
	int l = 0, r = N - 1;
	int di = 2;
	int ans;
	while (l <= r) {
		if (r - l < di) {
			di /= 2;
		}
		guess = l + (r - l) / di;
		cout << "1 " << guess + 1 << endl;

		cin >> v;
		if (v == 1) {
			r = guess - 1;
			A[guess] = 1;
			ans = guess;
			cout << "2 " << endl;
			di = di * 2;
		} else if (v == 0) {
			l = guess + 1;
		} else {
			break;
		}
	}

	cout << "3 " << ans + 1 << endl;
	return 0;
}
