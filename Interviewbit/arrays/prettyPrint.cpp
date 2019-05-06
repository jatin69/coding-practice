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

void print2D(vector<vector<int>> res){
	for(auto row : res){
		for(auto cell : row){
			cout << cell << " ";
		}
		cout << "\n";
	}
}

vector<vector<int>> prettyPrint(int A) {
    int rows = 2*A -1;
    int columns = 2*A -1;
    vector<vector<int>> res(rows, vector<int>(columns, 0));
    int count = rows * columns;

    int direction = 1;
    int val = A;
    int begin=0;
    int end=columns-1;
    int r = 0;
    int c = 0;

    while(count){
    	switch(direction){
            case 1:{    // left
                while(c <= end){
                    res[r][c] = val;
                    c++;
                    count--;
                }
                c--;
                r++;
                direction = 2;
            }break;
            case 2:{    // down
                while(r <= end){
                    res[r][c] = val;
                    r++;
                    count--;
                }
                r--;
                c--;
                direction = 3;
            }break;
            case 3:{    // right
                while(c >= begin){
                    res[r][c] = val;
                    c--;
                    count--;
                }
                c++;
                r--;
                direction = 4;
            }break;
            case 4:{    // up
                while(r > begin){
                    res[r][c] = val;
                    r--;
                    count--;
                }
				r++;
                c++;

                // switch to new location
                begin++; end--;
                direction = 1;
                val--;
            }break;
        }
    }
    return res;
}

int main(){

	int A = 2;
	vector<vector<int>> res = prettyPrint(A);
	print2D(res);
    return 0;
}

