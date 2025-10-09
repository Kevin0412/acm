#include<bits/stdc++.h>
using namespace std;
long long a[10];
int t;
int main()
{
    cin>>t;;
    while(t--)
    {
        long long ans=0;
        for(int i=0;i<9;i++)
        {
            cin>>a[i];
        }
        long long temp;
        cin>>temp;
        a[6]+=temp;
        ans+=a[0]+a[4]+a[8];
        long long pl=min(a[1]+a[3]+a[5]+a[7],a[2]+a[6]);
        ans+=pl;
        if(pl<a[2])
        {
            a[2]-=pl;
            ans+=min(a[2],a[6]);
            if(a[2]<a[6])
            {
                ans+=(a[6]-a[2])/2;
            }
        }
        else
        {
            a[6]-=pl-a[2];
            ans+=a[6]/2;
        }
        cout<<ans<<'\n';
    }
}