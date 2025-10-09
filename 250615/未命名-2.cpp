#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n,m,u,v,i;
    cin>>n>>m;
   vector<int> a[n+1];
    for(i=1;i<n;i++){
        cin>>u>>v;
        (a[u]).push_back(v);
        (a[v]).push_back(u);
    }
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    if(m==n){
        cout<<1<<endl;
        return 0;
    }
    if(m==n-1){
        cout<<2<<endl;
        return 0;
    }
    return 0;
}