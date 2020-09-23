/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

// Driver program 
int main() 
{
	int n,var;
	deque<int> dq;  
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>var;
		(i%2==0) ? dq.push_back(var) : dq.push_front(var);
	}
	for(int i=0;i<dq.size();i++){
		cout<<"Front is :- "<<dq.front()<<" Back is :- "<<dq.back()<<endl;
		dq.pop_back();
		dq.pop_front();
	}
} 