/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::equal(vector<int> &A) {

    std::unordered_map<int, pair<int, int>> m;
    int currSum;
    int A1, B1, C1, D1;

    vector<int> res;
    for(int i=0; i<A.size(); ++i){
        for(int j=i+1; j<A.size();++j){
            auto it = m.find(A[i] + A[j]);
            if( it != m.end()){
                A1 = it->second.first;
                B1 = it->second.second;
                C1 = i;
                D1 = j;
                if(A1 < B1 && C1 < D1 && A1<C1 && B1!=D1 && B1!=C1){
                    vector<int> curr = {A1, B1, C1, D1};
                    if(res.size()==0){
                        curr = res;
                        continue;
                    }

                    bool shouldReplace = true;
                    for(int p=0; p<curr.size();++p){
                        if(curr[p] > res[p]){
                            shouldReplace = false;
                            break;
                        }
                    }
                    if(shouldReplace){
                        res = curr;
                        m[A[i] + A[j]] = {i, j};
                    }
                }
            }
            else{
                m[A[i] + A[j]] = {i, j};
            }
        }
    }

    return res;
}


