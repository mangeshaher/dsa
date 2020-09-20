/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

// Driver program 
int main() 
{ 
	int t,n,k,l;
	cin>>t;
	for(int u=0;u<t;u++){
		cin>>n>>k>>l;
		if(k>1&&k*l>=n){
			int i=1;
			int count=0;
			while(count<n){
				if(i>k){
					i=1;
				}
				cout<<i<<" ";
				i++;
				count++;
			}
			cout<<"\n";
		}
		else if(k==1&&n==1){
			cout<<"1\n";
		}
		else{
			cout<<"-1\n";
		}
	}
} 