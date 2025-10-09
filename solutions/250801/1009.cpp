#include<bits/stdc++.h>

using namespace std;

int a[200005],b[200005],nexta[200005],nextb[200005];

void solve(){
    int i,n;
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>a[i];
    	nexta[i+1]=-1;
    }
    for(i=0;i<n;i++){
    	cin>>b[i];
    	nextb[i+1]=-1;
    }
    for(i=0;i<n-1;i++){
    	nexta[a[i]]=a[i+1];
    	nextb[b[i]]=b[i+1];
    }
    int ans=n;
    for(i=1;i<=n;i++){
    	if(nexta[i]==nextb[i] & nexta[i]!=-1){
    		ans--;
    	}
    }
    cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}