#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    map<string,string> ans;
    ans["01"]="0 0 0 0 0 0 0 0 0 0 0 0";
    ans["02"]="0 0 0 0 0 0 0 0 0 0 0 1";
    ans["03"]="0 0 0 0 0 0 0 0 0 0 2 1";
    ans["04"]="0 0 0 0 0 0 0 0 0 3 2 1";
    ans["05"]="0 0 0 0 0 0 0 0 4 3 2 1";
    ans["06"]="0 0 0 0 0 0 0 5 4 3 2 1";
    ans["07"]="0 0 0 0 0 6 0 5 4 3 2 1";
    ans["08"]="0 0 0 0 7 6 0 5 4 3 2 1";
    ans["11"]="0 0 0 8 7 6 0 5 4 3 2 1";
    ans["22"]="0 0 1 8 7 6 0 5 4 3 2 1";
    ans["33"]="0 2 1 8 7 6 0 5 4 3 2 1";
    while(t--){
        string s;
        cin>>s;
        if(ans.count(s)){
            cout<<"Yes\n";
            cout<<ans[s]<<"\n";
        }else{
            cout<<"No\n";
        }
    }
}