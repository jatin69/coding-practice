/*
 * Author : Jatin Rohilla
 * Date   : 2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	char A[3][3];
	bool found;
	while (t--) {
		found = false;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> A[i][j];
			}
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (A[i][j] == 'l') {
					if (A[i + 1][j] == 'l' && A[i + 1][j + 1] == 'l') {
						found = true;
						break;
					}
				}
			}
			if (found)
				break;
		}

		if (found) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

	return 0;
}
