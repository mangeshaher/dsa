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

int searchInorderIndex(vector<int> inorder,int inStart,int inEnd,int preOrderValue){
	int retval;
	for(int i=inStart;i<=inEnd;i++){
		if(preOrderValue == inorder[i]){
			retval = i;
			break;
		}
	}
	return retval;
}

TreeNode* buildTree(vector<int> preorder,vector<int> inorder,int inStart,int inEnd,unordered_map<int,int> map){
	int static preIndex = 0;
	if(inStart<=inEnd){
		int inIndex = map[preorder[preIndex++]];
		TreeNode* node = new TreeNode(inorder[inIndex]);
		if(inStart!=inEnd){
			node -> left = buildTree(preorder,inorder,inStart,inIndex-1,map);
			node -> right = buildTree(preorder,inorder,inIndex+1,inEnd,map);
		}
		return node;
	}
	else{
		return NULL;
	}
}

TreeNode* buildTreeWrapper(vector<int> preorder,vector<int> inorder,int inStart,int inEnd){
	unordered_map<int,int> map;
	for(int i=0;i<inorder.size();i++){
		map[inorder[i]] = i;
	}
	return buildTree(preorder,inorder,0,6,map);
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
	vector<int> preorder;
	vector<int> inorder;
	int var;
	for(int i=0;i<7;i++){
		cin>>var;
		inorder.push_back(var);
	}
	for(int i=0;i<7;i++){
		cin>>var;
		preorder.push_back(var);
	}
	TreeNode* root = buildTreeWrapper(preorder,inorder,0,6);
	preOrder(root);
} 