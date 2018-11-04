/*
 * Author : Jatin Rohilla
 * Date   :  3-11-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<bits/stdc++.h>
using namespace std;

void printVectorPair(vector<pair<int,int>> A){

	cout << "\nPrint : \n";
	for(int i=0; i<A.size(); ++i) {
		cout << A[i].first << "  " << A[i].second << "\n";
	}
	cout << "\n\n";
}

bool myfunc(pair<int,int> a, pair<int,int> b){
	return a.first < b.first ;
}

struct compare {
    bool operator()(const pair<int, int>& value, const int& key){
	        return (value.first < key);
    }
    bool operator()(const int& key, const pair<int, int>& value){
        return (key < value.first);
    }
};

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> A(n);
		vector<int> B(n);
		int ele;
		for(int i=0;i<n;++i){
			cin >> ele;
			A[i] = make_pair(ele, i+1);
			B[i] = ele;
		}

//		printVectorPair(A);
		sort(A.begin(), A.end(), myfunc);
//		printVectorPair(A);

		bool found = false;

		for(int i=0;i<n-1;++i){

			// probable answer
			if(A[i].first == A[i+1].first ){

//				cout << "i is " << A[i].second << "  and i+1 is " << A[i+1].second << " \n";

				if(binary_search (A.begin(), A.end(), A[i].second , compare()) && binary_search (A.begin(), A.end(),  A[i+1].second, compare()) ){

					if(B[A[i].second] != B[A[i+1].second]) {
						found = true;
						break;
					}

//					int x = (lower_bound(A.begin(), A.end(), make_pair(A[i].second, INT_MIN)) - A.begin());
//					int y = (lower_bound(A.begin(), A.end(), make_pair(A[i+1].second, INT_MIN)) - A.begin());

				}
			}
		}

		if(found){
			cout << "Truly Happy\n";
		}
		else{
			cout << "Poor Chef\n";
		}
	}

    return 0;
}

