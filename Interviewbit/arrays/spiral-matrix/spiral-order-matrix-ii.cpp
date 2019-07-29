/*
 * Author : Jatin Rohilla
 * Date   : 4-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/spiral-order-matrix-ii/
 */


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int A) {
    vector<vector<int>> res(A, vector<int>(A, 0));

    int count = A*A;
    int val = 0;

    int direction = 1;
    int begin = 0;
    int end = A-1;

    int r=0, c=0;

    while(val < count){
        // cout << "val is "<< val << " ";
        switch(direction){
            case 1:{    // left
                while(c <= end){
                    res[r][c] = ++val;
                    c++;
                }
                c--;
                r++;
                direction = 2;
            }break;
            case 2:{    // down
                while(r <= end){
                    res[r][c] = ++val;
                    r++;
                }
                r--;
                c--;
                direction = 3;
            }break;
            case 3:{    // right
                while(c >= begin){
                    res[r][c] = ++val;
                    c--;
                }
                c++;
                r--;
                direction = 4;
            }break;
            case 4:{    // up
                while(r > begin){
                    res[r][c] = ++val;
                    r--;
                }
                r++;
                c++;
                direction = 1;

                begin++;
                end--;
            }break;
        }
    }
    return res;
}

int main(){

	int A = 3;
	vector<vector<int>> res =generateMatrix(A);
	
	for(auto row : res){
		for(auto cell : row){
			cout << cell << " ";
		}
		cout << "\n";
	}

    return 0;
}

