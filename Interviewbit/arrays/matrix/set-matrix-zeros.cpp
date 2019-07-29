/*
 * Author : Jatin Rohilla
 * Date   : 18/06/2018, 25-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

original link - https://www.interviewbit.com/problems/set-matrix-zeros/
Question - Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0. Do it in place

Similar question - https://www.geeksforgeeks.org/a-boolean-matrix-question/


approach -

use two flag variables to store status of 0th row and 0th column.
Now process matrix (m-1 * n-1) by reusing space of 0th row and 0th column as Aux space
At last, process 0th row and column using flags.
 */


#include<bits/stdc++.h>
using namespace std;


void setZeroes_newsession(vector<vector<int> > &A) {

    if(A.size()==0){
        return ;
    }
    int m = A.size();
    int n = A[0].size();


    // preprocess first row and column
    bool willFirstRowBeZero = false;
    bool willFirstColumnBeZero = false;

    if(willFirstRowBeZero==false){
        for(int j=0;j<n;++j){
            if(A[0][j]==0){
                willFirstRowBeZero = true;
                break;
            }
        }
    }

    if(willFirstColumnBeZero==false){
        for(int i=0;i<m;++i){
            if(A[i][0]==0){
                willFirstColumnBeZero = true;
                break;
            }
        }
    }

    // pre process matrix m-1 x n-1
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(A[i][j]==0){
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }

    // process matrix m-1 x n-1
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(A[i][0]==0 || A[0][j]==0){
                A[i][j] = 0;
            }
            else{
                A[i][j] = 1;
            }
        }
    }

    if(willFirstRowBeZero){
        for(int j=0;j<n;++j){
            A[0][j] = 0;
        }
    }

    if(willFirstColumnBeZero){
        for(int i=0;i<m;++i){
            A[i][0] = 0;
        }
    }

}


void setZeroes(vector<vector<int> > &A) {

	int R = A.size();
	int C = A[0].size();

	// flags to hold status of first row and column
	bool rowFlag = false;
	bool colFlag = false;
	
	// processing 0th row
	for(int j=0; j<C;++j){
		if(A[0][j] == 0){
			rowFlag = true;
			break;
		}
	}
	
	// processing 0th column
	for(int i=0;i<R;++i){
		if(A[i][0] == 0){
			colFlag = true;
			break;
		}
	}

	// processing matrix of size M-1 * N-1
	for(int i=1;i<R;++i){
		for(int j=1; j<C;++j){
			if(A[i][j]==0){
				A[0][j] = 0;        
				A[i][0] = 0;
			}
		}
	}
	
	// Modifying the matrix of size M-1 * N-1
	for(int i=1;i<R;++i){
		for(int j=1; j<C;++j){
			if(A[i][0] == 0 || A[0][j] == 0 ){
				A[i][j] = 0;
			}
		}
	}
	
	// modifying the 0th row if needed
	if(rowFlag){
		for(int j=0;j<C;++j){
				A[0][j]=0;
		}
	}

	// modifying the 0th column if needed
	if(colFlag){
		for(int i=0; i<R; ++i){
				A[i][0]=0;
		}
	}
	
}


int main(){

	vector<vector<int>> A = {
		{1,0,1},
		{1,1,1},
		{1,1,1}

//		{1,1},
//		{0,1},
//		{0,1}
	};


	setZeroes(A);
	cout << "\n";
	for(int i=0;i<A.size();++i){
		for(int j=0; j<A[i].size();++j){
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}


    return 0;
}

