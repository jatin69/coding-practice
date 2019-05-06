#include <bits/stdc++.h>
using namespace std;

/* Split the string into array based on delim */
vector<string> str_split(string str, string delim) {
	vector<string> tokens;
	string token;
	size_t prev = 0, pos = 0;

	do {
		// find `delim` in `str` after index `prev`
		pos = str.find(delim, prev);

		// if not found, we are done here
		if (pos == string::npos) {
			// break out the last string and push in array
			token = str.substr(prev, str.length());
			tokens.push_back(token);
			break;
		}
		// break out the string and push in array
		token = str.substr(prev, pos - prev);
		tokens.push_back(token);

		// move forward
		prev = pos + delim.length();

	} while (prev < str.length());

	//	for(auto it = tokens.begin(); it != tokens.end(); ++it) {
	//		cout << *it << " ";
	//	} cout << "\n";

	return tokens;
}

void printPattern(string str) {
	// split the string with space
	vector<string> A = str_split(str, " ");

	int longest = (*A.begin()).size();
	for (auto it = A.begin() + 1; it != A.end(); ++it) {
		if ((*it).size() > longest) {
			longest = (*it).size();
		}
	}

	for (int i = 0; i <= longest; ++i) {
		for (auto it = A.begin(); it != A.end(); ++it) {
			cout << left << setw((*it).size() + 1);
			i < (*it).size() ? cout << (*it)[i] : cout << " ";
		}
		cout << "\n";
	}
}

int main() {
	string str;
	getline(cin, str);
	printPattern(str);
	return 0;
}
