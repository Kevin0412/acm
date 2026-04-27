#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    struct a{
        int idx;
        int n;
        int rank;
        string s;
    };
    vector<a> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i].s>>b[i].n;
        b[i].idx=i+1;
    }
    sort(b.begin(),b.end(),[](a x,a y){
        return x.n>y.n;
    });
    b[0].rank=1;
    for(int i=1;i<n;i++){
        b[i].rank=i+1;
        if(b[i-1].n==b[i].n){
            b[i].rank=b[i-1].rank;
        }
    }
    sort(b.begin(),b.end(),[](a x,a y){
        return x.idx<y.idx;
    });
    string ans="";
    for(auto i:b){
        for(int j=0;j<(int)(i.s.size())-i.rank;j++){
            ans+=i.s[j];
        }
    }
    ans[0]=ans[0]-('a'-'A');
    cout<<"Stage: "<<ans<<"\n";
}