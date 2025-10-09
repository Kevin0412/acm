// Problem: D. Chicken Jockey
// Contest: Codeforces - Codeforces Round 1044 (Div. 2)
// URL: https://codeforces.com/contest/2133/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	long long ai;
	vector<long long> a;
	for(int i=0;i<n;i++){
		cin>>ai;
		a.push_back(ai);
	}
	a.push_back(0);
	vector<long long> dp(n+2,0),damage(n+2,0),kill(n+2,0);
	vector<long long> ones(n+2,0);
	for(int i=n-1;i>=0;i--){
		if(a[i]==1){
			ones[i]=ones[i+1]+1;
		}
		cerr<<ones[i]<<" ";
	}
	cerr<<"\n";
	for(int i=n-1;i>=0;i--){
		if(a[i+1]){
			if(i+1>=a[i+1]){
				damage[i]=a[i+1];
				if(ones[i+1])damage[i]=ones[i+1];
				kill[i]=ones[i+1];
				if(a[i+2+kill[i]]) damage[i]++;
			}
			else{
				damage[i]=i+1;
			}
		}
		cerr<<damage[i]<<" ";
		dp[i]=max(damage[i]+dp[i+kill[i]+2],dp[i+1]);
		cerr<<dp[i]<<" ";
	}
	cerr<<"\n";
	cerr<<"\n";
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	cout<<sum-dp[0]<<endl;
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