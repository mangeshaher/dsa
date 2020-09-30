/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

// Driver program 
int main() 
{ 
	//division by 2
	for(int i=16;i>1;i>>=1){
		cout<<i<<"\n";
	}   
	//multiplication by 2
	for(int i=1;i<33;i<<=1){
		if(i|1){//even number check
			cout<<i<<"\n";
		}
	}
}