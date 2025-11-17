#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    int kn=n/k;
    if(m<=n-kn){
        cout<<(kn+1)/2+m<<"\n";
        return;
    }else{
        kn-=m-(n-kn);
        cout<<(kn+1)/2+m<<"\n";
        return;
    }
}

signed main(){
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
