#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,x;
		cin>>n>>x;
		int j;
		for(j=0;j<x;j++){
			cout<<j<<" ";
		}
		for(j=n-1;j>=x;j--){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}