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

TreeNode* successor(TreeNode* root){
	TreeNode* right = root->right;
	while(right->left!=NULL){
		right = right->left;
	}
	return right;
}

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
	if(bal<-1 && key>root->right->data){
		root = leftRotate(root);
	}
	if(bal<-1 && key<root->right->data){
		root->right = rightRotate(root->right);
		root = leftRotate(root);
	}
	if(bal>1 && key<root->left->data){
		root = rightRotate(root);
	}
	if(bal>1 && key>root->left->data){
		root->left = leftRotate(root->left);
		root = rightRotate(root); 
	}
	return root;
}

TreeNode* deleteNode(TreeNode* root, int key){
	TreeNode* retval;
	if(root==NULL){
		retval = root;
	}
	else if(root->data < key){
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
				TreeNode* nodeToDelete = successor(root);
				TreeNode* node = new TreeNode(nodeToDelete->data);
				node->right = deleteNode(root->right,node->data);
				node->left = root->left;
				free(root);
				retval = node;
			}
	}
	if(retval!=NULL){
		retval -> height = max(getHeight(retval->left),getHeight(retval->right))+1;
		int bal = balance(retval);
		if(bal<-1 && key>retval->right->data){
			retval = leftRotate(retval);
		}
		if(bal<-1 && key<retval->right->data){
			retval->right = rightRotate(retval->right);
			retval = leftRotate(retval);
		}
		if(bal>1 && key<retval->left->data){
			retval = rightRotate(retval);
		}
		if(bal>1 && key>retval->left->data){
			retval->left = leftRotate(retval->left);
			retval = rightRotate(retval); 
		}	
	}
	return retval;
}

void levelOrderTraversal(TreeNode* root){
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);
	while(!nodeQueue.empty()){
		TreeNode* front = nodeQueue.front();
		if(front!=NULL){
			cout<<"Data :- "<<front->data<<" Height :- "<<front->height<<endl;
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
	levelOrderTraversal(root);
	cout<<"After Deletion\n";
	levelOrderTraversal(deleteNode(root,20));
} 