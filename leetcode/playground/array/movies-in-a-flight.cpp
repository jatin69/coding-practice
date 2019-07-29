/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> findMinDiff_sort(vector<int>& movies, int target){

    // method 1 sort
    sort(begin(movies), end(movies));
    int i = 0;
    int j = movies.size()-1;
    int minDiff = INT_MAX, minOne = -1, minTwo = -2;
    while(i < j){
        int diff = target -( movies[i] + movies[j]);
        if(diff == 0){
            return {movies[i], movies[j]};
        }
        if(diff > 0){
            i++;
        }
        else{
            j--;
        }
        if(diff < minDiff){
            minDiff = diff;
            minOne = movies[i];
            minTwo = movies[j];
        }
    }
    return {minOne, minTwo};
}

int main() {
    vector<int> movies = { 2,3,5,1,11,7,2,8};
    int d = 9;
    vector<int> result = findMinDiff_sort(movies, d);
    for(auto it : result){
        cout << it << " ";
    }
}

