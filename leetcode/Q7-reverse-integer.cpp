class Solution {
public:
	int reverse(int x) {
		if (x == 0) {
			return x;
		}
		bool neg = (x < 0);
		if (neg) {
			x = x * -1;
		}

		int res = 0;
		int i = -1;
		int rem;
		stack<int> A;
		while (x) {
			A.push(x % 10);
			x = x / 10;
		}
		while (!A.empty()) {
			i++;
			res += A.top() * pow(10, i);
			A.pop();
		}
		if (res < 0) {
			return 0;
		}
		if (neg) {
			res = res * -1;
		}
		return res;
	}
};