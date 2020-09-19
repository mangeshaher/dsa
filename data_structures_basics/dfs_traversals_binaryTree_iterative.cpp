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
	if(node!=NULL){
		stack<TreeNode*> s;
		s.push(node);
		TreeNode* current = node;
		current = current -> left;
		while(!(s.empty()&&current==NULL)){
			if(current==NULL){
				cout<<s.top()->data<<" ";
				current = s.top()->right;
				s.pop();
			}
			else{
				s.push(current);
				current = current -> left;
			}
		}
	}
}

void preOrder(TreeNode* node){
	if(node!=NULL){
		stack<TreeNode*> s;
		s.push(node);
		TreeNode* current = node;
		cout<<current->data<<" ";
		current = current -> left;
		while(!(s.empty()&&current==NULL)){
			if(current==NULL){
				current = s.top()->right;
				s.pop();
			}
			else{
				cout<<current->data<<" ";
				s.push(current);
				current = current -> left;
			}
		}
	}
}

void postOrder(TreeNode* node){
	if(node!=NULL){
		stack<TreeNode*> s;
		TreeNode* current = node;
		while(!(s.empty()&&current==NULL)){
			if(current!=NULL){
				s.push(current);
				s.push(current);
				current = current -> left;
			}
			else{
				if(!s.empty()){
					current = s.top();
					s.pop();
					if(!s.empty()&&current == s.top()){
						current = current -> right;
					}
					else{
						cout<< current->data <<" ";
						current = NULL;
					}
				}
				else{
					break;
				}
			}
		}
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