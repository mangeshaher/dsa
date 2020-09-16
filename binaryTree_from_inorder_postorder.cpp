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

TreeNode* buildTree(vector<int> postorder,vector<int> inorder,int inStart,int inEnd,unordered_map<int,int> map){
	int static postIndex = postorder.size()-1;
	if(inStart<=inEnd){
		int inIndex = map[postorder[postIndex--]];
		TreeNode* node = new TreeNode(inorder[inIndex]);
		if(inStart!=inEnd){
			node -> right = buildTree(postorder,inorder,inIndex+1,inEnd,map);
			node -> left = buildTree(postorder,inorder,inStart,inIndex-1,map);
		}
		return node;
	}
	else{
		return NULL;
	}
}

TreeNode* buildTreeWrapper(vector<int> postorder,vector<int> inorder,int inStart,int inEnd){
	unordered_map<int,int> map;
	for(int i=0;i<inorder.size();i++){
		map[inorder[i]] = i;
	}
	return buildTree(postorder,inorder,0,6,map);
}

void preOrder(TreeNode* node){
	if(node != NULL){
		cout<<node->data<<" ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

// Driver program 
int main() 
{ 
	vector<int> postorder;
	vector<int> inorder;
	int var;
	for(int i=0;i<7;i++){
		cin>>var;
		inorder.push_back(var);
	}
	for(int i=0;i<7;i++){
		cin>>var;
		postorder.push_back(var);
	}
	TreeNode* root = buildTreeWrapper(postorder,inorder,0,postorder.size()-1);
	preOrder(root);  
}