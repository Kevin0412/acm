#include<bits/stdc++.h>
using namespace std;
string str;
int n,a[6];
int ans=5e5+10;
int main()
{
    cin>>n>>str;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a'||str[i]=='A') a[0]++;
        if(str[i]=='h'||str[i]=='H') a[1]++;
        if(str[i]=='S'||str[i]=='s') a[2]++;
        if(str[i]=='i'||str[i]=='I') a[3]++;
        if(str[i]=='n'||str[i]=='N') a[4]++;
        if(str[i]=='g'||str[i]=='G') a[5]++;
    }
    for(int i=0;i<2;i++)
    {
        ans=min(ans,a[i]/2);
    }
    for(int i=2;i<6;i++)
    {
        ans=min(ans,a[i]);
    }
    cout<<ans<<'\n';
    return 0;
}