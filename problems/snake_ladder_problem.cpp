/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

// Driver program 
int main() 
{ 
	int n,a,b;
	unordered_map<int,int> map;
	cin>>n;  
	for(int i=0;i<n;i++){
		cin>>a>>b;
		map[a]=b;
	}
	int dp[31];
	for(int i=1;i<31;i++){
		dp[i] = min(dp[i],i/6 +1);
		if(map.find(i)!=map.end()){
			dp[map[i]] = min(dp[map[i]],dp[i]);
		}
	}
	for(int i=1;i<31;i++){
		cout<<dp[i]<<" ";
	}
} 