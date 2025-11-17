#include<bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(0));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    set<pair<int,int>> visited;
    deque<int> bfs;
    for(int i=1;i<=n;i++){
        if(a[i].size()%2==0){
            bfs.push_back(i);
            break;
        }
    }
    deque<int> bfs1;
    if(bfs.empty()){
        cout<<"-1\n";
        return;
    }
    vector<pair<int,int>> ans;
    int flag=-1;
    while(!bfs.empty()){
        int k=bfs.back();
        bfs.pop_back();
        vector<int> ans1;
        for(auto i:a[k]){
            if(visited.count({i,k})==0){
                visited.insert({i,k});
                visited.insert({k,i});
                if(a[i].size()%2==1){
                    ans1.push_back(i);
                    bfs1.push_back(i);
                }else{
                    bfs.push_back(i);
                }
            }
        }
        for(int i=0;i<ans1.size()/2;i++){
            ans.push_back({ans1[2*i],ans1[2*i+1]});
            visited.insert({ans1[2*i],ans1[2*i+1]});
            visited.insert({ans1[2*i+1],ans1[2*i]});
        }
        if(ans1.size()%2==1){
            if(flag!=-1){
                ans.push_back({flag,ans1.back()});
                visited.insert({flag,ans1.back()});
                visited.insert({ans1.back(),flag});
                flag=-1;
            }else{
                flag=ans1.back();
            }
        }
        if(bfs.empty()){
            if(!bfs1.empty()){
                bfs.push_back(bfs1.front());
                bfs1.pop_front();
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
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