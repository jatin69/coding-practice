/*
 * Author : Jatin Rohilla
 * Date   : 1/12/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Related problem : find-maximum-possible-stolen-value-houses
 *
 */


#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<int> A={50,5,10,100,10,50};
	
	int curr,prev,pred,max_val;
	
	pred=A[0];
	prev=max(A[0],A[1]);
	max_val=max(pred,prev);
	
	for(int i=2;i<A.size();++i){
		curr=A[i];
		max_val=max(curr+pred,prev);
		pred=prev;
		prev=max_val;
	}

	cout << max_val << "\n";


	/*
	// Nice approach. But size can be minimised.
	
	int count[A.size()];

	if(A.size()==1){
		cout<< A[0] << "\n";
		return 0;
	}

	count[0]=A[0];
	count[1]=max(A[0],A[1]);
	
	int i;
	for(i=2;i<A.size();++i){
		count[i]=max(count[i-2]+A[i],count[i-1]);
	}
	cout << count[i-1] << "\n";
	*/
    return 0;
}

