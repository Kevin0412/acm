#include <bits/stdc++.h>
using namespace std;

long long a[5000006],b[5000006];

void solve(){
	long long n,x,y,z,i,k;
	cin>>n>>x>>y>>z;
	for(i=0;i<n;i++){
		b[i]=0;
		a[i]=0;
	}
	b[n]=0;
	for(i=0;i<n;i++){
		cin>>k;
		a[k]++;
	}
	for(i=1;i<=n;i++){
		//cerr<<a[i]<<" ";
		b[a[i]]++;
	}
	//cerr<<endl;
	long long maxb=n+1;
	//for(i=0;i<=n;i++)//cerr<<b[i]<<" ";
	//cerr<<endl;
	for(i=n;i>0;i--){
		if(b[i]==0)maxb=i;
		else break;
	}
	for(i=n-1;i>=0;i--){
		b[i]+=b[i+1];
	}
	long long ans=0,xi=1,yi=0,zi=-1;
	for(i=1;i<maxb;i++){
		xi+=b[i]-1;
		zi++;
		yi=n-xi-zi;
		cerr<<xi<<" "<<yi<<" "<<zi<<endl;
		ans=max(xi*x+yi*y+zi*z,ans);
	}
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}