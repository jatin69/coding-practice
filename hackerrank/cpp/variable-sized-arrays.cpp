/*
 * Author : Jatin Rohilla
 * Date   : 4/12/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */
 /*
 test case
2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    int q;
    cin>>q;
    int k;
    int ele;
    for(int i=0;i<n;++i){
        cin>>k;
        for(int j=0;j<k;++j){
			cin>>ele;
            a[i].push_back(ele);
        }
    }

    int i,j;
    while(q--){
     cin>>i>>j;
     cout<<a[i][j]<<"\n";
    }


    return 0;
}

