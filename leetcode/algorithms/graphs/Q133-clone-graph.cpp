/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    void fillMap(Node* root, unordered_map<Node*, Node*>& m){
        if(!root){
            return;
        }
        if(m.find(root)!=m.end()){
            return;
        }
        m[root] = new Node(root->val);
        for(auto adjacent : root->neighbors){
            fillMap(adjacent, m);
        }
    }

    void connectNodes(Node* root, unordered_map<Node*, Node*>& m){
        if(!root){
            return;
        }

        for(auto adjacent : root->neighbors){
            auto vec = m[root]->neighbors;
            if(std::find(vec.begin(), vec.end(), m[adjacent])==vec.end()){
                (m[root]->neighbors).push_back(m[adjacent]);
            }
            vec = m[adjacent]->neighbors;
            if(std::find(vec.begin(), vec.end(), m[root])==vec.end()){
                connectNodes(adjacent, m);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        fillMap(node, m);
        connectNodes(node, m);
        return m[node];
    }
};

