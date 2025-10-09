// Problem: A. Redstone?
// Contest: Codeforces - Codeforces Round 1044 (Div. 2)
// URL: https://codeforces.com/contest/2133/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=1e5+5;
const int inf=1e9;

void solve(){
	int n;
	cin>>n;
	vector<int> a(101,0);
	int ai;
	for(int i=0;i<n;i++){
		cin>>ai;
		a[ai]++;
	}
	for(auto i:a){
		//cerr<<i<<"\n";
		if(i>=2){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
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