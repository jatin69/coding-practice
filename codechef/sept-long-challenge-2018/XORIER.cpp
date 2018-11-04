/*
 * Author : Jatin Rohilla
 * Date   : 9-9-18
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * https://www.codechef.com/SEPT18B/problems/XORIER
 */


#include<bits/stdc++.h>
using namespace std;

enum parity {even, odd};



bool isTargetPossible(int target, vector<int>& A){

	int i = 0;
	int j = lower_bound(A.begin(), A.end(), target) - A.begin();
	while(i<=j){
		if(A[i]+A[j]==target){
			return true;
		}
		if(A[i]+A[j]<target){
			i++;
		}
		else{
			j--;
		}
	}
	return false;
}

parity findParity(int n) {
	bool isEven = true;
	while(n){
		n = n&n-1;
		isEven = !isEven;
	}
	return isEven?even:odd;
}

void SieveOfEratosthenes(int n, vector<int>& oddParityPrimes, vector<int>& evenParityPrimes )
{
	bool prime[n+1];
	memset(prime, true, sizeof(prime));

	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}

	// store primes
	for (int i=2; i<=n; i++){
		if(prime[i]){
			if(findParity(i) == even){
				evenParityPrimes.push_back(i);
			}
			else{
				oddParityPrimes.push_back(i);
			}
		}
	}
}


int main(){

	// precompute primes & parities
	vector<int> oddParityPrimes;
	vector<int> evenParityPrimes;
	
	SieveOfEratosthenes(1048575, oddParityPrimes, evenParityPrimes);
	int t;
	cin>>t;
	int n,ele,k,xorValue,count;
	vector<int> A;
	while(t--){
		count = 0;
		cin>>n;
		k = n;
		while(k--){
			cin>>ele;
			A.push_back(ele);
		}
		
		for(int i=0;i<n-1;++i){
			for(int j=i+1; j<n;++j){
				
				xorValue = A[i]^A[j];
				if(isTargetPossible(xorValue, oddParityPrimes) || isTargetPossible(xorValue, evenParityPrimes)){
					count++;
				}
			}
		}
		
		cout << count << "\n";
	}

    return 0;
}

