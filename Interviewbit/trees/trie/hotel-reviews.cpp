/*
 * Author : Jatin Rohilla
 * Date   : 16-06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/hotel-reviews/
 */


#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isWord{false}, children{} {}
    ~TrieNode(){
        for(auto child : children){
            delete child.second;
        }
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    ~Trie(){
        delete root;
    }
    void insert(string& word){
        TrieNode* trav = root;
        for(auto ch : word){
            if(trav->children.find(ch) == trav->children.end()){
                trav->children[ch] = new TrieNode();
            }
            trav = trav->children[ch];
        }
        trav->isWord = true;
    }
    bool findWord(string& word){
        TrieNode* trav = root;
        for(auto ch : word){
            if(trav->children.find(ch) == trav->children.end()){
                return false;
            }
            trav = trav->children[ch];
        }
        return trav->isWord;
    }
};

vector<int> Solution::solve(string A, vector<string> &B) {

    if(B.size()==0){
        return {};
    }

    // make a trie of good words
    Trie t;
    std::stringstream ss(A);
    string goodWord;
    while(getline(ss, goodWord, '_')){
        t.insert(goodWord);
    }

    // count no of good words in each review
    // pair of frequency and original index
    vector<pair<int, int>> vec;
    for(int i=0; i<B.size(); ++i){

        // count no of good words in review
        int count = 0;
        std::stringstream sw(B[i]);
        string word;
        while(getline(sw, word, '_')){
            if(t.findWord(word)){
                count++;
            }
        }

        // insert in vec
        vec.push_back({count, i});
    }

    // sort vec based on frequencies
    sort(vec.begin(), vec.end(), [](pair<int, int> p1, pair<int, int> p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    });


    // form the resultant array from vec
    vector<int> res;
    for(auto it : vec){
        res.push_back(it.second);
    }

    return res;
}


int main(){

	cout<<"Hello World";

    return 0;
}

