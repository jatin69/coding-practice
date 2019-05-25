/*
 * Author : Jatin Rohilla
 * Date   : 28/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * link - https://www.interviewbit.com/problems/intersection-of-linked-lists/
 */


#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode* temp;
    temp=A;
    int lenA=0;
    while(temp!=NULL){
        lenA++;
        temp=temp->next;
    }
    temp=B;
    int lenB=0;
    while(temp!=NULL){
        lenB++;
        temp=temp->next;
    }
    int d;
    if(lenA>lenB){
        d=lenA-lenB;
        for(int i=0;i<d;++i){
           A=A->next;
        }
    }
    else{
        d=lenB-lenA;
        for(int i=0;i<d;++i){
           B=B->next;
        }
    }

    while(A!=NULL && B!=NULL){
        if(A==B){
            return A;
        }
        A=A->next;
        B=B->next;
    }
    return NULL;
}

int main(){

    return 0;
}

