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

// Driver program 
int main() 
{ 
	int n,u,v;
	cin>>n;
	std::vector<int> adj[n];
	for(int i=0;i<n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	printAdjList(adj,n);
}