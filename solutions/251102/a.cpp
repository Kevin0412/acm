#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;

    for(int i=0;i<2*n;i++){
        cout<<(i/2)%n+1<<" "<<(i/2+i%2)%n+1<<"\n";
    }
    
    for(int i=2*n;i<k;i++){
        cout<<i%n+1<<" "<<(i+i/n)%n+1<<"\n";
    }
    return 0;
}