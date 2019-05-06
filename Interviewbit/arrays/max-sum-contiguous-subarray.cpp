/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    vector<int> maxSum(A.size());
    vector<int> relatedIndex(A.size());
    int i;

    i=0;
    maxSum[i] = A[i];
    relatedIndex[i] = i;
    for(i=1; i<A.size(); ++i){
        maxSum[i] = A[i] + max(0, maxSum[i-1]);
        relatedIndex[i] = maxSum[i-1]>0 ? i-1 : i;
    }

    i = 0;
    int maxValueIndex = i;
    for(i=1; i<maxSum.size(); ++i){
        if(maxSum[i] > maxSum[maxValueIndex]) {
            maxValueIndex = i;
        }
    }
    // displaying the maxSum array
    for(auto it : maxSum){ cout << it << " "; } cout << "\n\n";

    // generate subset
	vector<int> maxSubset;
	int currentMaxIndex = maxValueIndex;
    while(1){
        maxSubset.push_back(A[currentMaxIndex]);
        if( currentMaxIndex == relatedIndex[currentMaxIndex]){
            break;
        }
        else{
            currentMaxIndex = relatedIndex[currentMaxIndex];
        }
    }

    // display the found max subset
    reverse(maxSubset.begin(), maxSubset.end());
    for(auto it : maxSubset){ cout << it << " "; } cout << "\n";

    return maxSum[maxValueIndex];
}


int main(){

	vector<int> A = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << maxSubArray(A);

    return 0;
}

