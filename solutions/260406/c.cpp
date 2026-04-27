#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m,u,v;
    cin>>m;
    vector<vector<int>> tree(m);
    vector<int> degree(m,0);

    for(int i=1;i<m;i++){
        cin>>u>>v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    vector<vector<int>> ans;
    vector<int> visited(m,0);
    vector<int> remain(m,2);
    //pair<node,0:delete 1:remain>
    queue<pair<int,int>> bfs;

    while(true){
        for(int i=0;i<m;i++){
            degree[i]=tree[i].size();
        }
        for(int i=0;i<m;i++){
            visited[i]=0;
        }
        for(int i=0;i<m;i++){
            if(degree[i]==1){
                if(visited[tree[i][0]]==0){
                    bfs.push({i,0});
                    visited[i]=1;
                    remain[i]=0;
                }
            }
        }

        pair<int,int> curr_node;
        while(!bfs.empty()){
            curr_node=bfs.front();
            for(auto k:tree[curr_node.first]){
                if(!visited[k]){
                    if(degree[k]<=2 && curr_node.second==1){
                        remain[k]=0;
                        for(auto j:tree[k]){
                            if(remain[j]==0) remain[k]=1;
                        }
                        bfs.push({k,remain[k]});
                    }else{
                        bfs.push({k,1});
                        remain[k]=1;
                    }
                }
                visited[k]=1;
            }
            bfs.pop();
        }

        vector<int> ans1;
        for(int i=0;i<m;i++){
            if(remain[i]==0){
                ans1.push_back(i+1);
                remain[i]=-1;
                for(auto j:tree[i]){
                    for(auto k:tree[i]){
                        if(j!=k){
                            tree[j].push_back(k);
                        }
                    }
                }
                tree[i].clear();
            }
        }
        for(int i=0;i<m;i++){
            vector<int> neighbor;
            for(auto j:tree[i]){
                if(remain[j]!=-1){
                    neighbor.push_back(j);
                }
            }
            tree[i]=neighbor;
        }
        if(ans1.empty())break;
        ans.push_back(ans1);
    }

    
    cout<<ans.size()+1<<"\n";
    for(auto an:ans){
        cout<<an.size();
        for(auto a:an){
            cout<<" "<<a;
        }
        cout<<"\n";
    }
    for(int i=0;i<m;i++){
        if(remain[i]!=-1){
            cout<<"1 "<<i+1;
        }
    }
    return 0;
}