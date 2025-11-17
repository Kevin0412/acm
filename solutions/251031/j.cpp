#include<bits/stdc++.h>
#define int long long
using namespace std;

struct gs{
    int x;
    int t;
    bool operator<(const gs& other) const {
        return x > other.x;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),c(n+1);
    vector<gs> b(m+1);
    vector<queue<int>> g(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i].x>>b[i].t;
        g[b[i].t].push(b[i].x);
    }
    priority_queue<gs> pq;
    for(int i=1;i<=n;i++){
        if(!g[i].empty()){
            pq.push({g[i].front(),i});
        }else{
            pq.push({(int)1e18,i});
        }
    }
    int ans=0,i=1;
    while(!pq.empty()){
        gs e=pq.top();
        if(c[e.t]>=e.x-ans){
            c[e.t]-=e.x-ans;
            ans=e.x;
        }else{
            ans+=c[e.t];
            c[e.t]=0;
        }
        pq.pop();
        if(c[e.t]!=0){
            if(!g[e.t].empty())g[e.t].pop();
            if(!g[e.t].empty()){
                pq.push({g[e.t].front(),e.t});
            }else{
                pq.push({(int)1e18,e.t});
            }
        }
        if(i<b.size())
        while(ans>=b[i].x){
            c[b[i].t]=a[b[i].t];
            // if(b[i].t==e.t){
            //     c[b[i].t]-=ans-b[i].x;
            // }
            if(g[b[i].t].empty())pq.push({(int)1e18,b[i].t});
            else{
                pq.push({g[b[i].t].front(),b[i].t});
            }
            i++;
            if(i>=b.size())break;
        }
    }
    cout<<ans<<"\n";
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