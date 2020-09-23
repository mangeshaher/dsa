/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

// Driver program 
int main() 
{ 
	unordered_set<string> uset;
	uset.insert("a");
	uset.insert("b");
	uset.insert("c");
	uset.insert("d");
	uset.insert("e");
	uset.insert("f");
	for(auto i:uset){
		cout<<i<<endl;
	}
	auto itr = uset.find("bb");
	if(itr!=uset.end()){
		cout<<"Value of key is :-"<< *itr << endl;
	}
	else{
		cout<<"key not found for umap of size "<<uset.size()<<endl;
	}
	cout<<"Changes for SET\n";
	set<string> set;
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	for(auto i:set){
		cout<<i<<endl;
	}
	auto itrr = set.find("ss");
	if(itrr!=set.end()){
		cout<<"Value of key is :-"<< *itrr << endl;
	}
	else{
		cout<<"key not found for umap of size "<<set.size()<<endl;
	}
}