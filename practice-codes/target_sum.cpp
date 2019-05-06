/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Problem :  Given an array of integers, return indices of the two numbers such that
 * they add up to a specific target.You may assume that each input would have
 * exactly one solution, and you may not use the same element twice.
 *
 * Approach : Use hashmap from STL
 * Pick one element from array, calculate its partner, find its partner in hashmap,
 * if found, result is found.
 * if not, add this element to hashmap
 *
 * Time complexity - O(n)
 *
 */


#include <iostream>
#include <map>
using namespace std;

int main() {
	int SIZE = 15;
	int a[SIZE] = {1, 2, 4, 5, 6, 7, 8, 10, 14, 11, 3, 11, 65, 9, 17};

	int target = 11;
	int n1, n2;
	bool flag = false;

	map<int, int> partner;
	map<int, int>::iterator it;

	for (int i = 0; i < SIZE; ++i) {
		int iPair = target - i;
		it = partner.find(iPair);
		if (it != partner.end()) {
			n1 = i;
			// n1=it->first;
			n2 = iPair;
			// n2=it->second;
			flag = true;
			break;
		} else {
			partner.insert(std::make_pair<int, int>(i, i));
		}
	}

	if (flag) {
		cout << "Pair is : " << n1 << " and " << n2;
	} else {
		cout << "No pair exists.";
	}

	return 0;
}
