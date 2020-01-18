/*
 * Author : Jatin Rohilla
 * Date   : 2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include <bits/stdc++.h>
using namespace std;

int getDay(string d) {
	if (!d.compare("monday"))
		return 1;
	if (!d.compare("tuesday"))
		return 2;
	if (!d.compare("wednesday"))
		return 3;
	if (!d.compare("thursday"))
		return 4;
	if (!d.compare("friday"))
		return 5;
	if (!d.compare("saturday"))
		return 6;
	if (!d.compare("sunday"))
		return 7;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string sday1, sday2;
		cin >> sday1 >> sday2;

		int L, R;
		cin >> L >> R;
		int day1 = getDay(sday1);
		int day2 = getDay(sday2);

		int diff = (day2 - day1 + 1 + 7) % 7;
		if (!diff)
			diff = 7;

		//	 cout << "diff is " << diff << "\n\n";
		bool notDone = true;
		int val = 0;
		bool many = false;

		for (int i = 0; diff + (7 * i) <= R; ++i) {
			if (diff + (7 * i) >= L && diff + (7 * i) <= R) {
				if (notDone) {
					notDone = false;
					val = diff + (7 * i);
				} else {
					many = true;
					break;
				}
			}
		}

		if (notDone) {
			cout << "impossible\n";
		} else if (many) {
			cout << "many\n";
		} else {
			cout << val << "\n";
		}
	}
	return 0;
}
