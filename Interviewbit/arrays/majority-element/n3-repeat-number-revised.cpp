/*
 * Author : Jatin Rohilla
 * Date   : 06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/n3-repeat-number/
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::repeatedNumber(const vector<int> &A) {
    int k = 3;
    vector<pair<int, int>> candidates(k-1, {-1, 0});

    for(auto ele : A){
        bool processed = false;

        // 1. if found, increment its count
        for(auto& candidate : candidates){
            if(candidate.second > 0){
                if(candidate.first == ele){
                    candidate.second++;
                    processed = true;
                    break;
                }
            }
        }

        // 2. find a space to live
        if(!processed){
            for(auto& candidate : candidates){
                if(candidate.second == 0){
                    candidate.first = ele;
                    candidate.second = 1;
                    processed = true;
                    break;
                }
            }
        }

        // 3. decrement everyone's count
        if(!processed){
            for(auto& candidate : candidates){
                candidate.second--;
            }
        }
    }

    // verify the candidates
    int validCandidate = -1;
    for(auto& candidate : candidates){
        if(candidate.second > 0){
            int count = 0;
            for(auto ele : A){
                if(candidate.first == ele){
                    count++;
                }
            }
            if(count > (A.size()/3)){
                validCandidate = candidate.first;
                break;
            }
        }
    }
    return validCandidate;
}

int main(){

	cout<<"Hello World";

    return 0;
}

