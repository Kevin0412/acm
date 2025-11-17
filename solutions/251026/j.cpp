#include<bits/stdc++.h>
#define int long long
using namespace std;

struct j
{
    int x;
    int y;
    int z;
    int den;
};


void solve(){
    vector<j> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a.push_back({x,y,z,-1LL});
    }
    sort(a.begin(),a.end(),[](j a,j b){return a.x<b.x;});
    int i=0;
    while(1){
        int x=a[i].x;
        int k=i;
        for(;i<n;i++){
            if(x!=a[i].x)break;
        }
        for(int l=k;l<i;l++){
            a[l].den=max(a[l].den,i-k-1);
        }
        if(i>=n)break;
    }
    sort(a.begin(),a.end(),[](j a,j b){return a.y<b.y;});
    i=0;
    while(1){
        int y=a[i].y;
        int k=i;
        for(;i<n;i++){
            if(y!=a[i].y)break;
        }
        for(int l=k;l<i;l++){
            a[l].den=max(a[l].den,i-k-1);
        }
        if(i>=n)break;
    }
    sort(a.begin(),a.end(),[](j a,j b){return a.z<b.z;});
    i=0;
    while(1){
        int z=a[i].z;
        int k=i;
        for(;i<n;i++){
            if(z!=a[i].z)break;
        }
        for(int l=k;l<i;l++){
            a[l].den=max(a[l].den,i-k-1);
        }
        if(i>=n)break;
    }
    sort(a.begin(),a.end(),[](j a,j b){return a.den<b.den;});
    i=0;
    for(int k=0;k<n;k++){
        if(i<n)
        while(a[i].den<k){
            i++;
            if(i==n){
                break;
            }
        }
        cout<<i<<" ";
    }
    cout<<"\n";
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