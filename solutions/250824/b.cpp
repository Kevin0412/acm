// Problem: B. Villagers
// Contest: Codeforces - Codeforces Round 1044 (Div. 2)
// URL: https://codeforces.com/contest/2133/problem/B
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
	vector<long long> a;
	long long ai;
	for(int i=0;i<n;i++){
		cin>>ai;
		a.push_back(ai);
	}
	sort(a.begin(), a.end(), greater<int>());
	long long ans=0;
	for(int i=0;i<n;i+=2){
		ans+=a[i];
	}
	cout<<ans<<"\n";
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