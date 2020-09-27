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

int* updateTreeNode(int position,int value,int st[],int n){
	st[position+n] = value;
	for(int i=position+n;i>1;i>>=1){
		st[i>>1] = st[i] + st[i^1];	
	}
	return st;
}

int query(int l, int r, int st[], int n){
	int res=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1){
			res+=st[l++];
			cout<<"l is := "<<l<<endl;
		}
		if(r&1){
			res+=st[--r];
			cout<<"r is := "<<r<<endl;
		}
	}
	return res;
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
	retval = updateTreeNode(2,9,retval,n);
	cout<<query(0,4,retval,n)<<endl;
}