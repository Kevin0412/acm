#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=n-k;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}