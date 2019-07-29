/*
 * Author : Jatin Rohilla
 * Date   : 16-06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/shortest-unique-prefix/
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
    string uniquePrefix(string& word){
        if(word == ""){
            return "";
        }

        string res = "";
        TrieNode* trav = root;
        int minRequiredLength = 1;

        for(int i=0; i<word.length(); ++i){
            res += word[i];
            if(trav->children.size()>1){
                minRequiredLength = i+1;
            }
            trav = trav->children[word[i]];

        }
        return word.substr(0, minRequiredLength);
    }
};

vector<string> Solution::prefix(vector<string> &A) {
    if(A.size()==0){
        return {};
    }
    Trie t;
    for(auto s : A){
        t.insert(s);
    }
    vector<string> res;
    for(auto s : A){
        res.push_back(t.uniquePrefix(s));
    }
    return res;
}


int main(){

	cout<<"Hello World";

    return 0;
}

