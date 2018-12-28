/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

ques - https://leetcode.com/problems/two-sum/description/
Return indexes of two elements which add up to target sum


approach -
1. 2 pointers -> needs sorting
But sorting will distort indexes, so can't use

2. Simple hashmap (unordered_set) only stores elements, cant find index.

3. We use unordered_map here. pair of <element, index>

Accepted.
 
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& A, int target) {

    unordered_map<int,int> s ;
    unordered_map<int,int>::iterator it;

    for(int i=0;i<A.size();++i){

        int ele = target -  A[i];
        it = s.find(ele);
        if(it!=s.end()){
            int j = it->second;
            return vector<int>({ j, i });
        }

        s.insert(make_pair(A[i],i));

    }

    return vector<int>();
}

int main(){

	vector<int> A = {
		3,2,4
	};
	
	int reqSum = 6;
	
	vector<int> res = twoSum(A,reqSum);
	cout << "(" << res[0] << ", " << res[1] << ")" <<endl;

    return 0;
}

