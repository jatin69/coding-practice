/*
 * Author : Jatin Rohilla
 * Date   : 27-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pat){

    int n = pat.length();
    int i = 0;
    int j = 0;
    vector<int> lps(n);

    lps[0] = 0;
    i++;

    while(i<n){
        if(pat[i]==pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j==0){
                lps[i] = 0;
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    return lps;
}


int solve(string A) {
    string rev(A);
    reverse(rev.begin(), rev.end());
    string s = A + '$' + rev;
    vector<int> res = computeLPS(s);
    return (A.length() - res.back());
}

int solve_editorial(string A) {
    int start = 0 , end = A.length()-1;
    int temp_end = end;
    /*Idea is to find longest palindrome length starting from index 0 . Differece of
    this length from string length is the required value*/
    while(start<=temp_end)
    {
        if(A[start]==A[temp_end])
        {
            start++;
            temp_end--;
        }
        else
        {
            start = 0;
            temp_end = --end;
        }
    }
    return A.length()-(end+1);
}

int main(){

	string s = "AACECAAAA"; // 2
	cout << solve(s);
	
    return 0;
}

