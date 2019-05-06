/*
 * Author : Jatin Rohilla
 * Date   : 3-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/courses/programming/topics/strings/
 */


#include<bits/stdc++.h>
using namespace std;

int atoi(const string A) {
    string s = "";
    int i = 0;

    // trim starting spaces
    while(A[i]==' '){
        i++;
    }

    bool isNegative = false;

    // find out if number is negative
    if(A[i]=='-'){
        isNegative = true;
        i++;
    }
    else if(A[i]=='+'){
        isNegative = false;
        i++;
    }

    // remove starting 0's
    while(A[i]=='0'){
        i++;
    }

    // break at space
    while(i<A.length()){
        if(A[i] >= '0' && A[i] <= '9'){
            s+=A[i];
        }
        else{
            break;
        }
        i++;
    }

    // still empty
    if(s==""){
        return 0;
    }

    // s is now to be converted
    int n = s.length();

    if((n>10) || (n==10)&&s[0]>'2' ){
        if(isNegative){
            return INT_MIN;
        }
        else{
            return INT_MAX;
        }
    }

    int res = 0;
    for(int i=n-1; i>=0; --i){
        res += (s[i]-'0')*pow(10, n-1-i);
    }

    if(isNegative){
        res *= -1;
    }

    return res;
}


int main(){

	string A;

	A = "      trt43";
	cout <<atoi(A) << "\n";

	A = "-  54";
	cout <<atoi(A) << "\n";

	A = "-00043";
	cout <<atoi(A) << "\n";

	A = "-3";
	cout <<atoi(A) << "\n";

	A = "+7";
	cout <<atoi(A) << "\n";

	A = "+7345345345345345 3534 63 ggbv et35t4";
	cout <<atoi(A) << "\n";

	A = "3555+7";
	cout <<atoi(A) << "\n";

	A = "-244444444444443555+7";
	cout <<atoi(A) << "\n";

	A = "-24 4444444444443555+7";
	cout <<atoi(A) << "\n";

    return 0;
}

