/*
 * Author : Jatin Rohilla
 * Date   : 31-12-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */

#include <bits/stdc++.h>
using namespace std;

#include "tree.h"

// Prototypes

// DFS

void inOrder(Node *);
void preOrder(Node *);
void postOrder(Node *);

void inOrderIterative(Node *);
void preOrderIterative(Node *);
void postOrderIterative(Node *);
void postOrderIterativeMyVersion(Node *);

// BFS

void levelOrderTraversal(Node *);
void levelOrderReverse(Node *);

int main() {

  Node *root = makeTree({
      "{1, {2, {4}, {5}}, {3, {6}, {7}}}"
      //	"{1, {2, {}, {5, {8}, {9} }}, {3, {}, {7}}}"
  });
  printBinaryTree(root);

  cout << "\n\ninOrder (Recursive)    :  ";  inOrder(root);
  cout <<   "\ninOrder (Iterative)    :  ";  inOrderIterative(root);

  cout << "\n\npreOrder (Recursive)   :  ";  preOrder(root);
  cout <<   "\npreOrder (Iterative)   :  ";  preOrderIterative(root);

  cout << "\n\npostOrder (Recursive)  :  ";  postOrder(root);
  cout <<   "\npostOrder (Iterative)  :  ";  postOrderIterative(root);
  cout <<   "\npostOrder (Iterative)  :  ";  postOrderIterativeMyVersion(root);
  cout << "   (My Version)";

  cout << "\n\nLevelOrder (Iterative) :  ";  levelOrderTraversal(root);
  cout <<   "\nLevelOrder Reversed    :  ";  levelOrderReverse(root);

  return 0;
}

// Functions

/********************************** DFS ************************************/

/******************************* Recursive *********************************/

void inOrder(Node *root) {
  if (root) {
    inOrder(root->left);
    visit(root);
    inOrder(root->right);
  }
}

void preOrder(Node *root) {
  if (root) {
    visit(root);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(Node *root) {
  if (root) {
    postOrder(root->left);
    postOrder(root->right);
    visit(root);
  }
}

/******************************* Iterative *********************************/

void inOrderIterative(Node *root) {
  if (!root)
    return;

  stack<Node *> S;
  while (1) {
    while (root) {
      S.push(root);
      root = root->left;
    }
    if (S.empty()) {
      break;
    }

    root = S.top();
    S.pop();
    visit(root);
    root = root->right;
  }
  return;
}

void preOrderIterative(Node *root) {

  stack<Node *> S;
  while (1) {

    while (root) {
      visit(root);
      S.push(root);
      root = root->left;
    }

    if (S.empty()) {
      break;
    }

    root = S.top();
    S.pop();
    root = root->right;
  }
}

// Standard Version ( single stack version )
void postOrderIterative(Node *root) {

  stack<Node *> S;
  Node *previous = nullptr;

  while (1) {

    while (root) {
      S.push(root);
      root = root->left;
    }

    while (!root && !S.empty()) {

      root = S.top();
      // no right subtree _OR_  coming back from right subtree
      if (root->right == nullptr || root->right == previous) {
        visit(root);
        previous = root;
        root = nullptr;
        S.pop();
      } else {
        root = root->right;
      }
    }

    if (S.empty()) {
      break;
    }
  }
}

/* 	PostOrder iterative traversal : A Modification of PreOrder ( uses 2
   stacks )

        PreOrder 				: Root Left Right
        Modification 			: Root Right Left
        Reverse with Stack 		: Left Right Root
        Matches with Postorder  : Left Right Root
*/
void postOrderIterativeMyVersion(Node *root) {

  stack<Node *> S;
  stack<Node *> V;

  while (1) {

    while (root) {
      V.push(root);
      S.push(root);
      root = root->right;
    }

    if (S.empty()) {
      break;
    }

    root = S.top();
    S.pop();
    root = root->left;
  }

  while (!V.empty()) {
    root = V.top();
    V.pop();
    visit(root);
  }
}

/******************************* BFS *********************************/

void levelOrderTraversal(Node *root) {

  if (root == nullptr) {
    return;
  }

  queue<Node *> bfsQueue;
  bfsQueue.push(root);
  Node *it;

  while (!bfsQueue.empty()) {
    it = bfsQueue.front();
    bfsQueue.pop();
    visit(it);

    if (it->left) {
      bfsQueue.push(it->left);
    }
    if (it->right) {
      bfsQueue.push(it->right);
    }
  }
}

// start from lower level upto top level
void levelOrderReverse(Node *root) {
  if (!root) {
    return;
  }

  queue<Node *> Q;
  stack<Node *> S;
  Q.push(root);
  Node *it;
  while (!Q.empty()) {
    it = Q.front();
    Q.pop();
    S.push(it);
    if (it->right) {
      Q.push(it->right);
    }
    if (it->left) {
      Q.push(it->left);
    }
  }

  while (!S.empty()) {
    it = S.top();
    S.pop();
    visit(it);
  }
  return;
}

