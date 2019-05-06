/*
 * Author : Jatin Rohilla
 * Date   : 19/1/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * ref - https://www.codechef.com/problems/STACKS

 // binary search tag
 // redo using binary search to find minimum abs difference
 // TLE
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t, n, ele, min, min_idx;
	cin >> t;
	while (t--) {
		cin >> n;
		std::vector<int> a;

		for (int i = 0; i < n; ++i) {
			cin >> ele;
			a.push_back(ele);
		}

		std::vector<int> stacks;
		for (int i = 0; i < n; ++i) {
			ele = a[i];
			if (stacks.size() == 0) {
				stacks.push_back(ele);
			} else {
				min = -1;
				min_idx = -1;
				int j;
				for (j = 0; j < stacks.size(); ++j) {
					if (ele < stacks[j]) {
						if (min == -1) {
							min = stacks[j] - ele;
							min_idx = j;
						} else if (stacks[j] - ele < min) {
							min = stacks[j] - ele;
							min_idx = j;
						}
					}
				}
				if (min == -1) {
					stacks.push_back(ele);
				} else {
					stacks[min_idx] = ele;
				}
			}
		}

		std::sort(stacks.begin(), stacks.end());

		cout << stacks.size() << " ";
		int i;
		for (i = 0; i < stacks.size() - 1; ++i) {
			cout << stacks[i] << " ";
		}
		cout << stacks[i] << "\n";
	}

	return 0;
}
