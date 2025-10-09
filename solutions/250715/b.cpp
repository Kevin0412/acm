#include<bits/stdc++.h>

using namespace std;

struct lrc{
	int l,r;
	long long c;
};

long long b[400009];

void solve(){
	int n,m,i,l,r;
	long long c;
	vector<int> s;
	vector<lrc> a;
	cin>>n>>m;
	for(i=0;i<m;i++){
	    cin>>l>>r>>c;
	    a.push_back({l,r,c});
	    s.push_back(l);
	    s.push_back(r);
	}
	sort(s.begin(),s.end());
	if(s[0]!=1 | s[s.size()-1]!=n){
		cout<<0<<endl;
		return;
	}
	map<int,int> mp;
	int j=0;
	for(i=0;i<s.size();i++){
		mp[s[i]]=j;
		//cerr<<s[i]<<" "<<j<<endl;
		if(i<s.size()-1){
			if(s[i]!=s[i+1]){
				j++;
			}
		}
	}
	for(i=0;i<j+2;i++){
		b[i]=0;
	}
	for(auto k:a){
		b[mp[k.l]]+=k.c;
		b[mp[k.r]]-=k.c;
	}
	//cerr<<b[0]<<" ";
	for(i=1;i<=j;i++){
		//cerr<<b[i]<<" ";
		b[i]+=b[i-1];
	}
	//cerr<<endl;
	long long ans=b[0];
	//cerr<<b[0]<<" ";
	for(i=1;i<j;i++){
		//cerr<<b[i]<<" ";
		ans=min(ans,b[i]);
	}
	//cerr<<endl;
	cout<<ans<<endl;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}