#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> pattern_next(const string& pattern){
    int m=pattern.size();
    vector<int> next(m,0);
    for(int i=1,j=0;i<m;i++){
        while(j>0&&pattern[i] != pattern[j]){
            j=next[j-1];
        }
        if(pattern[i]==pattern[j]){
            j++;
        }
        next[i]=j;
    }
    return next;
}

vector<int> kmp(const string& text, const string& pattern, vector<int> next){
    vector<int> ans;
    int n=text.size(), m=pattern.size();
    if(n<m) return ans;

    for(int i=0, j=0;i<n;i++){
        while(j>0 && text[i]!= pattern[j]){
            j=next[j-1];
        }
        if (text[i]==pattern[j]){
            j++;
        }
        if (j==m){
            ans.push_back(i-m+1);
        }
    }
    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;
    if(k>=6)k=6;
    string s;
    cin>>s;
    for(int i=0;i<k;i++){
        s+=s[i];
    }
    vector<int>ans=kmp(s,"nanjing",pattern_next("nanjing"));
    cout<<ans.size()<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}
