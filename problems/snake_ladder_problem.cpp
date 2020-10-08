/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class Node{
public:
	int i;
	int length;
	Node(int a,int b){
		i = a;
		length = b;
	}
};

// Driver program 
int main() 
{ 
	int n,a,b;
	bool visited[31];
	queue<Node*> q;
	unordered_map<int,int> map;
	cin>>n;  
	for(int i=0;i<n;i++){
		cin>>a>>b;
		map[a]=b;
	}
	for(int i=1;i<31;i++){
		visited[i] = false;
	}
	q.push(new Node(1,0));
	int count = 0;
	int nodesInserted = 1;
	while(!q.empty()){
		Node* front = q.front();
		if(front->i==30){
			cout<<"Minimum Length is :- "<<front->length<<endl;
			break;
		}
		for(int i =front->i+1;i<=front->i+6;i++){
			if(!visited[i]){
				visited[i]=true;
				if(map.find(i)!=map.end()&&!visited[map[i]]){
					q.push(new Node(map[i],front->length + 1));
					visited[map[i]]=true;
				}
				else{
					if(map.find(i)==map.end()){
						q.push(new Node(i,front->length + 1));
					}
				}
			}
		}
		q.pop();
	}
} 