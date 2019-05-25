/*
 * Author : Jatin Rohilla
 * Date   : 8-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> res;

    int i=0;
    int j=0;

    while(i<A.size() && j<B.size()){
        if(A[i]==B[j]){
            res.push_back(A[i]);
            i++;
            j++;
        }
        else if(A[i] < B[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return res;
}

int main(){

	vector<int> A = {1,2,3,3,4,5,6};
	vector<int> B = {3,3,5};

	vector<int> res = intersect(A, B);
	for(auto it : res){
		cout << it << " ";
	}
    return 0;
}

