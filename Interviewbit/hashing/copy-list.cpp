/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode*, RandomListNode*> m;
    RandomListNode* trav;

    trav = A;
    while(trav){
        m[trav] = new RandomListNode(trav->label);
        trav = trav->next;
    }

    trav = A;
    while(trav){
        m[trav]->next = m[trav->next];
        m[trav]->random = m[trav->random];
        trav = trav->next;
    }
    return m[A];
}


