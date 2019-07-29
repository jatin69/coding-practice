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
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void preorderNary(Node* root, vector<int>& res){
        if(!root){
            return;
        }
        res.push_back(root->val);
        for(Node* it: root->children){
            preorderNary(it, res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorderNary(root, res);
        return res;
    }
};

