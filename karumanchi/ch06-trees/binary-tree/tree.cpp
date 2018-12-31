/*
 * Author : Jatin Rohilla
 * Date   : 31-12-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

#include "tree.h"

int main(){

	Node* root = makeTree(
	"{1, {2, {}, {4, {}, {5, {}, {6}}}}, {3, {}, {7, {8, {}, {9}}, {}}} }"
//	  "{1, {2, {}, {5, {8}, {9} }}, {3, {6}, {7}}}"
	);
	
	printBinaryTree(root);
    return 0;
}

