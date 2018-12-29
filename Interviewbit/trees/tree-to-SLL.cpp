/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x, TreeNode* _left=NULL, TreeNode* _right = NULL){
     	val = x;
     	left = _left;
     	right = _right;
	 }
};

/*
TreeNode* flatten(TreeNode* A){
	 if (A->left== NULL&&A->right==NULL)
    {
        return A;
    }
    else if(A->left==NULL)
    {
      return flatten(A->right);

    }
    else if(A->right==NULL)
    {
        A->right=A->left;
        A->left=NULL;
        return flatten(A->right);
    }
    else
    {
        TreeNode* temp=A->right;
        TreeNode* preorder=A->left;
        A->right=A->left;
        A->left=NULL;

        while ( preorder->right)
        {
            preorder=preorder->right;
        }
        preorder->right=temp;
        return (flatten(A->right));
    }
}

*/
void preOrder(TreeNode* root){
	if(root){

		cout << root->val << "  ";
		preOrder(root->left);
		preOrder(root->right);

	}
}
void check(TreeNode* root){
	if(root){
	if(root->left==NULL){
		cout<<"null\n";
	}
	
		root=root->right;
		check(root);
	 }
}


TreeNode* flatten(TreeNode* A){
	if (A->left != NULL && A->right !=NULL)
    {
		if(A->right==NULL){
	        A->right=A->left;
	        A->left=NULL;
    	}
    	else{
	        TreeNode* temp=A->right;
	        TreeNode* preorder=A->left;
	        A->right=A->left;
	        A->left=NULL;

	        while ( preorder->right)	        {
	            preorder=preorder->right;
	        }
	        preorder->right=temp;
    	}
    	A->right = flatten(A->right);
	}
   return A;
}


int main(){

// TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(7), new TreeNode(8)), new TreeNode(4)) , new  TreeNode(5, NULL, new TreeNode(6)));

TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)) , new  TreeNode(5, NULL, new TreeNode(6)));
preOrder(root);
cout<<"\n\n";

TreeNode* temp = flatten(root);
//check(root);
preOrder(temp);

    return 0;
}

