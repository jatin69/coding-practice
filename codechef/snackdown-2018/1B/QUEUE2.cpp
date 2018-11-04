#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(){

	int t;
	cin>>t;

	while(t--){

		lli n,m,k,l;
		cin>>n>>m>>k>>l;

		lli A[n+1];
		for(int i = 0;i < n;i++)
			cin>>A[i];

		A[n] = k;
		sort(A, A+n+1);

		lli minVal = LONG_MAX;
		lli sum = m * l;

		for(int i = 0; i <= n; ++i){
			minVal = min( minVal, sum + (i+1)*l - A[i] );
		}

		cout << minVal << "\n";

	}

	return 0;
}

