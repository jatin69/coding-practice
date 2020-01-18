/*
 * Author : Jatin Rohilla
 * Date   : 9-9-18
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * link - https://www.codechef.com/SEPT18B/problems/MAGICHF
 */


#include <iostream>
using namespace std;

int main() {
	int t, n, s, x, a, b;
	;
	cin >> t;
	while (t--) {
		cin >> n >> x >> s;
		while (s--) {
			cin >> a >> b;
			x = (x == a ? b : x == b ? a : x);
		}
		cout << x << "\n";
	}
	return 0;
}
