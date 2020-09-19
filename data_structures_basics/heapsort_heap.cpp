/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

vector<int> minHeapify(vector<int> heap, int n, int i){
	int smallest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if(left<n && heap[left]<heap[smallest]){
		smallest = left;
	}
	if(right<n && heap[right]<heap[smallest]){
		smallest = right;
	}
	if(smallest!=i){
		swap(heap[smallest],heap[i]);
		heap = minHeapify(heap,n,smallest);
	}
	return heap;
}

vector<int> maxHeapify(vector<int> heap, int n, int i){
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if(left<n && heap[left]>heap[largest]){
		largest = left;
	}
	if(right<n && heap[right]>heap[largest]){
		largest = right;
	}
	if(largest!=i){
		swap(heap[largest],heap[i]);
		heap = maxHeapify(heap,n,largest);
	}
	return heap;
}

vector<int> heapify(vector<int> heap, int n, int i, int flag){
	return (flag ==0 ) ? minHeapify(heap,n,i) : maxHeapify(heap,n,i);
}

vector<int> buildHeap(vector<int> heap,int flag){
	for(int i=heap.size()/2 -1; i>=0;i--){
		heap = heapify(heap,heap.size(),i,flag);
	}
	return heap;
}

vector<int> heapsort(vector<int> heap, int flag){
	heap = buildHeap(heap,flag);
	for(int i=heap.size()-1;i>0;i--){
		swap(heap[0],heap[i]);
		heap = heapify(heap,i,0,flag);
	}
	return heap;
}

// Driver program 
int main() 
{ 
	int n,var;
	vector<int> heap;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>var;
		heap.push_back(var);
	}
	vector<int> minHeap = heapsort(heap,0);
	vector<int> maxHeap = heapsort(heap,1);
	cout<<"Sort using MinHeap :- \n";
	for(int i=0;i<n;i++){
		cout<<minHeap[i]<<" ";
	}
	cout<<"\n";
	cout<<"Sort using MaxHeap :- \n";
	for(int i=0;i<n;i++){
		cout<<maxHeap[i]<<" ";
	}
	cout<<"\n";
} 