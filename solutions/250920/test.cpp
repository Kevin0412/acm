#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int cnt[N];
bool vis[N];
int k,n,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long ans=0;
        memset(cnt,0,sizeof(cnt));
        memset(vis,false,sizeof(vis));
        unordered_map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]%=k;
            cnt[m[a[i]]]++;
        }
        int beg=a[1];
        sort(a+1,a+n+1);
        a[n+1]=k;
        if(a[1]>0) a[0]=0;
        int l=lower_bound(a+1,a+n+2,beg)-a;
        int r=lower_bound(a+1,a+n+2,k-beg)-a;
        beg=l;int ed=r;
        vis[a[l]]=true;vis[a[r]]=true;
        int prel,prer;
        if(l>r) swap(l,r);
        while(r<=n)
        {
            ans+=((a[l]+a[r])%k)*(cnt[m[a[l]]]+cnt[m[a[r]]]-1);
            prel=l,prer=r;
            vis[m[a[r]]]=true;vis[m[a[l]]]=true;
            r=lower_bound(a+r,a+n+2,a[r]+1)-a;
            l=lower_bound(a+1,a+l+1,k-a[r])-a;
            if(r>n) break;
            ans+=(a[prel]+a[r])%k;
        }
        l=1;
        while(l<beg)
        {
            if(vis[m[a[l]]])
            {
                l=lower_bound(a+l+1,a+beg+1,a[l]+1)-a;
                continue;
            }
            r=lower_bound(a+ed+1,a+n+2,k-a[l])-a;
            if(vis[m[a[1]]])
            {
                ans+=min(((a[l]+a[r])%k),(a[l]+a[1])%k)*(cnt[m[a[l]]]);
            }
            else
            {
                if(r>n) ans+=((a[l]+a[beg])%k);
                else ans+=(((a[l]+a[r])%k),(a[l]+a[beg])%k)*(cnt[m[a[l]]]);
            }
            vis[m[a[l]]]=true;
            l=lower_bound(a+l+1,a+beg+1,a[l]+1)-a;
        }
        l=lower_bound(a+l+1,a+ed+1,a[l]+1)-a;
        while(l<ed)
        {
            if(vis[m[a[l]]])
            {
                l=lower_bound(a+l+1,a+ed+1,a[l]+1)-a;
            }
            r=(lower_bound(a+beg+1,a+ed+1,k-a[l]))-a;
            if((a[l]+a[1])%k<(a[l]+a[r])%k)
            {
                vis[m[a[l]]]=true;
                ans+=((a[l]+a[1])%k)*cnt[m[a[l]]];
            }
            else{
                vis[m[a[l]]]=true;
                if(vis[m[a[r]]])
                {
                    ans+=((a[l]+a[r])%k)*cnt[m[a[l]]];
                }
                else
                {
                    ans+=min((a[l]+a[ed])%k,(a[r]+a[ed]%k));
                    ans+=((a[l]+a[r])%k)*(cnt[m[a[l]]]+cnt[m[a[r]]]-1);
                    vis[m[a[r]]]=true;
                }
            }
            l=lower_bound(a+l+1,a+ed+1,a[l]+1)-a;
        }
        cout<<ans<<'\n';
    }
}