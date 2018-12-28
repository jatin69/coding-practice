#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	vector<int> B(n);

	for(int i=0;i<n;++i){
		cin>>A[i];
		B[i] = A[i];
	}
	
	int count = 0;
	vector<int> C;
	bool goforit = false;
	do{
		goforit = false;
		A = B;
		B = C;
		sort(A.begin(), A.end());
		for(int i = 1; i<A.size(); ++i){
			if(A[i]==A[i-1]){
				B.push_back(A[i]);
				A.erase(A.begin() + i-1);
			}
		}

		for(int i=1;i<A.size();++i){
			if(A[i] > A[i-1]){
				count++;
			}
		}
		
		for(int i=1; i<B.size(); ++i){
			if(A[i]!=A[i-1]){
				goforit = true;
			}
		}
		
		if(!goforit || B.empty()){
			B = C;
		}
		
	}while(!B.empty());
	
	cout << count << "\n";
	
    return 0;
}

