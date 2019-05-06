#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	int n, ele;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> A;
		for (int i = 0; i < n; ++i) {
			cin >> ele;
			A.push_back(ele);
		}

		vector<int> cF(A.size());

		cF[0] = A[0];

		for (int i = 1; i < cF.size(); i++) {
			cF[i] = cF[i - 1] + A[i];
		}

		int days = 0;
		int people = 1;
		int idx = 0;

		while (people < n) {
			people += cF[idx];
			idx = people - 1;
			days++;
		}

		cout << days << "\n";
	}

	return 0;
}
