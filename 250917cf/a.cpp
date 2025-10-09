#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+2,0);
	int ai;
	for(int i=1;i<=n;i++){
		cin>>ai;
		a[i]=ai;
	}
	int l,r;
	for(int i=1;i<=n;i++){
		if(a[i]==n){
			l=i;
			r=i;
		}
	}
	for(int i=n-1;i>0;i--){
		if(a[l-1]==i){
			l--;
		}else if(a[r+1]==i){
			r++;
		}else{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}