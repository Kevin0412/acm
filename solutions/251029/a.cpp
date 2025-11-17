#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u]++;a[v]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=4)
        {
            ans=0;
            break;
        }
        else if(a[i]==3) continue;
        else
        {
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}