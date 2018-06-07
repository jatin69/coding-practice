/*
 * Author : Jatin Rohilla
 * Date   : 06/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Q - https://www.interviewbit.com/problems/single-number-ii/
 * and at https://www.geeksforgeeks.org/find-the-element-that-appears-once/
 *
 * approach - 2 variable approach to hold the bits occurence ones, twice
 * and remove if they occure thrice.
 *
 * Another appraoch -
 * Add ith bit (1<<i) of each element (32 iterations req for 32 bits)
 * if the sum (ie, count of 1's) is a multiple of 3. All good.
 * If not multiple of 3, this bit is part of single occurence.
 * OR it to result at its appropriate place.
 */


#include<bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &A) {
    
    int ones=0, two=0, mask;

    for(int i=0;i<A.size();++i){

		/*
		first encounter, If not present in `one`, won't add in two as well.
		(it needs to go to `one` first)
		second encounter, If already present in `one`, add to `two` as well.
		( will get auto removed from `one` in next step)
		third encounter, Not present in A. But Present in two.
		So for next step `two` already has the value.
		
		*/
        two = two | (ones & A[i]);

		/*
		first encounter, If not present, will get added.
		Second encounter, If already present in `one`, will get automatically removed.
		third encounter, not present in one. But will now get added to `one`.
		`one` now has the value.
		*/
        ones = ones ^ A[i];


		/*
		Both `one` and `two` has the values. Need to remove that value from both.
		Find the common bits. These bits needs reset to remove the value.
		Make a  Negated mask, so common bits are now zero in mask.
		*/
        mask = ~(ones & two );
		// AND the mask to reset those bits in `one` and `two`
        ones &= mask;
        two &= mask;
    }

	// at the end, `one` will have the single element. Two will be zero.
    return ones;
    
}

int main(){

	vector<int> A = {
	12, 1, 12, 3, 12, 1, 1, 2, 3, 3
	};
	int single = singleNumber(A);
	cout << "Single occurence element is : "<< single;
    return 0;

}


/*
Detailed explanation of above solution at -
https://www.careercup.com/question?id=7902674

find the string ->
"Explanation for siva.sai.2020's code."
- Rama B March 10, 2011 |

*/

/* Same logic, different variant code -

int singleNumber(const vector<int> &A) {
 
    int ones = 0, twos = 0;
    for(int i = 0; i < A.size(); i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;

}


*/
