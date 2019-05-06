/*
 * Author : Jatin Rohilla
 * Date   : 30-4-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 https://www.interviewbit.com/problems/maxspprod/
 https://www.geeksforgeeks.org/maximum-product-of-indexes-of-next-greater-on-left-and-right/
 https://www.geeksforgeeks.org/next-greater-element/
 */


#include<bits/stdc++.h>
using namespace std;

int maxSpecialProduct(vector<int> &A) {
	
    int n = A.size();
    vector<pair<unsigned long long int,unsigned long long int>> specialValues(n);

	// NEXT GREATER on the right side : usual case
    stack<int> rightStack;
    rightStack.push(0);
    for(int i=1;i<n;++i){
        while(!rightStack.empty() && A[i] > A[rightStack.top()]  ){
            specialValues[rightStack.top()].second = i;
            rightStack.pop();
        }
        rightStack.push(i);
    }
    while(!rightStack.empty()){
        specialValues[rightStack.top()].second = 0;
        rightStack.pop();
    }

	// NEXT GREATER ON THE LEFT SIDE
	stack<int> leftStack;
    leftStack.push(n-1);
    for(int i=n-2;i>=0;--i){
        while(!leftStack.empty() && A[i] > A[leftStack.top()] ){
            specialValues[leftStack.top()].first = i;
            leftStack.pop();
        }
        leftStack.push(i);
    }

    while(!leftStack.empty()){
        specialValues[leftStack.top()].first = 0;
        leftStack.pop();
    }

    
    unsigned long long int res = 0;

    for(auto it : specialValues){
        res = max( res, it.first * it.second);
        // res = it.first * it.second;
        // cout << "{" << it.first << ", " << it.second << ", res : " << res << "}  ";
    }
    // cout << "\n";

    return res%1000000007;
}
int main(){

	vector<int> A = {
		5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9     // 80
	} ;
	cout <<maxSpecialProduct(A);

    return 0;
}

