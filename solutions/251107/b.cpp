#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    int sum=0;
    for(int i=0;i<m;i++){
        if(a[i]>b[i]){
            cout<<"-1\n";
            return;
        }else{
            sum+=b[i]-a[i];
        }
    }
    if(sum>n-m){
        cout<<"-1\n";
        return;
    }
    multiset<int> a1;
    for(int i=n-1;i>=m-1;i--){
        a1.insert(a[i]);
    }
    multiset<int> a2;
    for(int i=m-2;i>=0;i--){
        a2.insert(a[i]);
    }
    vector<int> ans;
    for(int i=0;i<n-m-sum;i++){
        int begin=*a1.begin();
        int end=*a1.rbegin();
        a1.erase(a1.begin());
        ans.push_back(begin);
        a1.insert(begin+1);
        a1.erase(a1.begin());
        if(end!=*a1.rbegin()){
            sum--;
            if(sum<0){
                cout<<"-1\n";
                return;
            }
            if(!a2.empty()){
                if(*a2.begin()<*a1.rbegin()){
                    a1.insert(*a2.begin());
                    a2.insert(*a1.rbegin());
                    auto it=a1.end();
                    it--;
                    a1.erase(it);
                    a2.erase(a2.begin());
                }
            }
        }
    }
    a2.insert(*a1.rbegin());
    vector<int> a3(a2.begin(),a2.end());
    sort(b.begin(),b.end());
    for(int i=0;i<m;i++){
        if(a3[i]>b[i]){
            cout<<"-1\n";
            return;
        }
        for(int j=a3[i];j<b[i];j++){
            ans.push_back(j);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
    return;
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
}