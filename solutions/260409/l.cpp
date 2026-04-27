#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long> a;
    long long a1;
    for(int i=0;i<n;i++){
        cin>>a1;
        a.push_back(a1);
    }
    sort(a.begin(),a.end());
    map<long long,int> b,c;
    for(int i=0;i<n;i++){
        b[a[i]]=i;
    }
    for(int i=n-1;i>=0;i--){
        c[a[i]]=i;    
    }
    int ans=1;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            long long mid=a[i]+a[j];
            if(mid%2==1)continue;
            mid/=2;
            if(!b.count(mid))continue;
            if((i+j)/2>=c[mid] && (i+j)/2<=b[mid]){
                ans=max(ans,j-i+1);
            }else if((i+j)/2<c[mid]){
                ans=max(ans,(j-c[mid])*2+1);
            }else{
                ans=max(ans,(b[mid]-i)*2+2);
            }
        }
    }
    cout<<ans<<"\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}