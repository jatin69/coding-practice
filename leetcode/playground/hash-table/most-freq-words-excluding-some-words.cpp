/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

struct comp{
  bool operator()(const pair<int, string>& a, const pair<int, string>& b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    };
};

vector<string> kFreq(string text, vector<string> exclude){

    // make case insensitive and remove punctuations
    transform(text.begin(), text.end(), text.begin(), [](auto& ch) -> char {
        if(ispunct(ch)){ return ' '; }
        return std::tolower(ch);
    });
    cout << "Modified : \n" << text << "\n\n";

    // make a set of excluded words
    for(auto& s : exclude){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    unordered_set<string> exSet(begin(exclude), end(exclude));

    // parse text and count freq of each word
    istringstream ss(text);
    string str;
    map<string, int> mymap;
    while(getline(ss, str, ' ')){
        if(str == "") continue;
        if(exSet.find(str)!=exSet.end()) continue;
        mymap[str]++;
    }

    // make a max heap with frequency, string
    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
    for(auto it : mymap){
        pq.push({it.second, it.first});
    }

    // extract elements from max heap
    vector<string> res;
    int maxVal = pq.top().first;
    while(pq.top().first == maxVal){
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

int main() {
    string text = "Jack and Jill went to the market to buy bread and cheese. Cheese is Jack's and Jill's favorite food.";
    vector<string> wordsToExclude = { "and", "he", "the", "to", "is", "Jack","Jill"};

    vector<string> res = kFreq(text, wordsToExclude);
    cout << "Most frquent words excluding specified words : \n";
    for(auto it : res){
        cout << it << " ";
    }
    cout << "\n";
}

