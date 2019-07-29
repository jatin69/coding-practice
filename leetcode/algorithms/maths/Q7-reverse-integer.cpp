/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */

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

// june 2019
class Solution {
public:
    int reverse(int x) {
        if(INT_MIN == x) return 0;
        if(x < 0) return -reverse(-x);
        int result = 0;
        while(x > 0){
            int a = x % 10;
            x = x / 10;
            if((INT_MAX - a) / 10 < result)
              return 0;
            result = result * 10 + a;
        }
        return result;
    }
};
