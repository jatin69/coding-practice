/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


struct TrieNode{
    /* Unordered map is used because,
       this will support trie of lowercase + uppercase + digits
       This is better than array.
    */
    unordered_map<char, TrieNode*> childMap;
    bool isWord = false;

    TrieNode(){

    }

    ~TrieNode(){
        for(auto child : childMap){
            delete child.second;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* trav = root;
        for(auto ch : word){
            if(trav->childMap.find(ch) == trav->childMap.end()){
                trav->childMap[ch] = new TrieNode();
            }
            trav = trav->childMap[ch];
        }
        trav->isWord = true;
    }

    TrieNode* find(string& prefix){
        TrieNode* trav = root;
        for(auto ch : prefix){
            if(trav->childMap.find(ch) == trav->childMap.end()){
                trav = nullptr;
                break;
            }
            trav = trav->childMap[ch];
        }
        return trav;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* match = find(word);
        return match!=nullptr && match->isWord==true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* match = find(prefix);
        return match!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
