/*
 * Author : Jatin Rohilla
 * Date   : 3-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

// BASIC
vector<int> maxset(vector<int> &A) {

    long long int maxVal = -1;
    int maxStart = 0;
    int maxEnd = 0;


    for(int i=0; i< A.size(); ++i){

        int currStart = i;
        long long int currVal = 0;
        while(i<A.size() && A[i]>=0){
            currVal += A[i];
            i++;
        }
        int currEnd = i-1;
        

        bool isGreater = false;

//		cout << "currStart : " << currStart << " and currEnd : " << currEnd << " and currval " << currVal << " and maxVal is "<< maxVal <<" \n" ;

		// strictly greater
        if(currVal > maxVal){
//		    cout << "case 1" << "\n";
            isGreater = true;
        }

        // tie : choose greater segment length
        else if(currVal == maxVal && (currEnd - currStart + 1) > (maxEnd - maxStart+ 1)){
//		    cout << "case 2" << "\n";
			isGreater = true;
        }

        else if(currVal == maxVal && (currEnd - currStart+ 1) > (maxEnd - maxStart+ 1) && currStart < maxStart){
//            cout << "case 3" << "\n";
			isGreater = true;
        }

        if(isGreater){
//          	cout << "maxStart : " << maxStart << " and maxEnd : " << maxEnd << " ";
			maxVal = currVal;
            maxStart = currStart;
            maxEnd = currEnd;
        }

    }

    vector<int> res;
    for(int i = maxStart; i<=maxEnd; ++i){
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
	
//	vector<int> res = maxset_including_negatives(A);
	vector<int> res = maxset(A);
	for(auto it: res){
		cout << it << " " ;
	}

    return 0;
}

