/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

int partition(int a[], int left,int right){
	int pivot = a[right];
	int i = left-1;
	int j = left;
	while(j<right){
		if(a[j]<pivot){
			swap(a[++i],a[j]);
		}
		j++;
	}
	swap(a[++i],a[right]);
	return i;
}

/*
f(n) = O(n) + f(k) + f(n-k)
here function depends on which pivotIndex is returned by partition function
so in the best case when pivotIndex divides the function into significant halfs complexity is O(nlogn)
and in the worst case O(n^2) when division is almost at ends
*/
void quickSort(int a[], int left, int right){
	if(left<right){
		int pivotIndex = partition(a,left,right);
		quickSort(a,left,pivotIndex-1);
		quickSort(a,pivotIndex+1,right);
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
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}  
} 