#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t, n, k, ele;;
	cin>>t;
	
	while(t--){
		vector<int> A;
		cin >> n >> k;
		for(int i=0;i<n;++i){
			cin>>ele;
			A.push_back(ele);
		}
		
		sort(A.begin(), A.end(), greater<int>());

		int count = 0;
		for(int i=0;i<n;++i){
			if(A[i] >= A[k-1]){
				count++;
			}
			else{
				break;
			}
		}

		cout << count << "\n";
	}
}
