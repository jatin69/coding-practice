class Solution {
public:
	int romanToInt(string s) {
		map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
								{'C', 100}, {'D', 500}, {'M', 1000}};

		int sum = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (roman[s[i]] >= roman[s[i + 1]]) {
				sum += roman[s[i]];
			} else {
				sum += (-roman[s[i]] + roman[s[i + 1]]);
				i++;
			}
		}
		return sum;
	}
};

/*

1- I

4- IV
5- V

9- IX
10 - X

XL - 40
L - 50

XC - 90
C - 100

CD - 400
D - 500

CM - 900
M - 1000


XC + V + IV - 99


*/