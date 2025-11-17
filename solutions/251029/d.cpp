#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> pattern_next(const string& pattern){
    int m = pattern.size();
    vector<int> next(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        next[i] = j;
    }
    return next;
}

vector<int> kmp(const string& text, const string& pattern, vector<int> next) {
	vector<int> ans;
    int n = text.size(), m = pattern.size();
    //if (m == 0) return 0;
    //if (n < m) return ans;
    int i = 0, j = 0;
    for (; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        if (text[i] == pattern[j])
            j++;
    }
    while(j!=0){
        //cout<<j<<" ";
        ans.push_back(j);
        if(j==1)break;
        j=next[j-1];
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    // vector<int> periods;
    // int period=s.length();
    // while(true){
    //     string pattern=s.substr(0,(period+1)/2);
    //     string text=s.substr(s.length()-(period+1)/2,(period+1)/2);
    //     period=kmp(text,pattern,pattern_next(pattern));
    //     //cout<<text<<" "<<pattern<<" "<<period<<"\n";
    //     if(period==0){
    //         break;
    //     }
    //     periods.push_back(period);
    //     if(period==1){
    //         break;
    //     }
    // }
    vector<int> p2;
    string pattern=s.substr(0,(s.length()+1)/2);
    string text=s.substr(s.length()-(s.length()+1)/2,(s.length()+1)/2);
    p2=kmp(text,pattern,pattern_next(pattern));
    //cout<<"\n";
    // for(int i=periods.size()-2;i>=0;i--){
    //     int k=p2.size();
    //     p2.push_back(periods[i]);
    //     if(2*periods[i-1]>=periods[i]){
    //         for(int j=0;j<k;j++){
    //             if(p2[j]<periods[i-1] & p2[j]+periods[i-1]<periods[i])
    //             p2.push_back(p2[j]+periods[i-1]);
    //         }
    //     }
    // }
    vector<int> a(s.length()+2,0);
    for(auto i:p2){
        a[i]=1;
    }
    vector<int> b(s.length()/2+2,0);
    for(int i=1;i<s.length()/2+2;i++){
        b[i]=b[i-1]+a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int i;
        cin>>i;
        if(i>s.length()-i){
            cout<<b[s.length()-i]<<"\n";
        }else{
            cout<<b[i-1]<<"\n";
        }
    }
    return 0;
}