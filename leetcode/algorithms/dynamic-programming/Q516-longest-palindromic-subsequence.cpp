/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;

        int n = s.length();
        vector<int> prevRow(n+1, 0);
        vector<int> currRow(n+1, 0);

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(s[i-1]==s[n-j]){
                    currRow[j] = 1 + prevRow[j-1];
                }
                else{
                    currRow[j] = max(prevRow[j], currRow[j-1]);
                }

            }
            // for(auto it : currRow) cout << it << " "; cout << "\n";
            prevRow = currRow;
        }
        return currRow[n];
    }
};


