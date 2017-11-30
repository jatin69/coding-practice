/*
 * Author : Jatin Rohilla
 * Date   : 01/12/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */
 
#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	int curr,prev,pred,total;
	int n;
	while(t--){
	    cin>>n;
	    vector<int> A(n);
	    for(int i=0;i<A.size();++i){
	        cin>>A[i];
	    }
	    pred=0;
	    total=0;
    	prev=A[0];
    	total=max(pred,prev);

    	for(int i=1;i<A.size();++i){
    		curr=A[i];
    		total=max(curr+pred,prev);
    		pred=prev;
    		prev=total;
    	}

    	cout << total << "\n";

	}
	return 0;
}
