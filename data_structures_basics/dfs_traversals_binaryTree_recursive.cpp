/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data){
		this->data = data;
		left = right = NULL;
	}
};

void inOrder(TreeNode* node){
	if(node != NULL){
		inOrder(node->left);
		cout<<node->data<<" ";
		inOrder(node->right);
	}
}

void preOrder(TreeNode* node){
	if(node != NULL){
		cout<<node->data<<" ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void postOrder(TreeNode* node){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		cout<<node->data<<" ";
	}
}

/*Tree
		  1
	 	/	\
	   2	 3
	  / \   / \
	 4   5 6   7
*/
// Driver program 
int main() 
{ 
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	inOrder(root);cout<<"\n";
	preOrder(root);cout<<"\n";
	postOrder(root);cout<<"\n";
} 