/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

void merge(int a[], int left, int mid, int right){
	int l[mid-left+1];
	int r[right-mid];
	for(int i=0;i<mid-left+1;i++){
		l[i] = a[left+i];
	}
	for(int i=0;i<right-mid;i++){
		r[i] = a[mid+i+1];
	}
	int i = 0;
	int j = 0;
	int start = left;
	while(i<=mid-left&&j<=right-mid-1){
		if(l[i]<=r[j]){
			a[start++]=l[i++];
		}
		else{
			a[start++]=r[j++];
		}
	}
	while(i<=mid-left){
		a[start++]=l[i++];
	}
	while(j<=right-mid-1){
		a[start++]=r[j++];
	}
}

void mergeSort(int a[],int left, int right){
	if(left<right){
		int mid = (right+left)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}

// Driver program 
int main() 
{ 
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}  
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
} 