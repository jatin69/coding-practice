// order n^2

// passes subtask 1 and 2a
// TLE in others

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int arr[n];

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		bool flag = false;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if ((arr[i] != arr[j]) && arr[arr[i] - 1] == arr[arr[j] - 1]) {
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}

		if (flag) {
			cout << "Truly Happy" << endl;
		} else {
			cout << "Poor Chef" << endl;
		}
	}

	return 0;
}
