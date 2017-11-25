/*
 * Compiler : g++ 5.1.0
 * flags : -std=c++11
 *
 * objective : reversing nested lists
 */


#include<iostream>
#include <vector>
using namespace std;

// vector passed as reference to save memory
vector<vector<int> > performOps(vector<vector<int> > &arr)
 {
    vector<vector<int> > B;
    B.resize(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        B[i].resize(arr[i].size());
        for (int j = 0; j < arr[i].size(); j++) {
            B[i][arr[i].size() - 1 - j] = arr[i][j];
        }
    }
    return B;
}

int main()
{
	vector<vector<int> > arr ({{1, 2, 3, 4},
                           {5, 6, 7, 8},
                           {9, 10, 11, 12}});

	vector<vector<int> > B = performOps(arr);

	for (int i = 0; i < B.size(); ++i)
	{
    	for (int j = 0; j < B[i].size(); ++j){
    	  cout<<B[i][j]<<" ";
        } 
        cout<<"\n";
	}

	return 0;
}
