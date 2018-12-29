/*
test case
7
10 40 30 70 10 30 60

TLE
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main() {

    int n,ele;
    cin>>n;

    vector<int> A;

    int globalMIN = INT_MAX;

    for(int i=0;i<n;i++){
    	
    	cin>>ele;
        A.push_back(ele);
        if( ele < globalMIN){
        	globalMIN = ele;
		}
    }

//cout << "global MIIN is " << globalMIN << "\n";
    int currMAX, currSum = 0, currAREA = 0;
    int MAX_AREA = 0;
    int j;

    // for each rectangle
    for(int i=0;i<n;++i){

        currAREA = 0;

        // max allowed is itself, min allowed is MIN
        for(int k = A[i]; k>=globalMIN; k = k-globalMIN){
//        	cout << "f";
			
            currMAX = k;
            j=i;
            
            int jj = j;

            // curr sum -> area sum for this iteration
            currSum = 0;
            while(j<n){
                if(A[j] >= currMAX){
                    currSum += currMAX;
                    j++;
                }
                else{
                	break;
				}
            }
            // curr area -> area after ith rectangle
            currAREA = max(currAREA, currSum);

        }
//        cout << "current Possible AREA with " << i << " is " << currAREA << "\n";
        // max area -> area after all rectangles
        MAX_AREA = max(currAREA, MAX_AREA);
    }
    cout << MAX_AREA ;
    return 0;
}
