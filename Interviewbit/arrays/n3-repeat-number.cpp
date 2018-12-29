/*
 * Author : Jatin Rohilla
 * Date   : 09/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question - https://www.interviewbit.com/problems/n3-repeat-number/
 * solution accepted
 */


#include<bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A) {

	int k = 3;
	int possibleCandidates = k-1;
	int requiredCount = A.size()/3;

	// variable initialisations not possible in many places
	//	int  candidate[possibleCandidates][possibleCandidates] = {0};
	int **candidate = new int*[possibleCandidates];
	for(int j=0;j<possibleCandidates;j++){
		candidate[j] = new int[possibleCandidates];
	}
	
	for(int j=0;j<possibleCandidates;j++){
		candidate[j][0]=0;
		candidate[j][1]=0;
	}
    // 0,0 => value
	// 0,1 => count
	
	bool actionRequired = true;
	bool processed = false;
	// traverse array
    for(int i=0;i<A.size();++i){
    	processed = false;
    	
    	// if element exists already, increase its count
		for(int j=0;j<possibleCandidates;j++){
			if(A[i]==candidate[j][0]){
				candidate[j][1]++;
				processed = true;
			}
		}
		
		// if not exist already, find a empty place and insert
		if(!processed) {
			for(int j=0;j<possibleCandidates;j++){
        		if(candidate[j][1]==0){
                	candidate[j][0] = A[i];
                	candidate[j][1]++;
                	processed = true;
               		break;
            	}
       		}
		}
		
		// if no empty place available, perform cleanup
		if(!processed) {
			for(int j=0;j<possibleCandidates;j++){
               candidate[j][1]--;
            }
		}
    }

    for(int j=0;j<possibleCandidates;j++){
        int count = 0;
        for(int i=0;i<A.size();++i){
            if(A[i]==candidate[j][0]){
                count++;
            }
        }
        if(count > (requiredCount)){
            return candidate[j][0];
        }
    }

    return -1;
}

int main(){

	vector<int> A = {
		1, 2, 3, 1, 1
//	  1000727, 1000727, 1000641, 1000517, 1000212, 1000532, 1000727, 1001000, 1000254, 1000106, 1000405, 1000100, 1000736, 1000727, 1000727, 1000787, 1000105, 1000713, 1000727, 1000333, 1000069, 1000727, 1000877, 1000222, 1000727, 1000505, 1000641, 1000533, 1000727, 1000727, 1000727, 1000508, 1000475, 1000727, 1000573, 1000727, 1000618, 1000727, 1000309, 1000486, 1000792, 1000727, 1000727, 1000426, 1000547, 1000727, 1000972, 1000575, 1000303, 1000727, 1000533, 1000669, 1000489, 1000727, 1000329, 1000727, 1000050, 1000209, 1000109
	};
	
	cout << repeatedNumber(A);

    return 0;
}

