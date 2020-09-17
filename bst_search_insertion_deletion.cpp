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

TreeNode* search(TreeNode* root, int key){
	if(root!=NULL){
		if(root->data == key){
			return root;
		}
		else if(key<root->data){
			return search(root->left,key);
		}
		else{
			return search(root->right,key);
		}
	}
	else{
		return NULL;
	}
}

TreeNode* insert(TreeNode* root, int val){
	if(root==NULL){
		root = new TreeNode(val);
	}
	else{
		if(val<root->data){
			root -> left = insert(root->left,val);
		}
		else{
			root -> right = insert(root->right,val);
		}
	}
	return root;
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

TreeNode* successor(TreeNode* root){
	TreeNode* right = root->right;
	while(right->left!=NULL){
		right = right->left;
	}
	return right;
}

TreeNode* deleteNode(TreeNode* root, int key){
	TreeNode* retval;
	if(root->data < key){
		root->right = deleteNode(root->right,key);
		retval = root;
	}
	else if(root->data > key){
		root->left = deleteNode(root->left,key);
		retval = root;	
	}
	else{
			if(root->left==NULL&&root->right==NULL){
				free(root);
				retval = NULL;
			}
			else if(root->left==NULL){
				retval = root->right;
				free(root);
			}
			else if(root->right==NULL){
				retval = root->left;
				free(root);
			}
			else{
				TreeNode* node = successor(root);
				node->right = deleteNode(root->right,node->data);
				node->left = root->left;
				free(root);
				retval = node;
			}
	}
	return retval;
}

// Driver program 
int main() 
{ 
	int n,val;
	TreeNode* root = NULL;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		root = insert(root,val);
	}
	levelOrderTraversal(deleteNode(root,3));
} 