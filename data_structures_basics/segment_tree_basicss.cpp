/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

int* createST(int arr[], int st[], int n){
	for(int i=0;i<n;i++){
		st[n+i]=arr[i];
	}
	for(int i=n-1;i>0;i--){
		st[i] = st[i<<1] + st[i<<1|1];
	}
	return st;
}


// Driver program 
int main() 
{
	int n,var;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int st[2*n];
	int* retval = createST(arr,st,n);
}