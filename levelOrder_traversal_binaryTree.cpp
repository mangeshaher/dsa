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
	levelOrderTraversal(root);
} 