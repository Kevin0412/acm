#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    int xc,yc,r;
    cin>>xc>>yc>>r;
    __int128 r2=r;
    r2*=r2;
    vector<pair<int,int>> points(n*2);
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
        points[i+n].first=points[i].first;
        points[i+n].second=points[i].second;
    }
    int p1=0,p2=1,size=0,ans=0;
    while(p1<n){
        //int flag=0;// 0 no pine  1 pine
        //p2++;
        __int128 size2_c_p1_p2=0;
        __int128 size2_r_p1_p2=0;
        int cross_p1p2_p1c=0;
        while(size2_c_p1_p2>=size2_r_p1_p2 && cross_p1p2_p1c>=0){
            ans=max(ans,size);
            p2++;
            if(p2>=n+p1){
                break;
            }
            size2_c_p1_p2=abs((points[p1].first-xc)*(points[p2].second-yc)
                            -(points[p2].first-xc)*(points[p1].second-yc));
            size2_c_p1_p2*=size2_c_p1_p2;
            size2_r_p1_p2=(points[p1].first-points[p2].first)*(points[p1].first-points[p2].first)
                        +(points[p1].second-points[p2].second)*(points[p1].second-points[p2].second);
            size2_r_p1_p2*=r2;
            size+=abs((points[p1].first-points[p2-1].first)*(points[p2].second-points[p2-1].second)
                    -(points[p2].first-points[p2-1].first)*(points[p1].second-points[p2-1].second));
            cross_p1p2_p1c=(points[p2].first-points[p1].first)*(yc-points[p1].second)
                            -(points[p2].second-points[p1].second)*(xc-points[p1].first);
        }
        if(p2>=n+p1){
            break;
        }
        while(!(size2_c_p1_p2>=size2_r_p1_p2 && cross_p1p2_p1c>=0)){
            p1++;
            if(p1>=n){
                break;
            }
            size2_c_p1_p2=abs((points[p1].first-xc)*(points[p2].second-yc)
                            -(points[p2].first-xc)*(points[p1].second-yc));
            size2_c_p1_p2*=size2_c_p1_p2;
            size2_r_p1_p2=(points[p1].first-points[p2].first)*(points[p1].first-points[p2].first)
                        +(points[p1].second-points[p2].second)*(points[p1].second-points[p2].second);
            size2_r_p1_p2*=r2;
            size-=abs((points[p1].first-points[p1-1].first)*(points[p2].second-points[p1-1].second)
                    -(points[p2].first-points[p1-1].first)*(points[p1].second-points[p1-1].second));
            if(size==0){
                break;
            }
            cross_p1p2_p1c=(points[p2].first-points[p1].first)*(yc-points[p1].second)
                            -(points[p2].second-points[p1].second)*(xc-points[p1].first);
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}