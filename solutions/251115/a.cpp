#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n,k;
    cin>>n>>k;
    int i=0;
    for(;i<2*n;i++){
        if(i%2==0){
            cout<<i/2+1<<" "<<i/2+1<<"\n";
        }else{
            cout<<(i/2+1)%n+1<<" "<<i/2+1<<"\n";
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            if(i>=k)return 0;
            if(x!=y & x-y!=1 & !(x==1 & y==n)){
                i++;
                cout<<x<<" "<<y<<"\n";
            }
        }
    }
}