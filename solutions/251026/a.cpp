#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[202][202];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    string temp="";
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(j==0 & i==0){
                for(int l=0;l<k;l++){
                    temp+=s[j*k+l];
                }
                a[i][j]=1;
            }else{
                a[i][j]=1;
                for(int l=0;l<k;l++){
                    if(temp[l]!=s[j*k+l]){
                        a[i][j]=0;
                        break;
                    }
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum+=a[i][j];
        }
    }
    if(sum==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    cout<<i+1<<" "<<j+1<<"\n";
                    return 0;
                }
            }
        }
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    cout<<i+1<<" "<<j+1<<"\n";
                    return 0;
                }
            }
        }
    }
}