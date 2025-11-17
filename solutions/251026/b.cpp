#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t[7];
    for(int i=1;i<=6;i++){
        cin>>t[i];
    }
    vector<int> cnt={0,0,0,0};
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i][1]=='D'){
            cnt[0]++;
        }else if(a[i][1]=='C'){
            cnt[1]++;
        }else if(a[i][1]=='H'){
            cnt[2]++;
        }else if(a[i][1]=='S'){
            cnt[3]++;
        }
    }
    for(int i=0;i<4;i++){
        ans+=cnt[i]/5;
        cnt[i]%=5;
    }
    int sum=0;
    for(int i=0;i<4;i++){
        sum+=cnt[i];
    }
    for(int i=0;i<4;i++){
        if(t[i+1]==1){
            cnt[i]+=3;
        }
    }
    int ans1=0;
    for(int i=0;i<4;i++){
        ans1+=cnt[i]/5;
        cnt[i]%=5;
    }
    int cnt1=t[5]+t[6];
    sort(cnt.begin(),cnt.end(),greater<int>());
    for(int i=0;i<4;i++){
        ans1+=(cnt[i]+cnt1)/5;
        if((cnt[i]+cnt1)/5)cnt1=(cnt[i]+cnt1)%5;
    }
    if(ans1*5<=sum){
        cout<<ans+ans1<<"\n";
    }else{
        cout<<ans+sum/5<<"\n";
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