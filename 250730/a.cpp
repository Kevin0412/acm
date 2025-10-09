#include<bits/stdc++.h>

using namespace std;

int a[10004];

void solve(){
	int n,i;
	cin>>n;
    for(i=0;i<n;i++){
    	cin>>a[i];
    }
    int ans=0;
    for(i=0;i<n;i++){
    	ans=ans^a[i];
    }
    if(ans){
    	cout<<"Yes"<<endl;
    }else{
    	cout<<"No"<<endl;
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}