/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

/*STACK OPERATION*/
//empty() -> returns boolean(0 or 1) if empty or not
//top() -> returns reference of top -- returns nothing if empty
//size() -> returns size of stack -- returns zero if empty
//push(x) -> pushes value x to stack and returns void
//pop() -> pops top value of stack and returns void --  does nothing if stack is null

/*QUEUE OPERATION*/
//empty() -> returns boolean(0 or 1) if empty or not
//front() and back()-> returns reference of front and back element -- returns nothing if empty
//size() -> returns size of queue -- returns zero if empty
//push(x) -> pushes value x at the end of queue
//pop() -> pops front value of queue --  does nothing if queue is null

/*PRIORITY QUEUE OPERATION -- decreasing order sorted -- greater number greater priority*/
//empty() -> returns boolean(0 or 1) if empty or not
//top()-> returns reference of front element -- returns nothing if empty
//size() -> returns size of queue -- returns zero if empty
//push(x) -> pushes value x at the end of queue
//pop() -> pops front value of queue --  does nothing if queue is null

template <class T>
void printStack(stack<T> s){
	while(!s.empty()){
		cout<<s.top()<<"\n";
		s.pop();
	}
	cout<<"\n";
}

template <class T>
void printPriorityQueue(priority_queue<T> pq){
	while(!pq.empty()){
		cout<<pq.top()<<"\n";
		pq.pop();
	}
	cout<<"\n";
}

template <class T>
void printQueue(queue<T> q){
	while(!q.empty()){
		cout<<"Front -> "<<q.front()<<" Back -> "<<q.back()<<"\n";
		q.pop();
	}
	cout<<"\n";
}

// Driver program 
int main() 
{ 
    int n;
    stack<int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		s.push(i);
	}
	printStack(s);
	queue<int> q;
	for(int i=0;i<n;i++){
		q.push(i);
	}
	printQueue(q);
	priority_queue<int> pq;
	pq.push(7);
	pq.push(5);
	pq.push(9);
	pq.push(8);
	printPriorityQueue(pq);
} 