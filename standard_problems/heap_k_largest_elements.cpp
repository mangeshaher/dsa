/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

vector<int> heapify(vector<int> a, int k, int n){
	int largest = k;
	int left = 2*k+1;
	int right = 2*k+2;
	if(left<n&&a[left]>a[largest]){
		largest = left;
	}
	if(right<n&&a[right]>a[largest]){
		largest = right;
	}
	if(largest!=k){
		swap(a[k],a[largest]);
		a = heapify(a,largest,n);
	}
	return a;
}

vector<int> heapUtil(vector<int> a, int k){
	for(int i=a.size()/2-1;i>=0;i--){
		a = heapify(a,i,a.size());
	}
	vector<int> retval;
	for(int i=a.size()-1;i>a.size()-k;i--){
		a = heapify(a,0,i);
		retval.push_back(a[0]);
		swap(a[0],a[i]);
	}
	retval.push_back(a[0]);
	return retval;
}

// Driver program 
int main() 
{ 
	vector<int> arr;
	int n,var;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>var;
		arr.push_back(var);
	}
	vector<int> retval;
	retval = heapUtil(arr,5);
	for(int i=0;i<retval.size();i++){
		cout<<retval[i]<<" ";
	}
} 