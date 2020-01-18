/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include <bits/stdc++.h>
using namespace std;

enum status { unmarked, chosen, marked };

int main() {
	int N, M;
	cin >> N >> M;

	// create grid
	vector<vector<pair<int, status>>> A(N + 1, vector<pair<int, status>>(N + 1));

	// fixed cells
	int r, c;
	for (int i = 1; i <= 2 * M; ++i) {
		cin >> r >> c;
		A[r][c].second = marked;
	}

	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < N + 1; ++j) {
			cin >> A[i][j].first;
			A[i][j].first = unmarked;
		}
	}


	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < N + 1; ++j) {
			cout << A[i][j].first << ":" << A[i][j].second << "   ";
		}
		cout << "\n";
	}



	return 0;
}
