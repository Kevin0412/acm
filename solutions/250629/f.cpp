#include<bits/stdc++.h>
using namespace std;

int a[100001];

void solve(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<"Yes"<<endl;
	    return;
	}
	if(a[0]%2==0 | a[n-1]%2==0){
		cout<<"No"<<endl;
		return;
	}
	for(i=1;i<n-1;i++){
		if(a[i]%2==1){
			cout<<"No"<<endl;
		    return;
		}
	}
	cout<<"Yes"<<endl;
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}