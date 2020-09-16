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
	levelOrderTraversal(root);
} 