#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<long long> a(n,0);
	vector<int> b(k,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<k;i++){
		cin>>b[i];
	}
	sort(a.begin(), a.end(), greater<long long>());
	sort(b.begin(), b.end());
	int l=0;
	for(auto i:b){
		if(l+i-1>=n)break;
		a[l+i-1]=0;
		l+=i;
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=a[i];
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