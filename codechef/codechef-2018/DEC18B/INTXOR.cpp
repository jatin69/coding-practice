/*
 * Author : Jatin Rohilla
 * Date   : 16-12-2018
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
	int t, n, res, val, AC;
	cin >> t;
	while (t--) {
		cin >> n;
		int A[n + 1]{0};

		int no_of_4_element_cycles{0};
		int x_123, x_234, x_124, x_134;

		int no_of_5_element_cycles{0};
		int x_125, x_145;

		int no_of_7_element_cycles{0};
		int x_345, x_456, x_567, x_127, x_167;

		// n elements can't be figured out at once, so figure in cycles

		// figure out cycles
		if (n % 4 == 0) {
			no_of_4_element_cycles = n / 4;
		} else if (n % 4 == 1) {
			no_of_4_element_cycles = (n / 4) - 1;
			no_of_5_element_cycles = 1;
		} else if (n % 4 == 2) {
			no_of_4_element_cycles = (n / 4) - 1;
			// no of 6 element cycles = 1,

			// but 6 element cycles are not possible, so make cycles of 5 elements
			no_of_4_element_cycles -= 1;
			no_of_5_element_cycles = 2;
		} else if (n % 4 == 3) {
			no_of_4_element_cycles = (n / 4) - 1;
			no_of_7_element_cycles = 1;
		}

		// now simply resolve cycles
		int i = 0;

		// 4 element cycles
		while (no_of_4_element_cycles--) {
			cout << "1"
				 << " " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
			cin >> x_123;
			cout << "1"
				 << " " << i + 2 << " " << i + 3 << " " << i + 4 << endl;
			cin >> x_234;

			cout << "1"
				 << " " << i + 1 << " " << i + 2 << " " << i + 4 << endl;
			cin >> x_124;
			cout << "1"
				 << " " << i + 1 << " " << i + 3 << " " << i + 4 << endl;
			cin >> x_134;

			// find logic
			A[i + 2] = x_123 ^ x_234 ^ x_124;
			A[i + 3] = x_123 ^ x_234 ^ x_134;

			A[i + 1] = x_123 ^ A[i + 2] ^ A[i + 3];
			A[i + 4] = x_234 ^ A[i + 2] ^ A[i + 3];

			i = i + 4;
		}

		// 5 element cycles
		while (no_of_5_element_cycles--) {
			cout << "1"
				 << " " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
			cin >> x_123;
			cout << "1"
				 << " " << i + 2 << " " << i + 3 << " " << i + 4 << endl;
			cin >> x_234;
			cout << "1"
				 << " " << i + 3 << " " << i + 4 << " " << i + 5 << endl;
			cin >> x_345;

			cout << "1"
				 << " " << i + 1 << " " << i + 2 << " " << i + 5 << endl;
			cin >> x_125;
			cout << "1"
				 << " " << i + 1 << " " << i + 4 << " " << i + 5 << endl;
			cin >> x_145;

			// find logic
			A[i + 4] = x_123 ^ x_125 ^ x_345;
			A[i + 3] = x_125 ^ x_145 ^ x_234;
			A[i + 5] = x_345 ^ A[i + 3] ^ A[i + 4];
			A[i + 2] = x_234 ^ A[i + 3] ^ A[i + 4];
			A[i + 1] = x_123 ^ A[i + 2] ^ A[i + 3];

			i = i + 5;
		}


		// 7 element cycles
		while (no_of_7_element_cycles--) {
			cout << "1"
				 << " " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
			cin >> x_123;
			cout << "1"
				 << " " << i + 2 << " " << i + 3 << " " << i + 4 << endl;
			cin >> x_234;
			cout << "1"
				 << " " << i + 3 << " " << i + 4 << " " << i + 5 << endl;
			cin >> x_345;
			cout << "1"
				 << " " << i + 4 << " " << i + 5 << " " << i + 6 << endl;
			cin >> x_456;
			cout << "1"
				 << " " << i + 5 << " " << i + 6 << " " << i + 7 << endl;
			cin >> x_567;

			cout << "1"
				 << " " << i + 1 << " " << i + 2 << " " << i + 7 << endl;
			cin >> x_127;
			cout << "1"
				 << " " << i + 1 << " " << i + 6 << " " << i + 7 << endl;
			cin >> x_167;

			// find logic
			A[i + 5] = x_123 ^ x_127 ^ x_345 ^ x_456 ^ x_567;
			A[i + 6] = x_123 ^ x_234 ^ x_456 ^ x_167 ^ x_567;

			A[i + 7] = x_567 ^ A[i + 5] ^ A[i + 6];
			A[i + 4] = x_456 ^ A[i + 5] ^ A[i + 6];
			A[i + 3] = x_345 ^ A[i + 4] ^ A[i + 5];
			A[i + 2] = x_234 ^ A[i + 3] ^ A[i + 4];
			A[i + 1] = x_123 ^ A[i + 2] ^ A[i + 3];

			i = i + 7;
		}

		cout << "2";
		for (int i = 1; i <= n; ++i) {
			cout << " " << A[i];
		}
		cout << endl;

		cin >> AC;
		if (AC == -1) {
			exit(0);
		}
	}

	return 0;
}
