#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,t,n,m,p,q;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>m>>p>>q;
		if(n%p!=0){
			cout<<"YES"<<endl;
			continue;
		}
		if(n*q==m*p){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}