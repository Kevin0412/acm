// Problem: C. The Nether
// Contest: Codeforces - Codeforces Round 1044 (Div. 2)
// URL: https://codeforces.com/contest/2133/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=1e5+5;
const int inf=1e9;

vector<int> a[502];

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		a[i].clear();
	}
	int maxk=0;
	for(int i=1;i<=n;i++){
		cout<<"? "<<i<<" "<<n;
		for(int j=1;j<=n;j++)cout<<" "<<j;
		cout<<"\n";
		cout.flush();
		int k;
		cin>>k;
		maxk=max(k,maxk);
		a[k].push_back(i);
	}
	vector<int> ans;
	ans.push_back(a[maxk][0]);
	for(int i=maxk-1;i>0;i--){
	    for(auto j:a[i]){
	    	cout<<"? "<<ans[0]<<" "<<maxk-i+1<<" "<<j;
	    	for(auto k:ans)cout<<" "<<k;
	    	cout<<"\n";
			cout.flush();
			int k;
			cin>>k;
			if(k==maxk-i+1){
				ans.push_back(j);
				break;
			}
	    }	
	}
	cout<<"! "<<maxk;
	for(auto k:ans){
		cout<<" "<<k;
	}
	cout<<"\n";
	cout.flush();
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}