#include<bits/stdc++.h>

using namespace std;

int n,m;

const int N=2e5+10;

pair<int,int> a[N];
int c[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=1;i<=n;i++){
        c[i]=0;
    }
    for(int i=1;i<=m;i++){
        if(a[i].second-a[i].first==1){
            c[a[i].first]=1;
        }
    }
    int d=0;
    for(int i=1;i<=n;i++){
        d+=c[i];
    }
    if(d==n-1){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}