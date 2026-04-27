#include<bits/stdc++.h>

using namespace std;

struct a
{
    long long star;
    vector<long long> points;
    long long idx;
};


void solve(){
    long long n,m,k;
    cin>>n>>m>>k;
    vector<a> b(n);
    for(long long i=0;i<n;i++){
        cin>>b[i].star;
        for(long long j=0;j<m;j++){
            long long c;
            cin>>c;
            b[i].points.push_back(c);
        }
        b[i].idx=i;
    }
    sort(b.begin(),b.end(),[](a x,a y){
        return x.star<y.star;
    });
    map<long long,long long> maxb;
    long long sum=0;
    vector<long long> d,e;
    for(long long i=0;i<n;i++){
        sum=0;
        d.clear();
        for(long long j=0;j<m;j++){
            if(b[i].points[j]==-1){
                d.push_back(j);
            }else{
                sum+=b[i].points[j];
            }
        }
        if(e.empty()){
            for(auto l:d){
                b[i].points[l]=0;
            }
            maxb[b[i].star]=sum;
            e.push_back(b[i].star);
        }else if(e.size()==1 && e[0]==b[i].star){
            for(auto l:d){
                b[i].points[l]=0;
            }
            maxb[b[i].star]=max(sum,maxb[b[i].star]);
        }else if(e[e.size()-1]==b[i].star){
            long long maxsum=sum+k*d.size();
            if(maxsum<=maxb[e[e.size()-2]]){
                cout<<"No\n";
                return;
            }
            long long minsum=max(sum,maxb[e[e.size()-2]]+1);
            for(auto l:d){
                if(minsum-sum>k){
                    b[i].points[l]=k;
                    sum+=k;
                }else{
                    b[i].points[l]=minsum-sum;
                    sum+=minsum-sum;
                }
            }
            maxb[b[i].star]=max(sum,maxb[b[i].star]);
        }else{
            long long maxsum=sum+k*d.size();
            if(maxsum<=maxb[e[e.size()-1]]){
                cout<<"No\n";
                return;
            }
            long long minsum=max(sum,maxb[e[e.size()-1]]+1);
            for(auto l:d){
                if(minsum-sum>k){
                    b[i].points[l]=k;
                    sum+=k;
                }else{
                    b[i].points[l]=minsum-sum;
                    sum+=minsum-sum;
                }
            }
            maxb[b[i].star]=sum;
            e.push_back(b[i].star);
        }
    }
    cout<<"Yes\n";
    sort(b.begin(),b.end(),[](a x,a y){
        return x.idx<y.idx;
    });
    for(auto i:b){
        for(auto j:i.points){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}