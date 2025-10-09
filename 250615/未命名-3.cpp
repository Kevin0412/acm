#include<bits/stdc++.h> 

using namespace std;
long long a[500002],mod=998244353,b[500002],c[500002];

int main() 
{ 
    int n,q,i,l,r;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        cin>>a[i];
        a[i]%=mod;
    }
    b[n+1]=0;
    for(i=n;i>0;i--){
        b[i]=b[i+1]+a[i];
        b[i]%=mod;
    }
    c[n+1]=0;
    for(i=n;i>0;i--){
        c[i]=c[i+1]+a[i]*i;
        c[i]%=mod;
    }
    for(i=0;i<q;i++){
        cin>>l>>r;
        cout<<(c[l]-c[r+1]-(b[l]-b[r+1])*(l-1)+mod*n)%mod<<endl;
    }
    return 0; 
}