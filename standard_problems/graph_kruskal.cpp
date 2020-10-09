/*Created by Mangesh Aher*/
#include <stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 

bool checkCycle(int u, int v, int n, int graph[][n+1]){
	return false;
}

// Driver program 
int main() 
{ 
	int n,t,u,v,w;
	cin>>n;
	cin>>t;
	int graph[n+1][n+1]={0};
	bool visited[n+1]={0};
	map<int,pair<int,int>> store;
	for(int i=1;i<t+1;i++){
		cin>>u>>v>>w;
		store[w] = make_pair(u,v);
	}
	for(auto i : store){
		int x = i.second.first;
		int y = i.second.second;
		if(!visited[x]||!visited[y]){
			graph[x][y]=1;
			graph[y][x]=1;
			visited[x]=visited[y]=true;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
} 