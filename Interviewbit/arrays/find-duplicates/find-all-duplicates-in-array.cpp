/*
 * Author : Jatin Rohilla
 * Date   : 10/06/18
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * NOTE : It is allowed to modify array.
 * same approach as -> find the duplicate element in array
 *
 * Time : Order N
 * Space : order 1
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(vector<int> &A) {
	vector<int> res;

 for(int i=0;i<A.size();++i){
    	if( A[ abs(A[i]) -1 ] > 0){
		 A[ abs(A[i]) -1 ] *= -1;
		}
		else{
			res.push_back(abs(A[i]));
		}
    }

    if(res.size()==0){
		res.push_back(-1);
	}
	return res;
}


int main(){

	vector<int> A = { 1, 2, 3, 1, 3, 6, 6};
	vector <int> repeatedList = repeatedNumber(A);
	if(repeatedList[0]==-1){
		cout<<"No repeated element found";
	}
	else{
	 for(int i=0;i<repeatedList.size();++i){
		cout << repeatedList[i] << " ";
	}


	}
	    return 0;
}

