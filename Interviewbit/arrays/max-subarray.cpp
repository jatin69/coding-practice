/*
 * Author : Jatin Rohilla
 * Date   : 3-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * similar to max-non-negative-subarray
 */


#include<bits/stdc++.h>
using namespace std;

// DP : max value using min elements
vector<int> maxset_including_negatives(vector<int> &A) {
	// initialise 2D array
    vector<vector<long long int>> B(A.size(), vector<long long int>(A.begin(), A.end()));


 cout << "\n\n";
    for(auto x : B ){
        for(auto it : x){
            cout << it << " ";
        }
        cout << "\n";
    }
	// make DP solution
	for(int start=0; start<B.size(); ++start){
		for(int i = start+1; i<B[start].size(); ++i){
			B[start][i] = max(B[start][i] + B[start][i-1], B[start][i]);
		}
    }

 cout << "\n\n";
    for(auto x : B ){
        for(auto it : x){
            cout << it << " ";
        }
        cout << "\n";
    }

	// find max
	long long int maxValue = B[0][0];
	int maxValueRow = 0, maxValueColumn = 0;
	bool isGreater = false;

	for(int i=0; i<B.size(); ++i){
		for(int j=i; j<B[i].size(); ++j){
			isGreater = false;

			// strictly greater
			if(B[i][j] > maxValue){
				isGreater = true;
			}

			// tie : choose smaller segment length
			if(B[i][j]==maxValue && (j-i+1) < (maxValueColumn-maxValueRow+1)){
				isGreater = true;
			}

			// tie and same segment length : choose smaller starting index
			if(B[i][j]==maxValue && (j-i+1) == (maxValueColumn-maxValueRow+1) && i<maxValueRow){
				isGreater = true;
			}

			if(isGreater){
				maxValue = B[i][j];
				maxValueRow = i;
				maxValueColumn = j;
			}
		}
	}

	cout << "max val : " << maxValue << ", max row : " << maxValueRow << ", max col : " << maxValueColumn << "\n";

	vector<int> res;
	for(int i = maxValueRow; i<=maxValueColumn; ++i){
		res.push_back(A[i]);
	}

	return res;

}


int main(){

	vector<int> A =  {
	1, 2, 5, -7, 2, 5
//	1, 2, 5, -7, 2, 6
//	1967513926, 1540383426, -1303455736, -1967513926
//	10, 20, -40 , -50
//	-1, -2, 33, -3
	};

	vector<int> res = maxset_including_negatives(A);
//	vector<int> res = maxset(A);
	for(auto it: res){
		cout << it << " " ;
	}

    return 0;
}

