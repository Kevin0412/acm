#include<bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int N=1e6+10;
int cnt=0;
int n,m,v,t;

int dis[N],h[N],to[N],val[N],nxt[N];
struct Bag_num{
    int bag,left;
}bag_num[N];
bool vis[N];

void add (int a,int b,int c){
    to[++cnt]=b;
    val[cnt]=c;
    nxt[cnt]=h[a];
    h[a]=cnt;
}

struct node{
    int v;
    Bag_num w;
    friend bool operator < (node a,node b){
        if(a.w.bag == b.w.bag){
            return a.w.left<b.w.left;
        }
        return a.w.bag>b.w.bag;
    }
}tmp;

priority_queue<node> q;
void dj(){
    for(int i=1;i<=n;++i){
        bag_num[i].bag=INT_MAX;
        bag_num[i].left=-1;
    }
    dis[t]=0;
    tmp.v=t,tmp.w={1,v};
    bag_num[t]={1,v};
    q.push(tmp);
    while(!q.empty()){
        int u=q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=h[u];i;i=nxt[i]){
            Bag_num tmp_bag;
            if(bag_num[u].left+val[i]>v){
                tmp_bag={bag_num[u].bag+1,v};
                cout<<"here"<<endl;
            }else{
                tmp_bag={bag_num[u].bag,bag_num[u].left+val[i]};
                cout<<"there"<<endl;
            }

            if(bag_num[to[i]].bag>tmp_bag.bag || ((bag_num[to[i]].bag==tmp_bag.bag) && bag_num[to[i]].left<tmp_bag.left)){
                bag_num[to[i]].bag=bag_num[u].bag;
                bag_num[to[i]].left=bag_num[u].left;
                tmp.w=bag_num[to[i]];
                tmp.v=to[i];
                q.push(tmp);
                cout<<"u:"<<u<<" to:"<<to[i]<<" "<<" tmp_bag.bag:"<<tmp_bag.bag<<" tmp_bag.left"<<tmp_bag.left<<endl;
            }
        }
    }
}

int main(){
    cin>>n>>m>>v>>t;
    for(int i=1,u,v,w;i<=m;++i){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dj();
    for(int i=1;i<=n;++i){
        if(bag_num[i].bag==INT_MAX)
            cout<<-1<<" ";
        else
            cout<<bag_num[i].bag<<" ";
    }


    return 0;
}