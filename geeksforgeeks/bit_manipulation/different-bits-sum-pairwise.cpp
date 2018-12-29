/*
 * Author : Jatin Rohilla
 * Date   : 07/06/18
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question - https://www.interviewbit.com/problems/different-bits-sum-pairwise/
 * editorial - https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
 */


#include<bits/stdc++.h>
using namespace std;

int f(int x, int y){
	int res = x^y;
	int count=0;
	while(res){
		count++;
		res = res&res-1;
	}
	return count;
}

/*
The below solution uses simple observation paired with brain kernighan's method.
O(n^2) supposedly

approach - simple
observe all pairs and deduce.
*/
int cntBits(vector<int> &A) {

	int n = A.size();
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			sum += f(A[i],A[j]);
		}
	}

	return (sum<<1)%1000000007;
}


/* O(31*n) solution. Here, 31 is treated as constant and not as logV,
because in question it was not mentioned that each value can range upto V
If the value was given a bound, we would have to mention it as O(nlogV)

approach -
divides each bit iteration into two sets
set / unset
Each set bit can go against each unset bit.
Therefore, we have
count = set bits
(n-count) = unset bits, trivially
*2 to because f(i,j) and f(j,i) are treated separate.
total combination for that bit = count * (n-count) * 2
Do that for all 32 bits
*/
int EfficientcntBits(vector<int> &A) {

	int sum=0;
	int n = A.size();
	for(int i=0;i<32;i++){
		int count = 0;
		for(int j=0;j<n;j++){
			if( A[j] & 1<<i ){
				count++;
			}
		}
		sum += count * (n-count) * 2;
	}

	return sum%1000000007;
}

int main(){

	vector<int> A = {3, 1, 5, 6, 27, 8};
	cout << EfficientcntBits(A);
    return 0;
}

