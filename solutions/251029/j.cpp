#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    b*=180;
    cout<<b/gcd(a,b)-1<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}