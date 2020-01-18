#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q, k, num, count, maxCount;
	string s;
	cin >> n >> q >> k;
	vector<int> sequence;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sequence.push_back(num);
	}

	cin >> s;
	int start, end, size;
	size = sequence.size();
	start = 0;
	end = size - 1;
	for (int i = 0; i < q; i++) {
		if (s[i] == '!') {
			start = (start + 1) % size;
			end = (end + 1) % size;
		} else {
			count = 0;
			maxCount = 0;
			int j;
			for (j = start; j != end; j = (j + 1) % size) {
				if (sequence[j] == 1) {
					count++;
				} else {
					if (count >= maxCount) {
						cout << "\nMax count found at  i : " << (count - j + size) % size
							 << " and j : " << j - 1 << "\n";
						maxCount = count;
					}
					count = 0;
				}
			}
			if (sequence[j] == 1) {
				count++;
				cout << "\nMax count found at  i : " << (count - j + size) % size
					 << " and j : " << j - 1 << "\n";
			}



			if (count >= maxCount) {
				maxCount = count;
				cout << "\nMax count found at  i : " << (count - j + size) % size
					 << " and j : " << j - 1 << "\n";
			}
			if (maxCount >= k) {
				maxCount = k;
			}
			cout << maxCount << "\n";
		}
	}
	return 0;
}
