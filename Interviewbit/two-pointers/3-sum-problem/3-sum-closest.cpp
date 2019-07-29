/*
 * Author : Jatin Rohilla
 * Date   : 9-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/3-sum/
 */


#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());

    int diff = INT_MAX;
    for(int i=0;i<A.size();++i){

        int j = 0;
        int k = A.size()-1;
        while(j < k){
            if(j==i){ j++; continue;}
            if(k==i){ k--; continue; }

            int currdiff = B-(A[j]+A[k]+A[i]);
            if(currdiff == 0)    { return B;  }
            if(currdiff > 0)     { j++;       }
            else if(currdiff < 0){ k--;       }

            if( abs(currdiff) < abs(diff) ){
                diff = currdiff;
            }

        }
    }

    return B-diff;
}

int main(){

	vector<int> A = { -1, 2, 1, -4};
	int target = 1;     // -1 + 1 + 2
	
//	vector<int> A = {
//		10, 1, 6, 10, -4, 1, -3, -10, -7, 10, -2, -5, 1, 7, -1, 7, -9, -7, 5, -2, 7, -1, -1, 10, 6, 0, -2, 9, 5, -9, 4, 8, 3, -6, -7, 0, 9, 3, 0, -10, 3, 7, -9, 10, -4, 7, 2, 1, -9, 3, 10, 4, 0, -2, -5, -4, 9, 10, 8, 7, 2, 1, 0, 3, 4, 7, 4, -3, 0, 8, -1
//	};
//	int target = -1;
	
	cout << threeSumClosest(A, target) << "\n";

    return 0;
}

