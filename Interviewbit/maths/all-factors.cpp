/*
 * Author : Jatin Rohilla
 * Date   : 26/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : find all factors of a number N - order root(N)
 */


#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> allFactors(int A) {
    vector<int> res;

    int limit=sqrt(A);
    for(int i=1;i<=limit;++i){
        if(A%i == 0){
            res.push_back(i);
        }
    }
    limit=res.size()-1;
    if((A/res.at(limit))!=(res.at(limit))){
        res.push_back(A/res.at(limit));
    }
    for(int i=limit-1;i>=0;--i){
        res.push_back(A/res.at(i));
    }
    return res;
}

int main(){

	int num=32;
	vector<int> res;
	res=allFactors(num);

	for(int i=0;i<res.size();++i){
		cout<<res[i]<<" ";
	}

    return 0;
}

