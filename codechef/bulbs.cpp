/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

int call(string s, int k){
	if(k<0){
		return INT_MAX;
	}
	vector<int> conti_0counts;
	int count=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			if(count>0){
				conti_0counts.push_back(count);
			}
			count=0;
		}
		else{
			count++;
		}
	}
	sort(conti_0counts.begin(),conti_0counts.end());
	while(k>1&&conti_0counts.size()>0){
		conti_0counts.pop_back();
		k-=2;
	}
	int retval=0;
	for(int i=0;i<conti_0counts.size();i++){
		retval+=conti_0counts[i];
	}
	return retval;
}

// Driver program 
int main() 
{ 
	int t,n,k,mini;
	cin>>t;
	string s;
	for(int u=0;u<t;u++){
		cin>>n>>k;
		cin>>s;
		int ct=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				ct++;
			}
		}
		if(ct==0||ct==n){
			cout<<"0\n";
		}
		else{
			string ss;
			int fcount,bcount,flag;
			fcount=bcount=flag=0;
			for(int i=0;i<n;i++){
				if(!flag&&s[i]=='0'){
					fcount++;
				}
				else{
					flag=1;
					ss.push_back(s[i]);
				}
			}
			while(ss.back()=='0'){
				bcount++;
				ss.pop_back();
			}
			mini = min(call(ss,k)+fcount+bcount,min(call(ss,k-1)+fcount,min(call(ss,k-1)+bcount,call(ss,k-2))));
			cout<<mini<<"\n";
		}
	}  
} 