/*
 * Author : Jatin Rohilla
 * Date   : Dec-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

typedef long long int ulli;

int main(){
	int t;
	cin>>t;
	while(t--){
		ulli n, k;
		cin >> n >> k;
		vector<ulli> A(n);
		for(int i=0;i<n;++i){
			cin >> A[i];
		}

		// sliding window method
		
		int L = 0, R = 0;
		ulli windowSum = 0;

		int maxL = L, maxR = R;
		ulli maxSum = windowSum;

		while(R < n){

			
			if(A[R] > k){
				R++;
				L = R;
				windowSum = 0;
				continue;
			}
			
			// expand
			if(windowSum + A[R] <= k){

				while(windowSum + A[R] <= k){
//					cout << "L is " << L << " and R is " << R << " and windowSum is " << windowSum << "\n";
					windowSum += A[R];
					R++;
				}
				if(windowSum  > maxSum){
					maxSum = windowSum;
					maxL = L;
					maxR = R-1;
//					cout << " MAX  : L is " << maxL << " and R is " << maxR << " and windowSum is " << maxSum << "\n";
				}
			}
			// shrink
			else{
				windowSum -= A[L];
				L++;
			}
			
		}
		
		if(maxSum == 0){
			cout << "-1\n";
		}
		else{
			cout << maxL+1 << " " << maxR+1 << " " << maxSum << "\n";
		}
	}
	return 0;
}


