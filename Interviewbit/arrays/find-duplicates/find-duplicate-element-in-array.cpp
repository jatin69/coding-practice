/*
 * Author : Jatin Rohilla
 * Date   : 10/06/18
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * NOTE : It is allowed to modify array.
 * approach can be used to find all duplicates as well.
 *
 * Time : Order N
 * Space : order 1
 */


#include<bits/stdc++.h>
using namespace std;

int repeatedNumber(vector<int> &A) {

    for(int i=0;i<A.size();++i){

		if( A[ abs(A[i]) -1 ] > 0){
		 A[ abs(A[i]) -1 ] *= -1;
	}
		else{
			// element is already negative, means its index has been repeated.
			return (abs(A[i])-1)+1;
		}
    }
    return -1;
}


int main(){

	vector<int> A = { 3, 4, 1, 4, 1};
	cout << repeatedNumber(A);

    return 0;
}

