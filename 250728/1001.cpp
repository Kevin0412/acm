#include<bits/stdc++.h>

using namespace std;

long long a[200005],MOD=998244353;

void solve(){
	int i,n;
	long long ans1=0,maxa=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		ans1+=a[i];
		maxa=max(maxa,a[i]);
	}
	//cerr<<maxa<<endl;
	if(maxa==0){
		cout<<ans1<<" "<<(((long long)(n+1)*(long long)(n+1))%MOD*(((long long)(n)*(long long)(n+1))/2)%MOD)%MOD<<endl;
		return;
	}
	long long mina=maxa;
	for(i=0;i<n;i++){
		if(a[i]!=0){
			mina=min(mina,a[i]);
		}
	}
	//cerr<<mina<<endl;
	int l0=-1,r0=n;
	for(i=0;i<n;i++){
		if(a[i]==0)l0=i;
		else break;
	}
	//cerr<<l0<<endl;
	for(i=n-1;i>=0;i--){
		//cerr<<i<<" ";
		if(a[i]==0)r0=i;
		else break;
	}
	//cerr<<r0<<endl;
	cout<<ans1<<" "<<(((long long)(mina+n+1)*(long long)(n-maxa+1))%MOD*((long long)(l0+2)*(long long)(n-r0+1))%MOD)%MOD<<endl;
}

int main(){
	ios::sync_with_stdio(false); // 关闭输入输出同步
    cin.tie(nullptr);            // 解绑cin和cout
    
    int t;
    cin>>t;
    while(t--)solve();
    
    return 0;
}