/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

// Driver program 
int main() 
{ 
	int t,n,k,m;
	string s;
	cin>>t;
	for(int m=0;m<t;m++){
		unordered_map<char,int> map;
		cin>>n>>k;
		int flag=0;
		cin>>s;
		for(int i=0;i<s.size();i++){ 
			map[s.at(i)]+=1;
		}
		for(int i=s.size()-1;i>=0;i--){ 
			if(map[s[i]]>0){
				map[s[i]]--;
			}
			else{
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"POSSIBLE\n";
		}
		else{
			cout<<"IMPOSSIBLE\n";
		}
	}
}