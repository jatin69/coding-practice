/*
 * Author : Jatin Rohilla
 * Date   : 09/06/2018, 5-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question : https://www.interviewbit.com/problems/largest-number/
 * solution accepted.
 * Approach - A modified type of radix sort
 */


#include<bits/stdc++.h>
using namespace std;

bool compfunction (int m,int n) {
    char* pEnd;
    string i = to_string(m) + to_string(n);
    string j = to_string(n) + to_string(m);
    return strtoll(i.c_str(), &pEnd, 10) > strtoll(j.c_str(), &pEnd, 10);
}

string largestNumber_old(const vector<int> &_A) {
    vector <int> A = _A;
    std::sort(A.begin(),A.end(), compfunction);
    string res = "";
    for(int i=0;i<A.size();++i){
        res.append(std::to_string(A[i]));
    }

    if(res[0]=='0'){
        res = '0';
    }

    return res;
}

bool comparator(string a, string b){
    return a+b > b+a;
}

string largestNumber(const vector<int> &A) {
    vector<string> nums;
    for(auto it : A){
        nums.push_back(to_string(it));
    }
    sort(nums.begin(), nums.end(), comparator);
    string res = "";
    for(auto it : nums){
        res += it;
    }

    if(res[0]=='0'){
        res = '0';
    }

    return res;
}

int main(){

	vector <int> A={
//	3, 30, 34, 5, 9
0, 0, 0, 0, 0
	};
	
	cout<< largestNumber(A);

    return 0;
}

