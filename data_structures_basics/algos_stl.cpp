/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

void printVector(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout<<v.at(i)<<" ";
	}
	cout<<endl;
}

// Driver program 
int main() 
{ 
	int n,var;
	std::vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>var;
		v.push_back(var);
	}
	sort(v.begin(),v.end());
	printVector(v);
	reverse(v.begin(),v.end());
	printVector(v);
	cout<<accumulate(v.begin(),v.end(),0)<<endl;
} 