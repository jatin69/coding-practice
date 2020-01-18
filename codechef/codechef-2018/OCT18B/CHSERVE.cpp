#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int p1, p2, k;
	while (t--) {
		cin >> p1 >> p2 >> k;
		(((p1 + p2) / k) % 2 == 0) ? cout << "CHEF\n" : cout << "COOK\n";
	}

	return 0;
}
