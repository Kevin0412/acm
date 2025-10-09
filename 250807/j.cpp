#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0), cout.tie(0);
    string s;
    cin>>s;
    int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int a[26],i,j;
    for(i=0;i<26;i++){
    	a[i]=0;
    }
    for(i=0;i<s.length();i++){
    	a[s[i]-'A']++;
    }
    int ans=0;
    for(i=0;i<26;i++){
    	int temp=0;
    	for(j=0;j<26;j++){
    		temp+=a[j]*holes_cnt[(i+j)%26];
    	}
    	//cerr<<temp<<endl;
    	ans=max(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}