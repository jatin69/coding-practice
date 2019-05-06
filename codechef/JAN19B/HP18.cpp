/*
 * Author : Jatin Rohilla
 * Date   : 04-01-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * AC - https://www.codechef.com/viewsolution/22188972
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
	// untie c and c++, speeds up in certain cases
	//	ios_base::sync_with_stdio(false);
	//	cin.tie(NULL);

	int t, N, a, b, ele, i;
	cin >> t;
	while (t--) {
		cin >> N >> a >> b;
		vector<int> A;

		for (i = 0; i < N; ++i) {
			cin >> ele;
			if (ele % a == 0 || ele % b == 0) {
				A.push_back(ele);
			}
		}

		N = A.size();

		// if a and b are equal
		if (a == b) {
			cout << "BOB\n";
			continue;
		}

		// when not equal

		// first turn is of bob
		bool turnBob = true;

		// Bob's turn
		bool turnedOK = false;

		// attack enemy
		for (i = 0; i < N; ++i) {
			if (A[i] && A[i] % b == 0 && A[i] % a == 0) {
				A[i] = 0;
				turnedOK = true;
			}
		}

		// if attack done, swap turn
		if (turnedOK) {
			A.erase(std::remove(A.begin(), A.end(), 0), A.end());
			N = A.size();
			turnBob = !turnBob;
		}

		while (1) {
			if (turnBob) {
				turnedOK = false;

				if (!turnedOK) {
					for (i = 0; i < N; ++i) {
						if (A[i] && A[i] % a == 0) {
							A[i] = 0;
							turnedOK = true;
							break;
						}
					}
				}

				if (!turnedOK) {
					cout << "ALICE\n";
					break;
				}
				turnBob = !turnBob;
			} else {
				turnedOK = false;

				// if no attack can be done
				if (!turnedOK) {
					for (i = 0; i < N; ++i) {
						if (A[i] && A[i] % b == 0) {
							A[i] = 0;
							turnedOK = true;
							break;
						}
					}
				}

				if (!turnedOK) {
					cout << "BOB\n";
					break;
				}
				turnBob = !turnBob;
			}

			// remove useless elements
			// popular erase-remove combo
			A.erase(std::remove(A.begin(), A.end(), 0), A.end());
			N = A.size();

			//			for(auto x : A){
			//				cout << x << " ";
			//			}
			//			cout << "\n";
		}
	}

	return 0;
}
