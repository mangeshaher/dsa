/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class TrieNode{
public:
	bool isEndOfNode;
	vector<TrieNode*> children;
	TrieNode(){
		this->isEndOfNode = false;
		for(int i=0;i<26;i++){
			this->children.insert(this->children.begin()+i,NULL);
		}
	}
};

bool hasAnyChild(TrieNode* root){
	for(int i=0;i<26;i++){
		if(root->children.at(i)){
			return true;
		}
	}
	return false;
}

bool search(TrieNode* root, string key){
	if(root!=NULL){
		bool flag = true;
		TrieNode* current = root;
		for(int i=0;i<key.length();i++){
			int index = key[i] - 'a';
			if(!current->children.at(index)){
				flag=true;
				break;
			}
			current = current->children.at(index);
		}
		if(!current->isEndOfNode){
			flag=false;
		}
		return flag;
	}
	return false;
}

void insert(TrieNode* root, string key){
	TrieNode* current = root;
	for(int i=0;i<key.length();i++){
		int index = key[i] - 'a';
		if(!current->children.at(index)){
			current->children.insert(current->children.begin()+index,new TrieNode());
		}
		current = current->children.at(index);
	}
	current->isEndOfNode = true;
}

TrieNode* deleteNode(TrieNode* root, string key, int depthOfKey){
	int index = key[depthOfKey] - 'a';
	if(depthOfKey==key.length()){//to go till leaf node 26
		if(!hasAnyChild(root)){
			free(root);
			return NULL;
		}
		else{
			root->isEndOfNode = false;
			return root;
		}
	}
	else{
		root->children.at(index) = deleteNode(root->children.at(index),key,depthOfKey+1);
		if(!hasAnyChild(root)&&!root->isEndOfNode){
			free(root);
			return NULL;
		}
		else{
			return root;
		}
	}
}

// Driver program 
int main() 
{ 
	int n;
	string var,keyToDelete;
	TrieNode* node = new TrieNode();
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>var;
		insert(node,var);
	}
	cin>>keyToDelete;
	if(search(node, keyToDelete)){
		node = deleteNode(node, keyToDelete,0);
	}
	cout<<search(node,keyToDelete);
}  