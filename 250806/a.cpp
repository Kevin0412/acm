#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0), cout.tie(0); 
    int i,n;
    cin>>n;
    unsigned long long ans=0,a;
    for(i=0;i<n;i++){
    	cin>>a;
    	ans|=a;
    }
    cout<<ans<<endl;
    return 0;
}