#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=-100;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    int n1=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            n1++;
        }
    }
    if(sum==0){
        cout<<"Yes\n";
        for(auto i:a){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }else if(sum>0){
        if(sum*2>n1){
            cout<<"No\n";
            return;
        }else{
            cout<<"Yes\n";
            for(auto i:a){
                if(i==0)cout<<"0 ";
                else cout<<i*n1-sum<<" ";
            }
            cout<<"\n";
            return;
        }
    }else{
        if(sum*2<=-n){
            cout<<"No\n";
            return;
        }else{
            cout<<"Yes\n";
            for(auto i:a){
                cout<<i*n-sum<<" ";
            }
            cout<<"\n";
            return;
        }
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
