/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class TreeNode{
public:
	int data;
	int height;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data){
		this->data = data;
		left = right = NULL;
		this->height = 1;
	}
};

int getHeight(TreeNode* node){
	return (node!=NULL) ? node->height : 0;
}

int balance(TreeNode* root){
	return (root!=NULL) ? getHeight(root->left) - getHeight(root->right) : 0 ;
}

TreeNode* leftRotate(TreeNode* root){
	TreeNode* right = root->right;
	TreeNode* rightLeft = right->left;
	right->left = root;
	root->right = rightLeft;
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
	right->height = max(getHeight(right->left),getHeight(right->right))+1;
	return right;
}

TreeNode* rightRotate(TreeNode* root){
	TreeNode* left = root->left;
	TreeNode* leftRight = left->right;
	left->right = root;
	root->left = leftRight;
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
	left->height = max(getHeight(left->left),getHeight(left->right))+1;
	return left;
}

TreeNode* insert(TreeNode* root, int key){
	if(root==NULL){
		return new TreeNode(key);
	}
	if(key<root->data){
		root->left = insert(root->left,key);
	}
	else if(key>root->data){
		root->right = insert(root->right,key);
	}
	else{
		return root;
	}
	root -> height = max(getHeight(root->left),getHeight(root->right))+1;
	int bal = balance(root);
	TreeNode* node;
	if(bal<-1 && key>root->right->data){
		node = leftRotate(root);
	}
	if(bal<-1 && key<root->right->data){
		root->right = rightRotate(root->right);
		node = leftRotate(root);
	}
	if(bal>1 && key<root->left->data){
		node = rightRotate(root);
	}
	if(bal>1 && key>root->left->data){
		root->left = leftRotate(root->left);
		node = rightRotate(root); 
	}
	return node;
}

void levelOrderTraversal(TreeNode* root){
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);
	while(!nodeQueue.empty()){
		TreeNode* front = nodeQueue.front();
		if(front!=NULL){
			cout<<front->data<<" ";
			nodeQueue.push(front->left);
			nodeQueue.push(front->right);
		}
		nodeQueue.pop();
	}
}

// Driver program 
int main() 
{
	TreeNode* root = NULL;
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,30);
	root = insert(root,40);
	root = insert(root,50);
	root = insert(root,25);
	//levelOrderTraversal(root);
} 