#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    vector<pair<int,int>> way;
    if(n%2==0){
        int x=1,y=1;
        for(x=1;x<=n;x++){
            way.push_back({x,y});
        }
        x=n;
        for(x=n;x>0;x--){
            if(x%2==0){
                for(y=2;y<=m;y++){
                    way.push_back({x,y});
                }
            }else{
                for(y=m;y>1;y--){
                    way.push_back({x,y});
                }
            }
        }
    }else if(m%2==0){
        int x=1,y=1;
        for(y=1;y<=m;y++){
            way.push_back({x,y});
        }
        y=m;
        for(y=m;y>0;y--){
            if(y%2==0){
                for(x=2;x<=n;x++){
                    way.push_back({x,y});
                }
            }else{
                for(x=n;x>1;x--){
                    way.push_back({x,y});
                }
            }
        }
    }else{
        int x=1,y=1;
        for(x=1;x<=n;x++){
            way.push_back({x,y});
        }
        x=n;
        for(x=n;x>2;x--){
            if(x%2==1){
                for(y=2;y<=m;y++){
                    way.push_back({x,y});
                }
            }else{
                for(y=m;y>1;y--){
                    way.push_back({x,y});
                }
            }
        }
        for(y=m;y>1;y--){
            if(y%2==1){
                way.push_back({2,y});
                way.push_back({1,y});
            }else{
                way.push_back({1,y});
                way.push_back({2,y});
            }
        }
        for(x=2;x<=n;x++){
            way.push_back({x,1});
        }
        x=n;
        for(x=n;x>2;x--){
            if(x%2==1){
                for(y=2;y<=m;y++){
                    way.push_back({x,y});
                }
            }else{
                for(y=m;y>1;y--){
                    way.push_back({x,y});
                }
            }
        }
        for(y=m;y>2;y--){
            if(y%2==1){
                way.push_back({2,y});
                way.push_back({1,y});
            }else{
                way.push_back({1,y});
                way.push_back({2,y});
            }
        }
        way.push_back({1,2});
    }
    // for(auto i:way){
    //     cout<<i.first<<" "<<i.second<<"\n";
    // }
    int l=1;
    while(1){
        if(l==n*m){
            break;
        }
        int r1,c1;
        cin>>r1>>c1;
        int n1=0,m1=0;
        for(n1=0;n1<way.size();n1++){
            if(r==way[n1].first && c==way[n1].second){
                break;
            }
        }
        for(m1=0;m1<way.size();m1++){
            if(r1==way[m1].first && c1==way[m1].second){
                break;
            }
        }
        if(m%2==1 && n%2==1){
            if(m1<n1){
                if(r1!=1 || c1!=1){
                    m1++;
                    for(;m1<way.size();m1++){
                        if(r1==way[m1].first && c1==way[m1].second){
                            break;
                        }
                    }
                }else{
                    m1+=way.size();
                    if(r!=2 || c!=2){
                        n1++;
                        for(;n1<way.size();n1++){
                            if(r==way[n1].first && c==way[n1].second){
                                break;
                            }
                        }
                    }
                }
            }
        }else{
            if(m1<n1){
                m1+=way.size();
            }
        }
        int size=way.size();
        string s;
        for(int i=n1;i<m1;i++){
            auto a=way[i%size];
            auto b=way[(i+1)%size];
            if(a.first-b.first==1){
                s+="U";
            }else if(a.first-b.first==-1){
                s+="D";
            }else if(a.second-b.second==1){
                s+="L";
            }else{
                s+="R";
            }
            if(b.first==r1 && b.second==c1){
                break;
            }
        }
        cout<<s<<"\n";
        cout.flush();
        l++;
        r=r1;
        c=c1;
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
