/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

//[] operator is used for initializing umap
//.insert() method uses pair<a,b> as input 
//.find() returns iterator for element if exists else returns umap.end()
//The first loop below returns pair 
//The second loop returns reference to pair 
//size()
//empty()

// Driver program 
int main() 
{ 
	unordered_map<string,int> umap;
	umap["abc"]=1;
	umap["uvw"]=3;
	umap["pqr"]=2;
	umap.insert(make_pair("cba",4));
	umap.insert(make_pair("wvu",5));
	umap.insert(make_pair("rqp",6));
	for(auto i:umap){
		cout<<i.first<<" "<<i.second<<endl;
	}
	auto itr = umap.find("ab");
	if(itr!=umap.end()){
		cout<<itr->first<<" "<<itr->second<<endl;
	}
	else{
		cout<<"key not found for umap of size "<<umap.size()<<endl;
	}
	cout<<"Changes for MAP\n";
	map<string,int> map;
	map["abc"]=1;
	map["uvw"]=3;
	map["pqr"]=2;
	map.insert(make_pair("cba",4));
	map.insert(make_pair("wvu",5));
	map.insert(make_pair("rqp",6));
	auto iter = map.find("abc");
	map.erase(iter->first);
	for(auto i:map){
		cout<<i.first<<" "<<i.second<<endl;
	}
	if(iter!=map.end()){
		cout<<itr->first<<" "<<itr->second<<endl;
	}
	else{
		cout<<"key not found"<<endl;
	}
}