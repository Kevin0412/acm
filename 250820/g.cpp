#include<bits/stdc++.h>

using namespace std;

void solve(){
	int i,n;
	long long k1,ai;
	cin>>n>>k1;
	__int128 k=(__int128)k1;
	vector<__int128> a,sum;
	sum.push_back(0LL);
	for(i=0;i<n;i++){
		cin>>ai;
		a.push_back((__int128)ai);
	}
	sort(a.begin(), a.end());
	for(i=0;i<n;i++){
		sum.push_back(sum[i]+a[i]);
	}
	long long ans=sum[n]-k;
	//cerr<<ans<<endl;
	if(ans<=0){
		cout<<0<<endl;
		return;
	}
	for(i=n;i>0;i--){
		long long ansi=n-i;
		// if(ansi>ans){
			// break;
		// }
		__int128 r;
		if(k-(sum[i]-sum[1])>=0){
			r=(k-(sum[i]-sum[1]))/(__int128)(n-i+1);
		}else{
			r=(k-(sum[i]-sum[1]) -(__int128)(n-i))/(__int128)(n-i+1);
		}
		if(r<a[0]){
			ansi+=a[0]-r;
		}
		//cerr<<i<<" "<<ansi<<" "<<r<<" "<<a[0]-r<<" "<<k-(sum[i]-sum[1])<<endl;
		ans=min(ansi,ans);
	}
	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}