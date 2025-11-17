#include<bits/stdc++.h>
#define int long long
using namespace std;

double logn[1000006];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    logn[1]=0.0;
    for(int i=2;i<1000006;i++){
        logn[i]=logn[i-1]+log10((double)i);
    }
    string s;
    cin>>s;
    // if(s.length()==1){
    //     if(s[0]=='1'){
    //         cout<<"1 1\n";
    //         return 0;
    //     }
    //     if(s[0]=='2'){
    //         cout<<"2 1\n";
    //         return 0;
    //     }
    //     if(s[0]=='3'){
    //         cout<<"3 2\n";
    //         return 0;
    //     }
    // }
    double log_s=(double)(s.length());
    double a=0;
    for(int i=min((int)20,(int)((int)(s.length())-1));i>=0;i--){
        a+=double(s[i]-'0');
        a/=10.0;
    }
    log_s+=log10(a);
    int l=0,r=1000005;
    while(r-l>1){
        if(log_s>logn[(r+l)/2]*1.0000000000001){
            l=(r+l)/2;
        }else{
            r=(r+l)/2;
        }
    }
    int ans1=(int)(pow(10.0,logn[r]-log_s)+0.5);
    cout<<r<<" "<<ans1<<"\n";
    return 0;
}