/*
 * Author : Jatin Rohilla
 * Date   : 08-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/max-continuous-series-of-1s/
 *
 * approach - two pointers. sliding window.
 *
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> maxone(vector<int> &A, int B) {

    int flips = B;
    int maxWindowLeftBoundary = -1, maxWindowRightBoundary = -1;
    int windowLeftBoundary = 0, windowRightBoundary = 0;

    while( windowRightBoundary < A.size()){

        if(A[windowRightBoundary]==1){
        	// nothing todo, simply let the boundary expand
            windowRightBoundary++;
        }
        else if(A[windowRightBoundary]==0){

			if(flips > 0){
				// compensate from allowed flips
                flips--;
                windowRightBoundary++;
            }
            else{
            	// no more flips available
            	
                if(A[windowLeftBoundary]==0){
                	// extract one flip from left side
                    windowLeftBoundary++;
                    windowRightBoundary++;
                }
                else if(A[windowLeftBoundary]==1){
                	// cannot extract from left, right cannot move forward
                    windowLeftBoundary++;
                }
            }
        }

        // is current windows greater than maxWindow
        if((windowRightBoundary - windowLeftBoundary) > (maxWindowRightBoundary - maxWindowLeftBoundary)){
            maxWindowLeftBoundary = windowLeftBoundary;
            maxWindowRightBoundary = windowRightBoundary;
        }
    }

    vector<int> res;
    for(int i=maxWindowLeftBoundary; i<maxWindowRightBoundary; ++i){
        res.push_back(i);
    }
    return res;
}

int main(){

	vector<int> A = { 1,1,0,1,1,0,0,1,1,1 };
	int B = 1;
	
//	vector<int> A = {1,1,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1};
//	int B = 2;

	vector<int> res =maxone(A, B);
	for(auto it : res){
		cout << it << " ";
	}
	cout << "\n";

    return 0;
}

