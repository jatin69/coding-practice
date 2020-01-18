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

int main() {
	int h, w, x, y;
	cin >> h >> w >> x >> y;

	int g = __gcd(x, y);
	x /= g;
	y /= g;

	if (h / x < 1 || w / y < 1) {
		x = 0;
		y = 0;

	} else {
		int a = min(h / x, w / y);
		x *= a;
		y *= a;
	}
	cout << x << " " << y << "\n";
	return 0;
}
