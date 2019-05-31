/*
 * Author : Jatin Rohilla
 * Date   : 19-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * question - https://leetcode.com/problems/rotate-image/description/
 */


#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& A) {
	for (int i = 0; i < A.size(); ++i) {
		for (int j = i + 1; j < A[i].size(); ++j) {
			swap(A[i][j], A[j][i]);
		}
	}

	for (int i = 0; i < A.size(); ++i) {
		int j = 0;
		int k = A[i].size() - 1;
		while (j < k) {
			swap(A[i][j], A[i][k]);
			j++;
			k--;
		}
	}
}

int main() {
	vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	cout << "\n";
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

	rotate(A);
	cout << "\n\n";
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
