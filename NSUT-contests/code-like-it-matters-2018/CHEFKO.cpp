/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int> A(n);
		vector<int> B(n);
		for(int i=0;i<n;++i){
			cin>>A[i] >> B[i];
		}
		
		int maxLen = INT_MIN;
		
//		for(int i=0; i+k <= n;++i){
//			cout << "\nidx" << i << " and " << i+k-1 << "\n";
//			cout << "Int : " << *min_element(A.begin() + i, A.begin() + i + k-1) << " , " << *max_element(B.begin() + i, B.begin() + i + k-1);
//			maxLen = max(maxLen, *min_element(B.begin() + i, B.begin() + i + k-1) - *max_element(A.begin() + i, A.begin() + i + k-1));
//		}
//		cout <<"\n";
		cout <<  *min_element(B.begin(), B.end()) - *max_element(A.begin(), A.end()) << "\n";
		
	}
    return 0;
}

