#include<bits/stdc++.h>

using namespace std;

struct song{
	int s;
	int p;
	int idx;
	bool operator<(const song& other) const {
		if(s!=other.s)
        	return s < other.s; 
        else
            return p < other.p; 
    }
};

int ans[200005];


void solve(){
	int n;
	cin>>n;
	string s;
	vector<int> p;
	vector<song> a;
	int pi,i;
	for(i=0;i<n;i++){
		cin>>pi;
		p.push_back(pi);
	}
	cin>>s;
	for(i=0;i<n;i++){
		a.push_back({s[i]-'0',p[i],i});
	}
	sort(a.begin(), a.end());
	for(i=0;i<n;i++){
		ans[a[i].idx]=i+1;
	}
	for(i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}