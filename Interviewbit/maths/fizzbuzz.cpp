/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


vector<string> Solution::fizzBuzz(int A) {
    int n = A;
    vector<string> res;
    string curr ;
    for(int i=1;i<=n;++i){
        if(i%3==0){
            if(i%5==0){
                curr = "FizzBuzz";
            }
            else{
                curr = "Fizz";
            }
        }
        else{
            if(i%5==0){
                curr = "Buzz";
            }
            else{
                curr = to_string(i);
            }
        }
        res.push_back(curr);
    }
    return res;
}
