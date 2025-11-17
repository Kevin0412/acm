#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    set<vector<int>> b;
    vector<vector<int>> c;
    b.insert(a[0]);
    c.push_back(a[0]);
    for(int i=1;i<m;i++){
        int k=c.size();
        for(int j=0;j<k;j++){
            vector<int> d(n,0);
            for(int l=0;l<n;l++){
                d[l]=c[j][a[i][l]-1];
            }
            if(b.count(d)==0){
                b.insert(d);
                c.push_back(d);
            }
        }
        if(b.count(a[i])==0){
            b.insert(a[i]);
            c.push_back(a[i]);
        }
    }
    cout<<c.size()<<"\n";
    return 0;
}