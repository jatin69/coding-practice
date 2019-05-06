/*
 * Author : Jatin Rohilla
 * Date   : 04-01-2019
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
	int t;
	cin >> t;
	cin.ignore();
	string str;
	while (t--) {
		getline(cin, str);
		int limit = str.length() - 3;
		int i = 0;
		for (i = 0; i <= limit; ++i) {
			if (str[i] == 'n' && str[i + 1] == 'o' && str[i + 2] == 't') {
				if ((i == 0 && i + 3 == str.length()) || (i == 0 && str[i + 3] == ' ') ||
					(i == limit && str[i - 1] == ' ') ||
					(str[i - 1] == ' ' && str[i + 3] == ' ')) {
					cout << "Real Fancy\n";
					break;
				}
			}
		}
		if (i > limit) {
			cout << "regularly fancy\n";
		}
	}

	return 0;
}
