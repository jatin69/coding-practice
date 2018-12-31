/*
 * Author : Jatin Rohilla
 * Date   : 31-12-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 *	Objective : header file for tree
 *	usage :
 *	```
 *	#include "tree.h"
 *	```
 */

//#include <bits/stdc++.h>
//using namespace std;

// Tree Node structure
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int _data, Node *_left = nullptr, Node *_right = nullptr) {
    data = _data;
    left = _left;
    right = _right;
  }
};

void printBinaryTree(Node *root, int COUNT = 1, int space = 0) {

  // increase distance between levels
  space += COUNT * 10;

  // Process right child first - to show it on top line
  if (root && (root->left || root->right)) {
    printBinaryTree(root->right, COUNT, space);
  }

  // Process current Node
  int gapLines, gapSpaces;

  // Gap lines before Node
  for (int i = 0; i < COUNT; ++i) {
    cout << "\n";
  }

  // spaces before node
  for (int i = 0; i < space - (COUNT * 10); ++i) {
    cout << " ";
  }
  // current node
  root == nullptr ? cout << "NULL" : cout << root->data;

  // Gap lines after Node
  for (int i = 0; i < COUNT; ++i) {
    cout << "\n";
  }

  // Process left child
  if (root && (root->left || root->right)) {
    printBinaryTree(root->left, COUNT, space);
  }
}

Node *makeTreeHelper(string s) {

//  cout << s << "\n";

  if (s.length() == 0) {
    return nullptr;
  }

  if (s[0] == '{') {
    return makeTreeHelper(s.substr(1, s.length() - 2));
  }

  // get root data
  int i = 0;
  while (isdigit(s[i])) {
    i++;
  }

  int rootData = atoi(s.substr(0, i).c_str());
  Node *root = new Node(rootData);

  int count;
  int j;
  if (s[i] == ',') {
    count = 0;
    i++;
    j = i;
    while (1) {
      if (s[j] == '{') {
        count++;
      } else if (s[j] == '}') {
        count--;
        if (count == 0) {
          break;
        }
      }
      j++;
    }
    root->left = makeTreeHelper(s.substr(i, j - i + 1));
  }

  i = j + 1;
  if (s[i] == ',') {
    count = 0;
    i++;
    j = i;
    while (1) {
      if (s[j] == '{') {
        count++;
      } else if (s[j] == '}') {
        count--;
        if (count == 0) {
          break;
        }
      }
      j++;
    }
    root->right = makeTreeHelper(s.substr(i, j - i + 1));
  }

  return root;
}

Node *makeTree(string str) {

  // clean string
  for (auto c : " \n\t") {
    str.erase(std::remove(str.begin(), str.end(), c), str.end());
  }

  //   cout << str << "\n";
  return makeTreeHelper(str);
}

int test() {

  // classic method
  // Node *root = new Node(1, new Node(2, new Node(4), new Node(5)),  new Node(3, new Node(6), new Node(7)));

  // new method
  Node *root = makeTree(
//  "{}"
//  "{1}"
//  "{1, {2}, {}}"
//  "{1, {}, {3}}"
//  "{1, {2}, {3}}"
  "{1, {2, {4}, {5}}, {3, {6}, {7}}}"
//  "{1, {2, {}, {5, {8}, {9} }}, {3, {6}, {7}}}"
  );
  
  printBinaryTree(root);
  
}

//int main(){
//	test();
//	return 0;
//}

bool isLeaf(Node* root){
	return root->left==nullptr && root->right==nullptr;
}
