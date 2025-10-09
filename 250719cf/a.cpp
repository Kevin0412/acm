#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	if(n==1 | m==1){
		cout<<"NO"<<endl;
		return;
	}
	if(n==2 & m==2){
		cout<<"NO"<<endl;
		return;
	}
    cout<<"YES"<<endl;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}