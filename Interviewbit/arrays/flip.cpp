/*
 * Author : Jatin Rohilla
 * Date   : 10/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question - https://www.interviewbit.com/problems/flip/
 *
 * approach -
 * 1. 2D array approach. Solution is correct.
 * but has O(n*n) time and space complexity. We need better.
 * 
 * 2. (Editorial) : Uses kadane's algo. same base logic.
 * time complexity - O(n) and uses constant space.
 */


#include<bits/stdc++.h>
using namespace std;


/*
2D array approach. Nice work coming up with it. But we need better. It has -
O(n*n) time complexity
O(n*n) space complexity
*/
vector<int> flip(string str) {

	int n = str.length();
	int **A = new int*[n];
	for(int i=0;i<n;++i){
		A[i] = new int[n];
	}

	for(int i=0;i<n;++i){
		for(int j=i; j<n;++j){
			if(i==j){
				if(str[j]=='1'){
					A[i][j] = -1;
				}
				else{
					A[i][j] = 1;
				}
			}
			else{
				if(str[j]=='1'){
					A[i][j] = A[i][j-1] - 1;
				}
				else{
					A[i][j] = A[i][j-1] + 1;
				}
			}
		}
	}

	int max = 0;
	int imax = -1, jmax = -1;
	for(int i=0;i<n;++i){
		for(int j=i; j<n;++j){
			if(A[i][j]>max){
				max = A[i][j];
				imax = i;
				jmax = j;
			}
		}
	}

	if(max==0){
		return vector<int>();
	}
	else{
		vector<int> res = { imax+1, jmax+1 };
		return res;
	}
}


/*
Editorial -
Modified version of the same base logic.
kadane's algo - https://en.wikipedia.org/wiki/Maximum_subarray_problem
*/

vector<int> Editorialflip(string A) {
    int l = 0, lmax = -1, rmax = -1;
    int maxi = 0, cmax = 0;
    int len = A.length();
    for(int i=0;i<len;i++) {
        cmax += (A[i]=='0'?1:-1);
        if(cmax>maxi) {
            maxi = cmax;
            lmax = l;
            rmax = i;
        }
        if(cmax<0) {
            l = i+1;
            cmax = 0;
        }
    }
    if(lmax == -1 || rmax == -1) {
        return vector<int>(0, 0);
    }
    vector<int> t(2, 0);
    t[0] = lmax+1;
    t[1] = rmax+1;
    return t;
}



int main(){

string A =
//		"0011101"       // 1 2
//		"011010101001110101001010101"   // 4 11
		"1101001010101111"      // 3 6
;
	
//	vector<int> res = Editorialflip(A);
	vector<int> res = flip(A);
	for(int i=0;i<res.size();i++){
		cout << res[i] << " ";
	}

    return 0;
}

