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

void search(TrieNode* root, string key){
	if(root!=NULL){
		int flag = 0;
		TrieNode* current = root;
		for(int i=0;i<key.length();i++){
			int index = key[i] - 'a';
			if(!current->children.at(index)){
				cout<<"breaking point is"<<key[i]<<endl;
				flag=1;
				break;
			}
			current = current->children.at(index);
		}
		if(flag==1){
			cout<<"Searched key string is not there in trie\n";
		}
		else{
			if(current->isEndOfNode){
				cout<<"Searched key string is found in trie\n";
			}
			else{
				cout<<"Searched key string is substring of some word found in trie\n";
			}
		}
	}
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

// Driver program 
int main() 
{ 
	int n;
	string var;
	TrieNode* node = new TrieNode();
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>var;
		insert(node,var);
	}
	search(node,"saturda");
} 