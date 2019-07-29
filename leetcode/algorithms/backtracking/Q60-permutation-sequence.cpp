/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here
class Solution {
public:
    void getNextPermutation(string& s){
        int i = s.length()-2;
        // 132
        while(i>=0 && s[i] >= s[i+1]){ i--; }
        if(i>=0){
            int j = s.length()-1;
            while(j>=0 && s[j] <= s[i] ){ j--; }
            swap(s[i], s[j]);
        }
        reverse(s.begin() + i + 1, s.end());
    }

    string getPermutation(int n, int k) {
        string seq;
        for(int i=1; i<=n; ++i){
            seq += to_string(i);
        }
        k = k-1;
        while(k--){
            getNextPermutation(seq);
        }
        return seq;
    }
};

// there also exists a more efficient math solution.


int main(){

	cout<<"Hello World";

    return 0;
}

