#include <iostream>
using namespace std;
template <typename T>
class Stack {
	T* arr;
	int size;
	int top;

public:
	Stack(int s = 0) {
		size = s;
		arr = new T[size];
		top = -1;
	}

	bool isEmpty() { return (top == -1); }

	bool isFull() { return (top == size - 1); }

	T stackTop() { return arr[top]; }

	void push(T num) {
		if (isFull()) {
			throw "Satck overflow";
		}
		arr[++top] = num;
	}

	T pop() {
		if (isEmpty()) {
			throw "Stack underflow";
		}
		return arr[top--];
	}

	void display() {
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << "\t";
		}
	}
};

void decToBin(int num) {
	Stack<char> p(32);
	int i = 0;
	while (num > 0) {
		p.push((num % 2) + '0');
		num /= 2;
		i++;
	}
	cout << "No. of bits = " << i << endl;
	while (!p.isEmpty()) {
		cout << p.pop();
	}
}
int main() {
	bool flag = true;
	do {
		cout << "\n\n1.Convert Decimal to Binary.";
		cout << "\t0.Exit.";
		cout << "\nOption...";
		int option;
		cin >> option;
		switch (option) {
			case 1: {
				cout << "Enter Decimal number :";
				int num;
				cin >> num;
				decToBin(num);
				break;
			}

			case 0: {
				flag = false;
				break;
			}
		}
	} while (flag);

	return 0;
}
