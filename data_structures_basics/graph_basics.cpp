/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

//Search takes O(n) and updation takes O(1)

void printAdjList(std::vector<int> v[],int vertices){
	for(int i=0;i<vertices;i++){
		cout<<i<<"->";
		for(int j=0;j<v[i].size();j++){
			cout<<v[i].at(j)<<"->";
		}
		cout<<"END\n";
	}
}

void BFS(std::vector<int> adj[],int vertices,int startIndex){
	bool visited[vertices];
	for(int i=0;i<vertices;i++){
		visited[i] = false;
	}
	queue<int> que;
	que.push(startIndex);
	cout<<"BFS is :- ";
	while(!que.empty()){
		int front = que.front();
		if(!visited[front]){
			cout<<front<<" ";
			for(int i=0;i<adj[front].size();i++){
				if(!visited[adj[front].at(i)]){
					que.push(adj[front].at(i));
				}
			}
			visited[front]=true;
		}
		que.pop();
	}
	cout<<endl;
}

void DFS(std::vector<int> adj[],int vertices,int startIndex){
	bool visited[vertices];
	for(int i=0;i<vertices;i++){
		visited[i] = false;
	}
	stack<int> stk;
	stk.push(startIndex);
	cout<<"DFS is :- ";
	while(!stk.empty()){
		int top = stk.top();
		stk.pop();
		if(!visited[top]){
			cout<<top<<" ";
			for(int i=0;i<adj[top].size();i++){
				if(!visited[adj[top].at(i)]){
					stk.push(adj[top].at(i));
					//cout<<"Pushing"<<adj[top].at(i)<<endl;
				}
			}
			visited[top]=true;
		}
	}
	cout<<endl;	
}

// Driver program 
int main() 
{ 
	int n,u,v;
	cin>>n;
	std::vector<int> adj[n+1];
	for(int i=0;i<n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printAdjList(adj,n);
	BFS(adj,n,0);
	DFS(adj,n,0);
}