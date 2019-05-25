/*
 * Author : Jatin Rohilla
 * Date   : 09-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/palindrome-string/
 */


#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string A) {
    int i=0;
    int j=A.length()-1;

    while(i<j){

        if(!isalnum(A[i])){
            i++;
            continue;
        }
        if(!isalnum(A[j])){
            j--;
            continue;
        }

        if(tolower(A[i])!=tolower(A[j])){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main(){

	string s =
	"A man, a plan, a canal: Panama";
// 	"race a car";

	cout << isPalindrome(s);
	
	

    return 0;
}

