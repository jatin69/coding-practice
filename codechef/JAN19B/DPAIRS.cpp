/*
 * Author : Jatin Rohilla
 * Date   : 10-1-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * AC
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> A(n);
	vector<int> B(m);

	std::unordered_map<int, pair<int, int>> mymap;

	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> B[i];
	}

	// find min element of A
	int minA = A[0];
	int minAid = 0;
	for (int i = 1; i < n; ++i) {
		if (A[i] < minA) {
			minA = A[i];
			minAid = i;
		}
	}

	// and max of B
	int maxB = B[0];
	int maxBid = 0;
	for (int i = 1; i < m; ++i) {
		if (B[i] > maxB) {
			maxB = B[i];
			maxBid = i;
		}
	}


	int currSum = 0;
	int limit = n + m - 1;

	int i = 0;
	int j = maxBid;

	for (i = 0; i < n; ++i) {
		// find current sum
		currSum = A[i] + B[j];

		// check if already exists map
		if (mymap.count(currSum) == 0) {
			mymap[currSum] = make_pair(i, j);
			limit--;
		}
	}

	i = minAid;
	for (j = 1; j < m; ++j) {
		if (j == maxBid) {
			continue;
		}

		// find current sum
		currSum = A[i] + B[j];

		// check if already exists map
		if (mymap.count(currSum) == 0) {
			mymap[currSum] = make_pair(i, j);
			limit--;
		}
	}

	if (limit == 0) {
		for (auto x : mymap) {
			cout << x.second.first << " " << x.second.second << "\n";
		}
		return 0;
	}

	if (n >= m) {
		int i = 0;
		int j = 0;

		while (limit) {
			for (j = 0; j < m; ++j) {
				// find current sum
				currSum = A[i] + B[j];

				// check if already exists map
				if (mymap.count(currSum) == 0) {
					mymap[currSum] = make_pair(i, j);
					limit--;
				}
				if (limit == 0) {
					break;
				}
			}
			++i;
		}
	} else {
		int i = 0;
		int j = 0;

		while (limit) {
			for (i = 0; i < n; ++i) {
				// find current sum
				currSum = A[i] + B[j];

				// check if already exists map
				if (mymap.count(currSum) == 0) {
					mymap[currSum] = make_pair(i, j);
					limit--;
				}
				if (limit == 0) {
					break;
				}
			}
			++j;
		}
	}


	for (auto x : mymap) {
		cout << x.second.first << " " << x.second.second << "\n";
	}

	return 0;
}
