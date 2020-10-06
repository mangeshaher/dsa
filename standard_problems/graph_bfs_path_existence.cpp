/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

//cell with 1 is source
//cell with 2 is destn
//cell with 0 is wall

// Driver program 
int main() 
{ 
	int n,size,si,sj;
	cin>>n;
	for(int s=0;s<n;s++){
		cin>>size;
		int mat[size][size];
		bool visited[size][size];
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cin>>mat[i][j];
				visited[i][j]=false;
				if(mat[i][j]==1){
					si = i;
					sj = j;
				}
			}
		}
		queue<pair<int,int>> q;
		q.push(make_pair(si,sj));
		int flag=0;
		while(!q.empty()){
			pair<int,int> front = q.front();
			int i = front.first;
			int j = front.second;
			visited[i][j]=true;
			if(mat[i][j]==2){
				flag=1;
				break;
			}
			if(i+1<size&&mat[i+1][j]!=0&&!visited[i+1][j]){
				q.push(make_pair(i+1,j));
			}
			if(i-1>=0&&mat[i-1][j]!=0&&!visited[i-1][j]){
				q.push(make_pair(i-1,j));
			}
			if(j+1<size&&mat[i][j+1]!=0&&!visited[i][j+1]){
				q.push(make_pair(i,j+1));
			}
			if(j-1>=0&&mat[i][j-1]!=0&&!visited[i][j-1]){
				q.push(make_pair(i,j-1));
			}
			q.pop();
		}
		if(flag==0){
			cout<<"-1\n";
		}
		else{
			cout<<"1\n";
		}
	}    
} 