#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int l=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            l++;
        }else{
            if(l!=0)l--;
        }
    }
    if(l>0){
        cout<<"impossible\n";
    }else{
        cout<<s<<"\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}