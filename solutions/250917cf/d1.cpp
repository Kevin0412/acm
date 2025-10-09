#include<bits/stdc++.h>

using namespace std;

long long MOD=1000000007;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<long long> dp1(n,1),dp2(n,1);
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(a[i]<=a[j]){
				dp1[i]+=dp1[j];
				dp1[i]%=MOD;
			}
		}
		cerr<<dp1[i]<<" ";
	}
	cerr<<"\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>=a[j]){
				dp2[i]+=dp2[j];
				dp2[i]%=MOD;
			}
		}
		cerr<<dp2[i]<<" ";
	}
	cerr<<"\n";
	long long ans=1;
	for(int i=0;i<n;i++){
		ans+=dp2[i];
		ans%=MOD;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				ans+=dp1[i]*dp2[j];
			}
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