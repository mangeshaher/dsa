/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

// Driver program 
int main() 
{ 
	int n,var;
	vector<int> vec;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>var;
		vec.push_back(var);
	}
	for(auto i = vec.begin() ; i!=vec.end() ; i++){
		cout<< *i <<endl;
	}
	for(int i = 0 ; i<vec.size() ; i++){
		cout<<"Eleemnt at "<< i << " is :- "<< vec.at(i)<<" "<<vec[i]<<endl;
	}
	for(int i = 0 ; i<vec.size() ; i++){
		cout<<"Front :-"<< vec.front() <<" Back :- "<<vec.back()<<endl;
		vec.pop_back();
	}
	int row=5;
	int col[5]={1,2,3,4,5};
	vector<vector<int>> vecc;
	for(int i=0;i<row;i++){
		for(int j=0;j<col[i];j++){
			cin>>var;
			vecc.push_back(vector<int> ());
			vecc[i].push_back(var);
		}
	}
	for(int i=0;i<vecc.size();i++){
		for(int j=0;j<vecc[i].size();j++){
			cout<<vecc[i][j]<<" ";
		}
		cout<<"\n";
	}
} 