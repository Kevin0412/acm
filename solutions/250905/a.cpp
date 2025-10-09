#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<long long> a(n+1,0);
	vector<pair<long long,long long>> b(n+1,{0,1000000001});
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(q--){
		int p;
		long long l,r;
		cin>>p>>l>>r;
		b[p].first=max(b[p].first,l);
		b[p].second=min(b[p].second,r);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(b[i].first>b[i].second){
			cout<<"-1\n";
			return;
		}
		if(a[i]<b[i].first){
			ans+=b[i].first-a[i];
		}else if(a[i]>b[i].second){
			ans+=a[i]-b[i].second;
		}
	}
	cout<<ans<<"\n";
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